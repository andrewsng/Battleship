// game.h
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Header for Game class

#ifndef GAME_H
#define GAME_H

#include "board.h"  // For class Board

#include <iostream> // For std::cout
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

    // setPlayer
    // Sets the current player number (1 or 2).
    void setPlayer(std::size_t playerNumber)
    {
        _player = playerNumber - 1;
    }

    // currentPlayer
    // Returns the current player number (1 or 2).
    std::size_t currentPlayer() const
    {
        return _player + 1;
    }
    
    // inputShip
    // Add a ship to the current player's board according to inputs.
    void inputShip(const std::string& ship, std::size_t restrictSize);

    // printShips
    // Prints the current player's board with ships visible.
    void printShips() const;

    // inputHit
    // Add a hit to the opposing player's board according to input.
    void inputHit();

    // printHitResult
    // Prints the result of the most recent attack.
    void printHitResult() const;

    // printAllResults
    // Prints the results of the attacks on the opposing player's board.
    void printAllResults() const;

    // printFinalBoard
    // Prints the attacks and ships on the current player's board.
    void printFinalBoard();

    // allShipsSunk
    // Given a list of ship names, return whether
    // all ships are sunk on the opposing board.
    bool opposingShipsSunk(std::vector<std::string> shipList) const
    {
        for (const auto &name : shipList)
        {
            if (!opposingBoard().isSunk(name))
                return false;
        }
        return true;
    }

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

    // opposingBoard
    // Returns a reference to the board of the opposing player.
    Board& opposingBoard()
    {
        return _boards[1 - _player];
    }
    const Board& opposingBoard() const
    {
        return _boards[1 - _player];
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
    
    // printHitSpace
    // Prints the hit result on the opposing board at the given coordinate.
    void printHitSpace(Coord pos, bool showHidden) const;

    // printBoard
    // Prints the board with information depending on 
    // if it's told to be setup or attack phase.
    void printBoard(bool setupPhase, bool final = false) const;

// ---- Game: Private data members ----
private:

    std::size_t          _player{ 0 };  // Current player (0 or 1)
    Coord                _prevHit{};    // Most recent attack target
    std::array<Board, 2> _boards{};     // Player specific boards

};  // End class Game


#endif  // GAME_H
