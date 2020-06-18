#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "pixel.h"
#include "utils.h"

class Snake
{
private:
    std::deque<Pixel> elements_;
public:
    Snake(int board_w, int board_h, Pixel food, int init_len);
    void Update_(Direction dir, bool grow=false);
    const std::deque<Pixel> &GetElements_() const;
};

#endif // SNAKE_H
