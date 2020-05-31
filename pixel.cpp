#include "pixel.h"
#include <iostream>
#include "utils.h"

Pixel::Pixel(size_t x, size_t y, PixelType pt)
    :x_pos_{x}, y_pos_{y}, p_type_{pt}
{

}

size_t Pixel::GetX() const{
    return x_pos_;
}

size_t Pixel::GetY() const{
    return y_pos_;
}

PixelType Pixel::GetType() const{
    return p_type_;
}

void Pixel::SetPos(size_t x, size_t y){
    x_pos_=x;
    y_pos_=y;
}
