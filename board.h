#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
private:
    const char BORDER_CHAR = 'X';
    size_t width;
    size_t height;
    std::vector<char> content;
    std::pair<size_t,size_t> food_pos;
    //Snake s;

public:
    Board(size_t width, size_t height);
    void display() const;
    void reset();
};

#endif // BOARD_H
