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
    char display_char_;
    std::string pixel_color_;
public:
    Pixel(size_t x, size_t y, char c, std::string pc=color_codes::kWhite);
};

#endif // PIXEL_H
