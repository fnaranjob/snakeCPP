#include "board.h"
#include "utils.h"
#include <iostream>
#include "pixel.h"

Board::Board(size_t w, size_t h)
    :width_{w}, height_{h}, food_(RandomCoord(2,w-2),RandomCoord(2,h-2), PixelType::FOOD_CHAR), snake_(w,h,food_, kInitialSnakeLen)
{
    PixelType char_to_insert{PixelType::EMPTY};
    content_.reserve(width_*height_);

    for(size_t y=1; y<=height_; ++y){
        for(size_t x=1; x<=width_; ++x ){
            if(x==food_.GetX_() && y==food_.GetY_())
                char_to_insert= PixelType::FOOD_CHAR;
            else if(x==1 || y==1 || x==width_ || y==height_)
                char_to_insert= PixelType::BORDER_CHAR;
            else
                char_to_insert= PixelType::EMPTY;
            content_.push_back(char_to_insert);
        }
    }

    size_t i=0;
    for(const auto &pix: snake_.GetElements_()){
        if((i++)==0)
            content_.at(GetIndex(pix.GetX_(),pix.GetY_(),width_))= PixelType::SNAKE_HEAD_CHAR;
        else
            content_.at(GetIndex(pix.GetX_(),pix.GetY_(),width_))= PixelType::SNAKE_BODY_CHAR;
    }

}

void Board::Display_() const{
    size_t col{1};
    system("cls");

    for(const auto c: content_){
        if (c == PixelType::BORDER_CHAR)
            std::cout << kBorderColor << static_cast<char>(c) << color_codes::kReset;
        else if (c == PixelType::FOOD_CHAR)
            std::cout << kFoodColor << static_cast<char>(c) << color_codes::kReset;
        else if (c == PixelType::SNAKE_HEAD_CHAR || c == PixelType::SNAKE_BODY_CHAR)
            std::cout << kSnakeColor << static_cast<char>(c) << color_codes::kReset;
        else
            std::cout << static_cast<char>(c);
        if((col++)%width_ == 0)
            std::cout<<std::endl;
    }
}

void Board::PlaceFood_(size_t x, size_t y){
    content_.at(GetIndex(food_.GetX_(),food_.GetY_(),width_))=PixelType::EMPTY;
    food_.SetPos_(x,y);
    content_.at(GetIndex(food_.GetX_(),food_.GetY_(),width_))= PixelType::FOOD_CHAR;
}

bool Board::Update_(Direction dir)
{
    bool grow = false; 

    if (dir == Direction::NONE)
        return false; //Snake is not moving, nothing to update
    
    auto head = snake_.GetElements_().front();
    auto tail = snake_.GetElements_().back();
    content_.at(GetIndex(head.GetX_(), head.GetY_(), width_)) = PixelType::SNAKE_BODY_CHAR;
    if (!grow)
        content_.at(GetIndex(tail.GetX_(), tail.GetY_(),width_)) = PixelType::EMPTY;
    
    snake_.Update_(dir, grow);
    
    head = snake_.GetElements_().front();
    content_.at(GetIndex(head.GetX_(), head.GetY_(), width_)) = PixelType::SNAKE_HEAD_CHAR;

    return false;
}

void Board::Reset_()
{
}
