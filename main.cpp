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
    game.inputShip("1ship", 0);
    game.inputShip("Patrol Boat", 2);
    // game.printShips();
    // game.inputShip("2ship");
    // game.printShips();
    // game.inputShip("3ship");
    // game.printShips();
    // game.inputShip("4ship");
    // game.printShips();
    // game.inputShip("5ship");
    game.printShips();
    game.switchPlayer();
    while (true)
    {
        game.printAllResults();
        game.inputHit();
        game.printHitResult();
    }
}
