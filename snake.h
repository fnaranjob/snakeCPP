#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "pixel.h"
#include "utils.h"

class Snake
{
private:
    std::deque<Pixel> elements_;
    constants::Direction travel_dir_;
public:
    Snake(size_t board_w, size_t board_h, Pixel food, size_t init_len);
    void Update_(constants::Direction dir, bool grow=false);
    const std::deque<Pixel> &GetElements_() const;
    constants::Direction GetDir_() const;
};

#endif // SNAKE_H
