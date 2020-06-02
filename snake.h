#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "pixel.h"
#include "utils.h"

class Snake
{
private:
    std::deque<Pixel> elements_;
    Direction travel_dir_;
public:
    Snake(size_t board_w, size_t board_h, Pixel food, size_t init_len);
    bool Update_(Direction dir, bool grow=false); //Returns true if collision occurs after update
};

#endif // SNAKE_H
