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

	void hitPoint(Coord pos)
	{
		pointAt(pos).isHit = true;
	}

	bool checkHit(Coord pos) const
	{
		return pointAt(pos).isHit;
	}

	void occupyPoint(Coord pos, std::string name)
	{
		pointAt(pos).isOccupied = true;
		pointAt(pos).shipName = name;
	}

	bool checkOccupied(Coord pos) const
	{
		return pointAt(pos).isOccupied;
	}

	std::string shipAtPoint(Coord pos) const
	{
		return pointAt(pos).shipName;
	}

	void shipSunk(Coord pos)
	{
		if (checkOccupied(pos) && checkHit(pos))
			pointAt(pos).isSunk = true;
	}

	bool checkSunk(Coord pos) const
	{
		return pointAt(pos).isSunk;
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
