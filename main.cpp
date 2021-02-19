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
using std::endl;
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
    cout << string(200, '\n') << endl;
}


void pauseForUser()
{
    while (cin.get() != '\n') ;
}


void printCurrentPlayer(const Game &battleship)
{
    cout << "----------------- Player ";
    cout << battleship.currentPlayer();
    cout << " -----------------\n";
}


void setupShips(Game &battleship, vector<pair<string, size_t>> shipList)
{
    for (const auto &ship : shipList)
    {
        printCurrentPlayer(battleship);
        cout << "------------------ SETUP -------------------\n\n";
        battleship.printShips();
        battleship.inputShip(ship.first, ship.second);
        clearScreen();
    }

    printCurrentPlayer(battleship);
    cout << "--------------- Final Board ----------------\n\n";
    battleship.printShips();
    cout << "---- Press ENTER to continue. ----\n";
    pauseForUser();
}


int main()
{
    Game classic;

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
    setupShips(classic, classicShips);
    classic.switchPlayer();

    clearScreen();
    setupShips(classic, classicShips);
    classic.switchPlayer();

    clearScreen();
    while (true)
    {
        printCurrentPlayer(classic);
        cout << "----------------- ATTACKING ----------------\n\n";

        classic.printAllResults();
        classic.inputHit();

        clearScreen();
        cout << "   (O) - Miss, [X] - Hit, {S} - Sunk\n\n";
        classic.printAllResults();
        classic.printHitResult();

        if (classic.opposingShipsSunk(classicShipNames))
        {
            cout << "Game over! Player ";
            cout << classic.currentPlayer() << " has won!\n";
            cout << "---- Press ENTER to continue. ----\n";
            pauseForUser();

            clearScreen();
            cout << "=============== FINAL BOARDS ===============\n\n";

            classic.setPlayer(1);
            printCurrentPlayer(classic);
            classic.printFinalBoard();
            
            classic.switchPlayer();
            printCurrentPlayer(classic);
            classic.printFinalBoard();
            cout << "---- Press ENTER to exit. ----\n";
            pauseForUser();
            break;
        }
        
        cout << "---- Press ENTER to continue. ----\n";
        pauseForUser();
        clearScreen();
        classic.switchPlayer();
    }
}
