#ifndef PIXEL_H
#define PIXEL_H
#include <cstddef>
#include <string>
#include "utils.h"

class Pixel
{
private:
    size_t x_pos_;
    size_t y_pos_;
    PixelType p_type_;
public:
    Pixel(size_t x, size_t y, PixelType pt);
    size_t GetX() const;
    size_t GetY() const;
    void SetPos(size_t x, size_t y);
    PixelType GetType() const;
};

#endif // PIXEL_H
