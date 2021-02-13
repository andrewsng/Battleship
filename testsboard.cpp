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
	b.checkSunk(Coord{ 3,1 });
	b.checkSunk(Coord{ 5,5 });

	REQUIRE(b.checkSunk(Coord{ 3,1 }));
	REQUIRE(b.checkSunk(Coord{ 5,5 }));

	REQUIRE(!b.checkSunk(Coord{ 3,1 }));
	REQUIRE(!b.checkSunk(Coord{ 5,5 }));



}