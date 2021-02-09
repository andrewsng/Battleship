#include "catch.hpp"

#include "board.h"


TEST_CASE( "Mark a point on the board as attacked" ) {
    Board b;
    b.addHit(0, 0);
    b.addHit(4, 7);

    REQUIRE( b.checkHit(0, 0) );
    REQUIRE( b.checkHit(4, 7) );
}