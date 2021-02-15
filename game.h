// game.h
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Header for Game class

#ifndef GAME_H
#define GAME_H

#include "board.h"

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
#include <array>
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <cctype>
using std::isalpha;
using std::tolower;


class Game
{

public:

    Game() = default;

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

    // board
    // Returns a reference to the board of the given player.
    // FOR TESTING PURPOSES ONLY (Client using Game should not have
    // direct access to the boards).
    // For use with testsgame.cpp
    Board& board(std::size_t player)
    {
        return _boards[player];
    }
    const Board& board(std::size_t player) const
    {
        return _boards[player];
    }

private:

    // getCoord
    // Gets a single coordinate from the command line
    Coord getCoord();

private:

    std::size_t          _player{ 0 };  // Current player (0 or 1)
    std::array<Board, 2> _boards{};     // Player specific boards

};


#endif  // GAME_H
