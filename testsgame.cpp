// testsgame.cpp
// Andrew Ng, Rose Peters
// Created: 2021-02-13
//
// For CS 372 Spring 2021
// Tests for Game class

#include "catch.hpp"

#include "game.h"

#include <iostream>


TEST_CASE( "Add a ship using player input" ) {
    Game g;

    SECTION( "Ship 1" ) {
        std::cout << "Tests require coordinates: d6, d10\n";
        g.inputShip("ship1");
        Board b = g.board(0);
        for (std::size_t i = 5; i <= 9; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{3, i}));
            REQUIRE(b.shipAtPoint(Coord{3, i}) == "ship1");
        }
    }
    SECTION( "Ship 2" ) {
        std::cout << "\nTests require coordinates: c7, e7\n";
        g.inputShip("ship2");
        Board b = g.board(0);
        for (std::size_t i = 2; i <= 4; ++i)
        {
            REQUIRE(b.checkOccupied(Coord{i, 6}));
            REQUIRE(b.shipAtPoint(Coord{i, 6}) == "ship2");
        }
    }
}
