#include "catch.hpp"

#include "game.h"


TEST_CASE( "Add a ship using player input" ) {
    Game g;

    SECTION( "Ship 1" ) {
        g.inputShip("ship1", 0, Coord{3, 5}, Coord{3, 9});
        Board b = g.board(0);
        for (std::size_t i = 5; i <= 9; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{3, i}));
            REQUIRE(b.shipAtPoint(Coord{3, i}) == "ship1");
        }
    }
    SECTION( "Ship 2" ) {
        g.inputShip("ship2", 1, Coord{2, 6}, Coord{4, 6});
        Board b = g.board(1);
        REQUIRE(b.addShip(Coord{2, 6}, Coord{4, 6}, "ship2"));
        for (std::size_t i = 2; i <= 4; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{i, 6}));
            REQUIRE(b.shipAtPoint(Coord{i, 6}) == "ship2");
        }
    }
}
