// game.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Source for Game class

#include "game.h"
#include "board.h"

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <cstddef>
using std::size_t;


void Game::inputShip(const string& ship)
{
    Coord c0, c1;
    while (true)
    {
        cout << "Enter start and end coordinates for the ship - \"" << ship << "\"\n";
        c0 = getCoord();
        c1 = getCoord();

        auto [worked, msg] = currentBoard().addShip(c0, c1, ship);
        if (!worked)
        {
            cout << "\nCould not place ship, try again: " << msg << '\n';
            continue;
        }

        break;
    }
}


void Game::printGridLine() const
{
    cout << '+';
    for (size_t col = 0; col < currentBoard().size(); ++col)
    {
        cout << "---+";
    }
    cout << '\n';
}


void Game::printGridNumbers() const
{
    cout << ' ';
    for (size_t colNum = 1; colNum < currentBoard().size()+1; ++colNum)
    {
        cout << ' ' << colNum << "  ";
    }
    cout << '\n';
}


void Game::printSpace(Coord pos) const
{
    if (currentBoard().isOccupied(pos))
    {
        const char shipLetter = currentBoard().shipAt(pos)[0];
        cout << '[' << shipLetter << ']';
    }
    else
    {
        cout << " - ";
    }
}


void Game::printShips() const
{
    const size_t size = currentBoard().size();
    const string padding = "   "; // 3 spaces

    cout << padding;
    printGridLine();
    for (size_t row = 0; row < size; ++row)
    {
        char rowLetter = 'A' + row;
        cout << ' ' << rowLetter << " |";
        for (size_t col = 0; col < size; ++col)
        {
            printSpace(Coord{row, col});
            cout << '|';
        }
        cout << '\n';

        cout << padding;
        printGridLine();
    }
    cout << padding;
    printGridNumbers();
}


Coord Game::getCoord() const
{
    while (true)
    {
        cout << "Enter a coordinate: ";
        string line;
        getline(cin, line);
        istringstream iss(line);

        char letter;
        int digit;
        iss >> letter >> digit;
        if (!iss)
        {
            iss.clear();
            iss.ignore(9999);
            cerr << "Input stream failed!\n";
            continue;
        }

        if (!isalpha(letter))
        {
            cerr << "First char is not a letter!\n";
            continue;
        }

        size_t x = tolower(letter) - 'a';
        size_t y = digit - 1;
        Coord result{x, y};
        
        if (currentBoard().outOfBounds(result))
        {
            cerr << "Coords out of bounds!\n";
            continue;
        }
        
        return result;
    }
}
