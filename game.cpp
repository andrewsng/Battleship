#include "game.h"


void Game::inputShip(const std::string& ship, std::size_t player, Coord start, Coord end)
{
    Coord c0, c1;
    while (true)
    {
        c0 = start;
        c1 = end;

        if (!(_boards[player].addShip(c0, c1, ship)))
            continue;

        break;
    }
}
