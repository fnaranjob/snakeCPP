#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "utils.h"
#include "pixel.h"
#include "snake.h"

class Board
{
private:

    int width_;
    int height_;
    std::vector<Pixel> content_;
    Pixel food_;
    Snake snake_;

public:
    Board(int w, int h);
    bool Update_(Direction dir); //returns true if collision happened
    void Reset_();
    std::vector<Pixel> &GetContent_();
    int GetWidth_() const;
    int GetHeight_() const;
    Pixel GetFood_() const;
};

#endif // BOARD_H
