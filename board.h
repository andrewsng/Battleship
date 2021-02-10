#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <cstddef>


class Board
{

public:

    using size_type = std::size_t;

public:

    Board() = default;

public:

    void hitPoint(size_type x, size_type y)
    {
        _board[x][y].isHit = true;
    }

    bool checkHit(size_type x, size_type y) const
    {
        return _board[x][y].isHit;
    }

    void occupyPoint(size_type x, size_type y, std::string name)
    {
        _board[x][y].isOccupied = true;
        _board[x][y].shipName = name;
    }

    bool checkOccupied(size_type x, size_type y) const
    {
        return _board[x][y].isOccupied;
    }

    std::string shipAtPoint(size_type x, size_type y) const
    {
        return _board[x][y].shipName;
    }

private:

    struct Point
    {
        bool isHit{ false };
        bool isOccupied{ false };
        std::string shipName{};
    };

private:

    std::vector<std::vector<Point>> _board{10, std::vector<Point>{10}};

};


#endif  // BOARD_H
