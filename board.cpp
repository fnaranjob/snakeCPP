#include "board.h"
#include "utils.h"
#include <iostream>

Board::Board(size_t w, size_t h, std::string bc)
    :width_{w}, height_{h}, kBorderColor_{bc}
{
    char char_to_insert{' '};
    content_.reserve(width_*height_);

    for(size_t y=1; y<=height_; ++y){
        for(size_t x=1; x<=width_; ++x ){
            if(x==1 || y==1 || x==width_ || y==height_)
                char_to_insert=kBorderChar_;
            else
                char_to_insert=' ';
            content_.push_back(char_to_insert);
        }
    }
}

void Board::display() const{
    size_t col{1};
    for(const char c: content_){
        if(c==kBorderChar_)
            std::cout<<kBorderColor_<<c<<color_codes::kReset;
        else
            std::cout<<c;
        if((col++)%width_ == 0)
            std::cout<<std::endl;
    }
}
