// main.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-14
//
// For CS 372 Spring 2021
// Main for Battleship Project

#include "game.h"

#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <cstddef>
using std::size_t;


int main()
{
    Game classicBattleship;

    vector<pair<string, size_t>> classicShips = {
        { "Carrier",     5 },
        { "Battleship",  4 },
        { "Destroyer",   3 },
        { "Submarine",   3 },
        { "Patrol Boat", 2 }
    };

    vector<string> classicShipNames = {
        { "Carrier" },
        { "Battleship" },
        { "Destroyer" },
        { "Submarine" },
        { "Patrol Boat" }
    };

    cout << string(200, '\n');
    for (const auto &ship : classicShips)
    {
        classicBattleship.printShips();
        classicBattleship.inputShip(ship.first, ship.second);
        cout << string(200, '\n');
    }
    classicBattleship.switchPlayer();
    cout << string(200, '\n');
    for (const auto &ship : classicShips)
    {
        classicBattleship.printShips();
        classicBattleship.inputShip(ship.first, ship.second);
        cout << string(200, '\n');
    }
    classicBattleship.switchPlayer();
    cout << string(200, '\n');
    while (true)
    {
        classicBattleship.printAllResults();
        classicBattleship.inputHit();
        classicBattleship.printHitResult();
        if (classicBattleship.allShipsSunk(classicShipNames))
        {
            classicBattleship.switchPlayer();
            classicBattleship.printShips();
            classicBattleship.switchPlayer();
            classicBattleship.printShips();
            cout << "game over\n";
            break;
        }
        classicBattleship.switchPlayer();
        cout << "---- Press ENTER to continue. ----\n";
        getchar();
        cout << string(200, '\n');
    }
}
