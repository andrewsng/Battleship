#include "board.h"


pair<bool, string> Board::addShip(Coord start, Coord end, const string& name)
{
    if (start.x == end.x && start.y == end.y)
        return make_pair(false, "Coordinates are the same");

    if (start.x != end.x && start.y != end.y)
        return make_pair(false, "Coordinates are not aligned");

    // Determine which points the ship covers
    vector<Coord> shipCoordinates;
    if (start.x == end.x)  // Vertical ship
    {
        if (start.y > end.y)
            swap(start, end);
        for (auto row = start.y; row <= end.y; ++row)
            shipCoordinates.push_back(Coord{start.x, row});
    }
    else                   // Horizontal ship
    {
        if (start.x > end.x)
            swap(start, end);
        for (auto col = start.x; col <= end.x; ++col)
            shipCoordinates.push_back(Coord{col, start.y});
    }

    for (auto c : shipCoordinates)
    {
        if (checkOccupied(c))
            return make_pair(false,
                "Coordinates already occupied by ship");
    }
    for (auto c : shipCoordinates)
    {
        occupyPoint(c, name);
    }

    return make_pair(true, "");
}
