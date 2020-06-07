#include "board.h"
#include "utils.h"
#include <iostream>
#include "pixel.h"

Board::Board(size_t w, size_t h)
    :width_{w}, height_{h}, food_(RandomCoord(2,w-2),RandomCoord(2,h-2), constants::FOOD_CHAR), snake_(w,h,food_, constants::kInitialSnakeLen)
{
    char char_to_insert{' '};
    content_.reserve(width_*height_);

    for(size_t y=1; y<=height_; ++y){
        for(size_t x=1; x<=width_; ++x ){
            if(x==food_.GetX_() && y==food_.GetY_())
                char_to_insert= constants::FOOD_CHAR;
            else if(x==1 || y==1 || x==width_ || y==height_)
                char_to_insert= constants::BORDER_CHAR;
            else
                char_to_insert=' ';
            content_.push_back(char_to_insert);
        }
    }

    size_t i=0;
    for(const auto &pix: snake_.GetElements_()){
        if((i++)==0)
            content_.at(GetIndex(pix.GetX_(),pix.GetY_(),width_))= constants::SNAKE_HEAD_CHAR;
        else
            content_.at(GetIndex(pix.GetX_(),pix.GetY_(),width_))= constants::SNAKE_BODY_CHAR;
    }

}

void Board::Display_() const{
    size_t col{1};
    system("cls");
    for(const char c: content_){
        if(c== constants::BORDER_CHAR)
            std::cout<< constants::kBorderColor<<c<<color_codes::kReset;
        else if(c== constants::FOOD_CHAR)
            std::cout<< constants::kFoodColor<<c<<color_codes::kReset;
        else if(c== constants::SNAKE_HEAD_CHAR || c== constants::SNAKE_BODY_CHAR)
            std::cout<< constants::kSnakeColor<<c<<color_codes::kReset;
        else
            std::cout<<c;
        if((col++)%width_ == 0)
            std::cout<<std::endl;
    }
}

void Board::PlaceFood_(size_t x, size_t y){
    content_.at(GetIndex(food_.GetX_(),food_.GetY_(),width_))=' ';
    food_.SetPos_(x,y);
    content_.at(GetIndex(food_.GetX_(),food_.GetY_(),width_))= constants::FOOD_CHAR;
}

void Board::Reset_()
{
}
