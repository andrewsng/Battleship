#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <cstddef>


struct Coord
{
	std::size_t x{ 0 };
	std::size_t y{ 0 };
};


class Board
{

public:

	Board() = default;

public:

	// hitPoint
	// Set tile to hit.
	void hitPoint(Coord pos)
	{
		pointAt(pos).isHit = true;
	}

	// checkHit
	// Return whether ship has been hit or not.
	bool checkHit(Coord pos) const
	{
		return pointAt(pos).isHit;
	}

	// occupyPoint
	// Set ship name, set tile to occupied.
	void occupyPoint(Coord pos, const std::string& name)
	{
		pointAt(pos).isOccupied = true;
		pointAt(pos).shipName = name;
	}

	// checkOccupied
	// Return whether a tile is occupied by a ship or not.
	bool checkOccupied(Coord pos) const
	{
		return pointAt(pos).isOccupied;
	}

	// shipAtPoint
	// Return name of ship.
	std::string shipAtPoint(Coord pos) const
	{
		return pointAt(pos).shipName;
	}

	// shipSunk
	// Set ship on tile to sank.
	void shipSunk(Coord pos, const std::string& name)
	{
		hitPoint(pos);
		occupyPoint(pos, name);
		if (checkOccupied(pos) && checkHit(pos)) {
			pointAt(pos).isSunk = true;
		}
	}

	// checkSunk
	// Return whether a ship has sank or not.
	bool checkSunk(Coord pos) const
	{
		return pointAt(pos).isSunk;
	}

    bool addShip(Coord start, Coord end, const std::string& name)
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

private:

	struct Point
	{
		bool isHit{ false };
		bool isOccupied{ false };
		bool isSunk{ false };
		std::string shipName{};
	};

	Point& pointAt(Coord pos)
	{
		return _board[pos.x][pos.y];
	}
	const Point& pointAt(Coord pos) const
	{
		return _board[pos.x][pos.y];
	}

private:

	std::vector<std::vector<Point>> _board{ 10, std::vector<Point>{10} };

};


#endif  // BOARD_H
