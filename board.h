#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstddef>


class Board
{

public:

    using size_type = std::size_t;

public:

    Board():_board(std::vector(10, std::vector(10, Point{})))
    {}

public:

    void hitPoint(size_type x, size_type y)
    {
        _board[x][y].isHit = true;
    }

    bool checkHit(size_type x, size_type y) const
    {
        return _board[x][y].isHit;
    }

    void occupyPoint(size_type x, size_type y)
    {
        _board[x][y].isOccupied = true;
    }

    bool checkOccupied(size_type x, size_type y) const
    {
        return _board[x][y].isOccupied;
    }

private:

    struct Point
    {
        bool isHit{ false };
        bool isOccupied{ false };
    };

private:

    std::vector<std::vector<Point>> _board;

};


#endif  // BOARD_H