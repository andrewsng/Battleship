#include "board.h"


bool Board::addShip(Coord start, Coord end, const std::string& name)
{
    if (start.x == end.x && start.y == end.y)
        return false;

    if (start.x != end.x && start.y != end.y)
        return false;

    if (start.x == end.x)  // Vertical Ship
    {
        if (start.y > end.y)
            std::swap(start, end);

        for (auto row = start.y; row <= end.y; ++row)
        {
            occupyPoint(Coord{start.x, row}, name);
        }
    }
    else  // Horizontal Ship
    {
        if (start.x > end.x)
            std::swap(start, end);

        for (auto col = start.x; col <= end.x; ++col)
        {
            occupyPoint(Coord{col, start.y}, name);
        }
    }

    return true;
}
