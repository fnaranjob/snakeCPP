#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "utils.h"
#include "pixel.h"

class Board
{
private:

    size_t width_;
    size_t height_;
    std::vector<char> content_;
    Pixel food_;

    //Snake s;

public:
    Board(size_t w, size_t h);
    void Display_() const;
    void PlaceFood_(size_t x, size_t y);
    void Reset_();
};

#endif // BOARD_H
