// game.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Source for Game class

#include "game.h"
#include "board.h"

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
    std::cout << '+';
    for (std::size_t col = 0; col < currentBoard().size(); ++col)
    {
        std::cout << "---+";
    }
    std::cout << '\n';
}


void Game::printGridNumbers() const
{
    std::cout << ' ';
    for (std::size_t colNum = 1; colNum < currentBoard().size()+1; ++colNum)
    {
        std::cout << ' ' << colNum << "  ";
    }
    std::cout << '\n';
}


void Game::printSpace(Coord pos) const
{
    if (currentBoard().isOccupied(pos))
    {
        const char shipLetter = currentBoard().shipAt(pos)[0];
        std::cout << '[' << shipLetter << ']';
    }
    else
    {
        std::cout << " - ";
    }
}


void Game::printShips() const
{
    const std::size_t size = currentBoard().size();
    const std::string padding = "   "; // 3 spaces

    std::cout << padding;
    printGridLine();
    for (std::size_t row = 0; row < size; ++row)
    {
        char rowLetter = 'A' + row;
        std::cout << ' ' << rowLetter << " |";
        for (std::size_t col = 0; col < size; ++col)
        {
            printSpace(Coord{row, col});
            std::cout << '|';
        }
        std::cout << '\n';

        std::cout << padding;
        printGridLine();
    }
    std::cout << padding;
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

        std::size_t x = tolower(letter) - 'a';
        std::size_t y = digit - 1;
        Coord result{x, y};
        
        if (currentBoard().outOfBounds(result))
        {
            cerr << "Coords out of bounds!\n";
            continue;
        }
        
        return result;
    }
}
