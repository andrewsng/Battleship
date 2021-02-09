#include "catch.hpp"

#include "board.h"


TEST_CASE( "Mark a point on the board as attacked" ) {
    Board b;
    b.hitPoint(0, 0);
    b.hitPoint(4, 7);

    REQUIRE( b.checkHit(0, 0) );
    REQUIRE( b.checkHit(4, 7) );
}

TEST_CASE( "Mark a point on the board as occupied by a ship" ) {
    Board b;
    b.occupyPoint(7, 3);
    b.occupyPoint(8, 2);

    REQUIRE( b.checkOccupied(7, 3) );
    REQUIRE( b.checkOccupied(8, 2) );
}