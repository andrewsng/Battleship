// board.h
// Andrew Ng, Rose Peters
// Created: 2021-02-08
//
// For CS 372 Spring 2021
// Header for Board class

#ifndef BOARD_H
#define BOARD_H

#include <vector>   // For std::vector
#include <string>   // For std::string
#include <utility>  // For std::pair
#include <cstddef>  // For std::size_t


// struct Coord
// Basic struct for a coordinate on the 2D Board grid.
// Can be used as: Coord{x, y} or Coord c{x, y}.
struct Coord
{
	std::size_t x{ 0 };
	std::size_t y{ 0 };
};  // End struct Coord


// class Board
// 2-dimensional square array of points containing hit/ship data.
class Board
{

// ---- Board: ctors, dctors, op= ----
public:

    // Default ctor.
	Board() = default;

    // Default dctor.
    ~Board() = default;

    // Copy, move, op= all deleted.
    Board(const Board &other) = delete;
    Board &operator=(const Board &other) = delete;
    Board(Board &&other) = delete;
    Board &operator=(Board &&other) = delete;

// ---- Board: General public functions ----
public:

    // size
    // Returns size of a side of the board.
    std::size_t size() const
    {
        return _size;
    }

    // outOfBounds
    // Returns whether a Coord is out of board boundaries.
    bool outOfBounds(Coord pos) const
    {
        return pos.x >= size() || pos.y >= size();
    }

	// hit
	// Set tile to hit.
	// Returns whether the operation was successful, and an error
    //   message if unsuccessful.
	std::pair<bool, std::string> hit(Coord pos)
	{
		if (isHitAt(pos))
			return std::make_pair(false,
				"Coordinates have already been hit");

		pointAt(pos).isHit = true;
		return std::make_pair(true, "");
	}

	// isHitAt
	// Return whether ship has been hit at a given coordinate.
	bool isHitAt(Coord pos) const
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

	// isOccupied
	// Return whether a tile is occupied by a ship at a given coordinate.
	bool isOccupied(Coord pos) const
	{
		return pointAt(pos).isOccupied;
	}

	// shipAt
	// Return name of ship.
	std::string shipAt(Coord pos) const
	{
		return pointAt(pos).shipName;
	}

	// isSunk
	// Return whether a given ship has sank or not.
	bool isSunk(const std::string& name) const
	{
		for (const auto& row : _board)
		{
			for (const auto& point : row)
			{
				if (point.isOccupied && point.shipName == name
				 && !point.isHit)
				{
					return false;
				}
			}
		}
		return true;
	}

    // addShip
    // Given 2 coordinates aligned either vertically or
    //   horizontally, adds a ship between them, inclusively.
    // Returns whether the operation was successful, and an error
    //   message if unsuccessful.
    std::pair<bool, std::string>
        addShip(Coord start, Coord end, const std::string& name, std::size_t restrictSize);

	// sendAttack
	// Given a coordinate, sets a tile to hit.
	// Returns whether the hit was successful, and an error
	// message if the tile was already hit.
    std::pair<bool,std::string> sendAttack(Coord hitTile);

// ---- Board: General private functions ----
private:

    // getCoordsBetween
    // Returns a list of coordinates between the 2 given, including them.
    std::vector<Coord> coordsBetween(Coord start, Coord end) const;

// ---- Board: Private Point struct and helper functions ----
private:

    // struct Point
    // Holds data for a point on the 2D Board that informs:
    //  - Has this point been hit or not?
    //  - Is this point occupied by a ship?
    //     - ...and if so, what is the ship's name?
	struct Point
	{
		bool isHit{ false };
		bool isOccupied{ false };
        std::string shipName{};
	};  // End struct Point

    // pointAt
    // Returns a reference to the point data at a given coordinate.
	Point& pointAt(Coord pos)
	{
		return _board[pos.x][pos.y];
	}
	const Point& pointAt(Coord pos) const
	{
		return _board[pos.x][pos.y];
	}

// ---- Board: Private data members ----
private:

    // Side length of the square grid.
    std::size_t _size{ 10 };

    // 2-dimensional square array of points.
    // NOTE: Requires _size to be initialized before construction.
	std::vector<std::vector<Point>> _board{ size(), std::vector<Point>{size()} };

};  // End class Board


#endif  // BOARD_H
