// board.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Source for Board class

#include "board.h"

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;
using std::make_pair;
using std::swap;
#include <algorithm>
using std::any_of;
#include <cmath>
using std::abs;
#include <cstddef>
using std::size_t;


vector<Coord> Board::coordsBetween(Coord start, Coord end) const
{
    vector<Coord> coordinates;
    if (start.x == end.x)  // Vertical Case
    {
        if (start.y > end.y)
            swap(start, end);
        for (auto row = start.y; row <= end.y; ++row)
            coordinates.push_back(Coord{start.x, row});
    }
    else                   // Horizontal Case
    {
        if (start.x > end.x)
            swap(start, end);
        for (auto col = start.x; col <= end.x; ++col)
            coordinates.push_back(Coord{col, start.y});
    }

    return coordinates;
}


bool Board::rightShipSize(Coord start, Coord end, size_t restrictSize) const
{
    std::size_t shipSize;
    if (start.x == end.x)  // Vertical Case
        shipSize = abs(int(start.y) - int(end.y)) + 1;
    else                   // Horizontal Case
        shipSize = abs(int(start.x) - int(end.x)) + 1;
    
    return shipSize == restrictSize;
}


pair<bool, string> Board::addShip(Coord start, Coord end,
    const string& name, size_t restrictSize)
{
    if (start.x == end.x && start.y == end.y)
        return make_pair(false, "Coordinates are the same");

    if (start.x != end.x && start.y != end.y)
        return make_pair(false, "Coordinates are not aligned");

    if (restrictSize != 0 && !rightShipSize(start, end, restrictSize))
        return make_pair(false, "Ship is not the right size");

    vector<Coord> shipCoords = coordsBetween(start, end);

    if (any_of(shipCoords.begin(), shipCoords.end(),
            [this] (Coord c) { return isOccupied(c); }))
        return make_pair(false, "Coordinates already occupied by ship");

    for (auto c : shipCoords)
    {
        occupyPoint(c, name);
    }

    return make_pair(true, "");
}