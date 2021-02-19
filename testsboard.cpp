// testsboard.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-08
//
// For CS 372 Spring 2021
// Tests for Board class

#include "catch.hpp"

#include "board.h"


TEST_CASE( "A board with 10x10 spaces" ) {
    Board b;
    REQUIRE( b.size() == 10);
    REQUIRE( b.outOfBounds(Coord{0, 10}) );
    REQUIRE( b.outOfBounds(Coord{10, 0}) );
    REQUIRE( b.outOfBounds(Coord{10, 10}) );
}

TEST_CASE( "Mark a point on the board as attacked" ) {
    Board b;
    b.hit(Coord{0, 0});
    b.hit(Coord{4, 7});

    REQUIRE( b.isHitAt(Coord{0, 0}) );
    REQUIRE( b.isHitAt(Coord{4, 7}) );

    REQUIRE( !b.isHitAt(Coord{1, 5}) );
    REQUIRE( !b.isHitAt(Coord{6, 0}) );
}

TEST_CASE( "Mark a point on the board as occupied by a ship" ) {
    Board b;
    b.occupyPoint(Coord{7, 3}, "ship");
    b.occupyPoint(Coord{8, 2}, "ship");

    REQUIRE( b.isOccupied(Coord{7, 3}) );
    REQUIRE( b.isOccupied(Coord{8, 2}) );
    REQUIRE( b.shipAt(Coord{7, 3}) == "ship" );
    REQUIRE( b.shipAt(Coord{8, 2}) == "ship" );

    REQUIRE( !b.isOccupied(Coord{2, 6}) );
    REQUIRE( !b.isOccupied(Coord{9, 9}) );
    REQUIRE( b.shipAt(Coord{2, 6}) == "" );
    REQUIRE( b.shipAt(Coord{9, 9}) == "" );
}

TEST_CASE("Mark a ship as destroyed") {
	Board b;

	SECTION("Vertical Ship Sunk")
	{
		b.addShip(Coord{ 2, 2 }, Coord{ 2,5 }, "ship");

		for (std::size_t i = 2; i <= 5; i++) {
			b.hit(Coord{ 2,i });
		}

		for (std::size_t i = 2; i <= 5; i++)
		{
			REQUIRE(b.isHitAt(Coord{ 2,i }));
			REQUIRE(b.isOccupied(Coord{ 2,i }));
		}
        REQUIRE(b.isSunk("ship"));
	}

	SECTION("Horizontal Ship Sunk")
	{
		b.addShip(Coord{ 5, 6 }, Coord{ 8,6 }, "ship");

		for (std::size_t i = 5; i <= 8; i++) {
			b.hit(Coord{ i,6 });
		}

		for (std::size_t i = 5; i <= 8; i++)
		{
			REQUIRE(b.isHitAt(Coord{ i,6 }));
			REQUIRE(b.isOccupied(Coord{ i,6 }));
		}
        REQUIRE(b.isSunk("ship"));
	}

    SECTION("Vertical Ship Unsunk")
	{
		b.addShip(Coord{ 2, 2 }, Coord{ 2,5 }, "ship");

		for (std::size_t i = 2; i <= 4; i++) {
			b.hit(Coord{ 2,i });
		}

		for (std::size_t i = 2; i <= 4; i++)
		{
			REQUIRE(b.isHitAt(Coord{ 2,i }));
			REQUIRE(b.isOccupied(Coord{ 2,i }));
		}
        REQUIRE(!b.isHitAt(Coord{2, 5}));
        REQUIRE(b.isOccupied(Coord{2, 5}));
        REQUIRE(!b.isSunk("ship"));
	}

	SECTION("Horizontal Ship Unsunk")
	{
		b.addShip(Coord{ 5, 6 }, Coord{ 8,6 }, "ship");

		for (std::size_t i = 5; i <= 7; i++) {
			b.hit(Coord{ i,6 });
		}

		for (std::size_t i = 5; i <= 7; i++)
		{
			REQUIRE(b.isHitAt(Coord{ i,6 }));
			REQUIRE(b.isOccupied(Coord{ i,6 }));
		}
        REQUIRE(!b.isHitAt(Coord{8, 6}));
		REQUIRE(b.isOccupied(Coord{8, 6}));
        REQUIRE(!b.isSunk("ship"));
	}
}

TEST_CASE( "Add a full ship to a board" ) {
    Board b;

    SECTION( "Vertical Ship" ) {
        auto [worked, msg] = b.addShip(Coord{3, 5}, Coord{3, 9}, "ship");
        REQUIRE(worked);
        for (std::size_t i = 5; i <= 9; ++i)
        {
            REQUIRE(b.isOccupied(Coord{3, i}));
            REQUIRE(b.shipAt(Coord{3, i}) == "ship");
        }
    }
    SECTION( "Horizontal Ship" ) {
        auto [worked, msg] = b.addShip(Coord{2, 6}, Coord{4, 6}, "ship");
        REQUIRE(worked);
        for (std::size_t i = 2; i <= 4; ++i)
        {
            REQUIRE(b.isOccupied(Coord{i, 6}));
            REQUIRE(b.shipAt(Coord{i, 6}) == "ship");
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
