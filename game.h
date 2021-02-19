// game.h
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Header for Game class

#ifndef GAME_H
#define GAME_H

#include "board.h"  // For class Board

#include <array>    // For std::array


// class Game
// Manages players and input for a game with 2 Boards.
class Game
{

// ---- Game: ctors, dctors, op= ----
public:

    // Default ctor.
    Game() = default;

    // Default dctor.
    ~Game() = default;

    // Copy, move, op= all deleted.
    Game(const Game &other) = delete;
    Game &operator=(const Game &other) = delete;
    Game(Game &&other) = delete;
    Game &operator=(Game &&other) = delete;

// ---- Game: General public functions ----
public:

    // switchPlayer
    // Switches the current player number.
    void switchPlayer()
    {
        _player = 1 - _player;
    }
    
    // inputShip
    // Add a ship to a player's board according to coordinate inputs
    void inputShip(const std::string& ship);

    // printShips
    // Prints the current player's board with ships visible.
    void printShips() const;

    void inputHit();

    // currentBoard
    // Returns a reference to the board of the current player.
    Board& currentBoard()
    {
        return _boards[_player];
    }
    const Board& currentBoard() const
    {
        return _boards[_player];
    }

// ---- Game: General private functions ----
private:

    // getCoord
    // Gets a single coordinate from the command line
    Coord getCoord() const;

    // printGridLine
    // Prints a gridline for the current board (+---+---+).
    void printGridLine() const;

    // printGridNumbers
    // Prints grid numbers for the current board x-axis.
    void printGridNumbers() const;

    // printSpace
    // Prints the space on the current board at the given coordinate.
    void printSpace(Coord pos) const;

// ---- Game: Private data members ----
private:

    std::size_t          _player{ 0 };  // Current player (0 or 1)
    std::array<Board, 2> _boards{};     // Player specific boards

};  // End class Game


#endif  // GAME_H
