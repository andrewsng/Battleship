// main.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-14
//
// For CS 372 Spring 2021
// Main for Battleship Project

#include "game.h"


int main()
{
    Game game;

    game.printShips();
    game.inputShip("ship1");
    game.printShips();
    game.switchPlayer();
    // game.hitTarget();
}
