// testsboard.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-08
//
// For CS 372 Spring 2021
// Tests for Board class

#include "catch.hpp"

#include "board.h"


TEST_CASE( "Mark a point on the board as attacked" ) {
    Board b;
    b.hitPoint(Coord{0, 0});
    b.hitPoint(Coord{4, 7});

    REQUIRE( b.checkHit(Coord{0, 0}) );
    REQUIRE( b.checkHit(Coord{4, 7}) );

    REQUIRE( !b.checkHit(Coord{1, 5}) );
    REQUIRE( !b.checkHit(Coord{6, 0}) );
}

TEST_CASE( "Mark a point on the board as occupied by a ship" ) {
    Board b;
    b.occupyPoint(Coord{7, 3}, "ship");
    b.occupyPoint(Coord{8, 2}, "ship");

    REQUIRE( b.checkOccupied(Coord{7, 3}) );
    REQUIRE( b.checkOccupied(Coord{8, 2}) );
    REQUIRE( b.shipAtPoint(Coord{7, 3}) == "ship" );
    REQUIRE( b.shipAtPoint(Coord{8, 2}) == "ship" );

    REQUIRE( !b.checkOccupied(Coord{2, 6}) );
    REQUIRE( !b.checkOccupied(Coord{9, 9}) );
    REQUIRE( b.shipAtPoint(Coord{2, 6}) == "" );
    REQUIRE( b.shipAtPoint(Coord{9, 9}) == "" );
}

TEST_CASE("Mark a ship as destroyed") {
	Board b;

	SECTION("Vertical Ship")
	{
		b.addShip(Coord{ 2, 2 }, Coord{ 2,5 }, "ship");

		for (std::size_t i = 2; i <= 5; i++) {
			b.hitPoint(Coord{ 2,i });
			b.occupyPoint(Coord{ 2,i }, "ship");
			b.shipSunk(Coord{ 2,i }, "ship");
		}

		for (std::size_t i = 2; i <= 5; i++)
		{
			REQUIRE(b.checkHit(Coord{ 2,i }));
			REQUIRE(b.checkOccupied(Coord{ 2,i }));
			REQUIRE(b.checkSunk(Coord{ 2,i }));

		}
		for (std::size_t i = 3; i <= 5; i++)
		{
			REQUIRE(!b.checkSunk(Coord{ 3,i }));
		}
		REQUIRE(!b.checkSunk(Coord{ 4,5 }));

	}

	SECTION("Horizontal Ship")
	{
		b.addShip(Coord{ 5, 6 }, Coord{ 8,6 }, "ship");

		for (std::size_t i = 5; i <= 8; i++) {
			b.hitPoint(Coord{ i,6 });
			b.occupyPoint(Coord{ i,6 }, "ship");
			b.shipSunk(Coord{ i,6 }, "ship");
		}

		for (std::size_t i = 5; i <= 8; i++)
		{
			REQUIRE(b.checkHit(Coord{ i,6 }));
			REQUIRE(b.checkOccupied(Coord{ i,6 }));
			REQUIRE(b.checkSunk(Coord{ i,6 }));

		}
		for (std::size_t i = 5; i <= 7; i++)
		{
			REQUIRE(!b.checkSunk(Coord{ i,6 }));
		}
		REQUIRE(!b.checkSunk(Coord{ 2,2 }));

	}
}

TEST_CASE( "Add a full ship to a board" ) {
    Board b;

    SECTION( "Vertical Ship" ) {
        auto [worked, msg] = b.addShip(Coord{3, 5}, Coord{3, 9}, "ship");
        REQUIRE(worked);
        for (std::size_t i = 5; i <= 9; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{3, i}));
            REQUIRE(b.shipAtPoint(Coord{3, i}) == "ship");
        }
    }
    SECTION( "Horizontal Ship" ) {
        auto [worked, msg] = b.addShip(Coord{2, 6}, Coord{4, 6}, "ship");
        REQUIRE(worked);
        for (std::size_t i = 2; i <= 4; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{i, 6}));
            REQUIRE(b.shipAtPoint(Coord{i, 6}) == "ship");
        }
    }
    SECTION( "Coordinates not aligned" ) {
        auto [worked, msg] = b.addShip(Coord{1, 1}, Coord{2, 2}, "ship");
        REQUIRE(!worked);
        REQUIRE(msg == "Coordinates are not aligned");
    }
    SECTION( "Coordinates the same" ) {
        auto [worked, msg] = b.addShip(Coord{4, 4}, Coord{4, 4}, "ship");
        REQUIRE(!worked);
        REQUIRE(msg == "Coordinates are the same");
    }
    SECTION( "Coordinates occupied by other ship" ) {
        b.addShip(Coord{3, 5}, Coord{3, 9}, "ship");
        auto [worked, msg] = b.addShip(Coord{1, 7}, Coord{5, 7}, "ship");
        REQUIRE(!worked);
        REQUIRE(msg == "Coordinates already occupied by ship");
    }
}
