#ifndef PIXEL_H
#define PIXEL_H

#include "utils.h"

class Pixel
{
private:
    int x_pos_;
    int y_pos_;
    PixelType p_type_;
public:
    Pixel(int x, int y, PixelType pt);
    int GetX_() const;
    int GetY_() const;
    void SetPos_(int x, int y);
    void SetType_(PixelType t);
    PixelType GetType_() const;
};

#endif // PIXEL_H
