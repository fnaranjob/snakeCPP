#ifndef PIXEL_H
#define PIXEL_H
#include <cstddef>

class Pixel
{
private:
    size_t x_pos;
    size_t y_pos;
    char display_char;
public:
    Pixel(size_t x, size_t y, char c);
};

#endif // PIXEL_H
