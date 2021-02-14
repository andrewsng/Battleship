#include "board.h"


pair<bool, string> Board::addShip(Coord start, Coord end, const string& name)
{
    if (start.x == end.x && start.y == end.y)
        return make_pair(false, "Coordinates are the same");

    if (start.x != end.x && start.y != end.y)
        return make_pair(false, "Coordinates are not aligned");

    vector<Coord> coordinates;
    if (start.x == end.x)  // VERTICAL SHIP
    {
        if (start.y > end.y)
            swap(start, end);
        for (auto row = start.y; row <= end.y; ++row)
            coordinates.push_back(Coord{start.x, row});
    }
    else                   // HORIZONTAL SHIP
    {
        if (start.x > end.x)
            swap(start, end);
        for (auto col = start.x; col <= end.x; ++col)
            coordinates.push_back(Coord{col, start.y});
    }

    for (auto c : coordinates)
    {
        if (checkOccupied(c))
            return make_pair(false,
                "Coordinates already occupied by ship");
    }
    for (auto c : coordinates)
    {
        occupyPoint(c, name);
    }

    return make_pair(true, "");
}
