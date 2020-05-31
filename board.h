#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "utils.h"

class Board
{
private:
    const char kBorderChar_ = 'X';
    const std::string kBorderColor_;
    size_t width_;
    size_t height_;
    std::vector<char> content_;
    std::pair<size_t,size_t> food_pos_;

    //Snake s;

public:
    Board(size_t width_, size_t height_, std::string bc=color_codes::kBlue);
    void display() const;
    void reset();
};

#endif // BOARD_H
