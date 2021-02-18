// board.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Source for Board class

#include "board.h"


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


pair<bool, string> Board::addShip(Coord start, Coord end, const string& name)
{
    if (start.x == end.x && start.y == end.y)
        return make_pair(false, "Coordinates are the same");

    if (start.x != end.x && start.y != end.y)
        return make_pair(false, "Coordinates are not aligned");

    vector<Coord> shipCoords = coordsBetween(start, end);

    if (std::any_of(shipCoords.begin(), shipCoords.end(),
            [this] (Coord c) { return isOccupied(c); }))
        return make_pair(false, "Coordinates already occupied by ship");

    for (auto c : shipCoords)
    {
        occupyPoint(c, name);
    }

    return make_pair(true, "");
}


pair<bool,string> Board::sendAttack(Coord hitTile) {
	vector<Coord> attackCoordinates;
	for (auto c : attackCoordinates)
	{
		if (isHitAt(c))
			return make_pair(false,
				"Coordinates have already been hit");
	}
	attackCoordinates.push_back(Coord{ hitTile.x, hitTile.y });
	for (auto c : attackCoordinates)
	{
		isHitAt(c);
	}

	return make_pair(true, "");
}
