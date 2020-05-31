#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "utils.h"

class Board
{
private:
    const char BORDER_CHAR = 'X';
    size_t width;
    size_t height;
    std::vector<char> content;
    std::pair<size_t,size_t> food_pos;
    std::string border_color;
    //Snake s;

public:
    Board(size_t width, size_t height, std::string bc=color_codes::BLUE);
    void display() const;
    void reset();
};

#endif // BOARD_H
