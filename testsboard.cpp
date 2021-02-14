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
	b.hitPoint(Coord{ 3,1 });
	b.hitPoint(Coord{ 5,3 });
	b.occupyPoint(Coord{ 3,1 }, "ship");
	b.occupyPoint(Coord{ 5,3 }, "ship");
	b.shipSunk(Coord{ 3,1 }, "ship");
	b.shipSunk(Coord{ 5,3 }, "ship");

	REQUIRE(b.checkSunk(Coord{ 3,1 }));
	REQUIRE(b.checkSunk(Coord{ 5,3 }));

	REQUIRE(!b.checkSunk(Coord{ 2,5 }));
	REQUIRE(!b.checkSunk(Coord{ 4,9 }));
}

TEST_CASE( "Add a full ship to a board" ) {
    Board b;

    SECTION( "Ship 1" ) {
        REQUIRE(b.addShip(Coord{3, 5}, Coord{3, 9}, "ship1"));
        for (std::size_t i = 5; i <= 9; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{3, i}));
            REQUIRE(b.shipAtPoint(Coord{3, i}) == "ship1");
        }
    }
    SECTION( "Ship 2" ) {
        REQUIRE(b.addShip(Coord{2, 6}, Coord{4, 6}, "ship2"));
        for (std::size_t i = 2; i <= 4; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{i, 6}));
            REQUIRE(b.shipAtPoint(Coord{i, 6}) == "ship2");
        }
    }
    REQUIRE(!b.addShip(Coord{1, 1}, Coord{2, 2}, "ship"));
    REQUIRE(!b.addShip(Coord{1, 3}, Coord{3, 1}, "ship"));
}
