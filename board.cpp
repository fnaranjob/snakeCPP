#include "board.h"
#include "utils.h"
#include <iostream>

Board::Board(size_t w, size_t h)
    :width_{w}, height_{h}, food_(RandomCoord(2,w-2),RandomCoord(2,h-2),FOOD_CHAR)
{
    char char_to_insert{' '};
    content_.reserve(width_*height_);

    for(size_t y=1; y<=height_; ++y){
        for(size_t x=1; x<=width_; ++x ){
            if(x==food_.GetX() && y==food_.GetY())
                char_to_insert=FOOD_CHAR;
            else if(x==1 || y==1 || x==width_ || y==height_)
                char_to_insert=BORDER_CHAR;
            else
                char_to_insert=' ';
            content_.push_back(char_to_insert);
        }
    }
}

void Board::Display() const{
    size_t col{1};
    for(const char c: content_){
        if(c==BORDER_CHAR)
            std::cout<<kBorderColor<<c<<color_codes::kReset;
        else if(c==FOOD_CHAR)
            std::cout<<kFoodColor<<c<<color_codes::kReset;
        else
            std::cout<<c;
        if((col++)%width_ == 0)
            std::cout<<std::endl;
    }
}
