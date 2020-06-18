#include "pixel.h"
#include "utils.h"

Pixel::Pixel(int x, int y, PixelType pt)
    :x_pos_{x}, y_pos_{y}, p_type_{pt}
{

}


int Pixel::GetX_() const{
    return x_pos_;
}

int Pixel::GetY_() const{
    return y_pos_;
}

PixelType Pixel::GetType_() const{
    return p_type_;
}


void Pixel::SetPos_(int x, int y){
    x_pos_=x;
    y_pos_=y;
}

void Pixel::SetType_(PixelType t)
{
    p_type_ = t;
}
