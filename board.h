#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "utils.h"
#include "pixel.h"
#include "snake.h"

class Board
{
private:

    size_t width_;
    size_t height_;
    std::vector<Pixel> content_;
    Pixel food_;
    Snake snake_;

public:
    Board(size_t w, size_t h);
    void PlaceFood_(size_t x, size_t y);
    bool Update_(Direction dir);
    void Reset_();
    std::vector<Pixel> &GetContent_();
    size_t GetWidth_() const;
    size_t GetHeight_() const;
};

#endif // BOARD_H
