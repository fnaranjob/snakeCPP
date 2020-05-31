#include "board.h"
#include "utils.h"
#include <iostream>

Board::Board(size_t w, size_t h, std::string bc)
    :width{w}, height{h}, border_color{bc}
{
    char char_to_insert{' '};
    content.reserve(width*height);

    for(size_t y=1; y<=height; ++y){
        for(size_t x=1; x<=width; ++x ){
            if(x==1 || y==1 || x==width || y==height)
                char_to_insert=BORDER_CHAR;
            else
                char_to_insert=' ';
            content.push_back(char_to_insert);
        }
    }
}

void Board::display() const{
    size_t col{1};
    for(const char c: content){
        if(c==BORDER_CHAR)
            std::cout<<border_color<<c<<color_codes::RESET;
        else
            std::cout<<c;
        if((col++)%width == 0)
            std::cout<<std::endl;
    }
}
