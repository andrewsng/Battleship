#include "catch.hpp"

#include "board.h"


TEST_CASE( "Mark a point on the board as attacked" ) {
    Board b;
    b.hitPoint(0, 0);
    b.hitPoint(4, 7);

    REQUIRE( b.checkHit(0, 0) );
    REQUIRE( b.checkHit(4, 7) );

    REQUIRE( !b.checkHit(1, 5) );
    REQUIRE( !b.checkHit(6, 0) );
}

TEST_CASE( "Mark a point on the board as occupied by a ship" ) {
    Board b;
    b.occupyPoint(7, 3, "ship");
    b.occupyPoint(8, 2, "ship");

    REQUIRE( b.checkOccupied(7, 3) );
    REQUIRE( b.checkOccupied(8, 2) );
    REQUIRE( b.shipAtPoint(7, 3) == "ship" );
    REQUIRE( b.shipAtPoint(8, 2) == "ship" );

    REQUIRE( !b.checkOccupied(2, 6) );
    REQUIRE( !b.checkOccupied(9, 9) );
    REQUIRE( b.shipAtPoint(2, 6) == "" );
    REQUIRE( b.shipAtPoint(9, 9) == "" );
}
