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
    size_t GetX_() const;
    size_t GetY_() const;
    void SetPos_(size_t x, size_t y);
    PixelType GetType_() const;
};

#endif // PIXEL_H
