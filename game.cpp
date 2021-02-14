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
#include <cctype>
using std::isalpha;
using std::tolower;


void Game::inputShip(const string& ship, std::size_t player)
{
    Coord c0, c1;
    while (true)
    {
        cout << "Enter start and end coordinates for the ship - \"" << ship << "\"\n";
        c0 = getCoord();
        c1 = getCoord();

        auto [worked, msg] = _boards[player].addShip(c0, c1, ship);
        if (!worked)
        {
            cout << "Could not place ship. Try again: " << msg << '\n';
            continue;
        }

        break;
    }
}


Coord Game::getCoord()
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

        if (x >= 10 || y >= 10)
        {
            cerr << "Coords out of bounds!\n";
            continue;
        }
        
        return Coord{x, y};
    }
}
