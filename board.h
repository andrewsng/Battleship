// board.h
// Andrew Ng, Rose Peters
// Created: 2021-02-08
//
// For CS 372 Spring 2021
// Header for Board class

#ifndef BOARD_H
#define BOARD_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstddef>
#include <utility>
using std::pair;
using std::make_pair;
#include <algorithm>
using std::swap;


// Coord struct
// Basic struct for a coordinate on the 2D Board grid.
// Can be used as: Coord{x, y} or Coord c{x, y}.
struct Coord
{
	std::size_t x{ 0 };
	std::size_t y{ 0 };
};


// Board class
// 2-dimensional square array of points containing hit/ship data.
class Board
{

public:

	Board() = default;

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
	void hit(Coord pos)
	{
		pointAt(pos).isHit = true;
	}

	// isHitAt
	// Return whether ship has been hit at a given coordinate.
	bool isHitAt(Coord pos) const
	{
		return pointAt(pos).isHit;
	}

	// occupyPoint
	// Set ship name, set tile to occupied.
	void occupyPoint(Coord pos, const string& name)
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

	// shipSunk
	// Set ship on tile to sank.
	void shipSunk(Coord pos, const string& name)
	{
			pointAt(pos).isSunk = true;
			pointAt(pos).shipName = name;
	}

	// checkSunk
	// Return whether a ship has sank or not.
	bool checkSunk(Coord pos) const
	{
		return pointAt(pos).isSunk;
	}

    // addShip
    // Given 2 coordinates aligned either vertically or
    //   horizontally, adds a ship between them, inclusively.
    // Returns whether the operation was successful, and an error
    //   message if unsuccessful.
    pair<bool, string>
        addShip(Coord start, Coord end, const string& name);

	// sendAttack
	// Given a coordinate, sets a tile to hit.
	// Returns whether the hit was successful, and an error
	// message if the tile was already hit.
	pair<bool,string> sendAttack(Coord hitTile);

private:

    // getCoordsBetween
    // Returns a list of coordinates between the 2 given, including them.
    vector<Coord> coordsBetween(Coord start, Coord end) const;

private:

    // Point struct
    // Holds data for a point on the 2D Board that informs:
    //  - Has this point been hit or not?
    //  - Is this point occupied by a ship?
    //     - ...and if so, what is the ship's name?
	struct Point
	{
		bool isHit{ false };
		bool isOccupied{ false };
		bool isSunk{ false };
		string shipName{};
	};

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

private:

    // Side length of the square grid.
    std::size_t _size{ 10 };

    // 2-dimensional square array of points.
    // NOTE: Requires _size to be initialized before construction.
	std::vector<std::vector<Point>> _board{ size(), std::vector<Point>{size()} };

};


#endif  // BOARD_H
