#ifndef BOARD_H
#define BOARD_H

#include <vector>


class Board
{

public:

    Board():_board(std::vector(10, std::vector(10, 0)))
    {}

private:

    std::vector<std::vector<int>> _board;

};


#endif  // BOARD_H