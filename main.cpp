// main.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-14
//
// For CS 372 Spring 2021
// Main for Battleship Project

#include "game.h"

#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <cstddef>
using std::size_t;


void clearScreen()
{
    cout << string(200, '\n') << std::endl;
}


void pauseForUser()
{
    while (cin.get() != '\n') ;
}


void setupShips(Game &battleship, vector<pair<string, size_t>> shipList)
{
    for (const auto &ship : shipList)
    {
        battleship.printShips();
        battleship.inputShip(ship.first, ship.second);
        clearScreen();
    }

    battleship.printShips();
    cout << "---- Press ENTER to continue. ----\n";
    pauseForUser();
}


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

    clearScreen();
    setupShips(classicBattleship, classicShips);
    classicBattleship.switchPlayer();

    clearScreen();
    setupShips(classicBattleship, classicShips);
    classicBattleship.switchPlayer();

    clearScreen();
    while (true)
    {
        classicBattleship.printAllResults();
        classicBattleship.inputHit();

        clearScreen();
        classicBattleship.printAllResults();
        classicBattleship.printHitResult();

        if (classicBattleship.opposingShipsSunk(classicShipNames))
        {
            classicBattleship.switchPlayer();
            classicBattleship.printShips();
            classicBattleship.switchPlayer();
            classicBattleship.printShips();
            cout << "Game over!\n";
            break;
        }
        
        cout << "---- Press ENTER to continue. ----\n";
        pauseForUser();
        clearScreen();
        classicBattleship.switchPlayer();
    }
}
