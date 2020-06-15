#include "board.h"
#include "utils.h"
#include <iostream>
#include "pixel.h"

Board::Board(size_t w, size_t h)
    :width_{w}, height_{h}, food_(RandomCoord(2,w-2),RandomCoord(2,h-2), PixelType::FOOD_CHAR), snake_(w,h,food_, kInitialSnakeLen)
{
    PixelType char_to_insert{PixelType::EMPTY};
    content_.reserve(width_*height_);

    for(size_t y=0; y<height_; ++y){
        for(size_t x=0; x<width_; ++x ){
            if(x==food_.GetX_() && y==food_.GetY_())
                char_to_insert= PixelType::FOOD_CHAR;
            else if(x==0 || y==0 || x==width_-1 || y==height_-1)
                char_to_insert= PixelType::BORDER_CHAR;
            else
                char_to_insert= PixelType::EMPTY;
            content_.emplace_back(x,y,char_to_insert);
        }
    }
    auto snake_elements = snake_.GetElements_();
    PixelType pix_type;
    for (auto it = snake_elements.begin(); it != snake_elements.end(); it++) {
        if ((it) == snake_elements.begin()) 
            pix_type = PixelType::SNAKE_HEAD_CHAR;
        else
            pix_type = PixelType::SNAKE_BODY_CHAR;
        auto x = it->GetX_();
        auto y = it->GetY_();
        content_.at(GetIndex(x, y, width_)) = Pixel(x,y,pix_type);
    }

}


void Board::PlaceFood_(size_t x, size_t y){
    auto initial_x = food_.GetX_();
    auto initial_y = food_.GetY_();
    content_.at(GetIndex(initial_x,initial_y,width_))=Pixel(initial_x,initial_y,PixelType::EMPTY);
    food_.SetPos_(x,y);
    content_.at(GetIndex(x,y,width_))= Pixel(x,y,PixelType::FOOD_CHAR);
}

bool Board::Update_(Direction dir)
{
    bool grow = true; 

    if (dir == Direction::NONE)
        return false; //Snake is not moving, nothing to update
    
    auto head = snake_.GetElements_().front();
    auto tail = snake_.GetElements_().back();
    auto head_x = head.GetX_();
    auto head_y = head.GetY_();
    auto tail_x = tail.GetX_();
    auto tail_y = tail.GetY_();

    content_.at(GetIndex(head_x, head_y, width_)) = Pixel(head_x,head_y,PixelType::SNAKE_BODY_CHAR);
    if (!grow)
        content_.at(GetIndex(tail_x, tail_y,width_)) = Pixel(tail_x,tail_y,PixelType::EMPTY);
    
    snake_.Update_(dir, grow);
    head = snake_.GetElements_().front();
    head_x = head.GetX_();
    head_y = head.GetY_();
    content_.at(GetIndex(head_x, head_y, width_)) = Pixel(head_x,head_y,PixelType::SNAKE_HEAD_CHAR);

    return false;
}

void Board::Reset_()
{
}

std::vector<Pixel>& Board::GetContent_()
{
    return content_;
}

size_t Board::GetWidth_() const
{
    return width_;
}

size_t Board::GetHeight_() const
{
    return height_;
}
