#include "pixel.h"
#include <iostream>
#include "utils.h"

Pixel::Pixel(size_t x, size_t y, PixelType pt)
    :x_pos_{x}, y_pos_{y}, p_type_{pt}
{

}

std::ostream& operator<<(std::ostream& os, const Pixel& rhs) {
    os << "("<<rhs.x_pos_<<","<<rhs.y_pos_<<")"<<std::endl;
    return os;
}

size_t Pixel::GetX_() const{
    return x_pos_;
}

size_t Pixel::GetY_() const{
    return y_pos_;
}

PixelType Pixel::GetType_() const{
    return p_type_;
}

void Pixel::SetPos_(size_t x, size_t y){
    x_pos_=x;
    y_pos_=y;
}

void Pixel::SetType_(PixelType t)
{
    p_type_ = t;
}
