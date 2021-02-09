#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstddef>


class Board
{

public:

    using size_type = std::size_t;

public:

    Board():_board(std::vector(10, std::vector(10, false)))
    {}

public:

    void addHit(size_type x, size_type y)
    {
        _board[x][y] = true;
    }

    bool checkHit(size_type x, size_type y)
    {
        return _board[x][y];
    }

private:

    std::vector<std::vector<bool>> _board;

};


#endif  // BOARD_H