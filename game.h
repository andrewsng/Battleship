#ifndef GAME_H
#define GAME_H

#include "board.h"

#include <array>
#include <string>


class Game
{

public:
    
    // inputShip
    // Add a ship to a player's board according to coordinate inputs
    void inputShip(const std::string& ship, std::size_t player);

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

    Coord getCoord();

private:

    std::size_t _player;
    std::array<Board, 2> _boards;

};


#endif  // GAME_H
