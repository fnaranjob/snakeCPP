#include "snake.h"
#include <stdlib.h>
#include <iostream>

Snake::Snake(size_t board_w, size_t board_h, Pixel food, size_t init_len)
    :travel_dir_{Direction::NONE}
{
    //Validate that snake fits board
    if((board_w - 2*kBorderInitDist - 2)<=init_len){
        std::cerr<<"Snake doesn't fit board, can't continue..."<<std::endl;
        exit(EXIT_FAILURE);
    }

    //Calculate snake's head initial coordinates
    size_t x_min = kBorderInitDist + init_len;
    size_t x_max = board_w - kBorderInitDist -1;
    size_t y_min = kBorderInitDist + 1;
    size_t y_max = board_h - kBorderInitDist -1;
    size_t head_x = RandomCoord(x_min, x_max);
    size_t head_y = RandomCoord(y_min, y_max);

    std::cout<<"min: "<<x_min<<" max: "<<x_max<<" X: "<<head_x<<std::endl;
    //Avoid placing the snake in the same row as the current food position
    if(head_y==food.GetY_()){
        if(head_y>y_min)
            head_y--;
        else
            head_y++;
    }

    //Create snake elements
    elements_.emplace_back(head_x,head_y, PixelType::SNAKE_HEAD_CHAR);

    for(size_t i=0; i<(init_len-1); ++i)
        elements_.emplace_back(--head_x,head_y, PixelType::SNAKE_BODY_CHAR);

}

void Snake::Update_(Direction dir, bool grow){

    if(dir!=travel_dir_)
        travel_dir_=dir;

    auto head = elements_.front();
    size_t head_x = head.GetX_();
    size_t head_y = head.GetY_();
    head.SetType_(PixelType::SNAKE_BODY_CHAR);

    switch (travel_dir_) {
        case Direction::UP:
            elements_.emplace_front(head_x,head_y - 1, PixelType::SNAKE_HEAD_CHAR);
            break;
        case Direction::DOWN:
            elements_.emplace_front(head_x, head_y + 1, PixelType::SNAKE_HEAD_CHAR);
            break;
        case Direction::LEFT:
            elements_.emplace_front(head_x - 1 , head_y, PixelType::SNAKE_HEAD_CHAR);
            break;
        case Direction::RIGHT:
            elements_.emplace_front(head_x + 1, head_y, PixelType::SNAKE_HEAD_CHAR);
            break;
        case Direction::NONE:
            break;
    }
    if(!grow)
        elements_.pop_back();

}

const std::deque<Pixel> &Snake::GetElements_() const{
    return elements_;
}

Direction Snake::GetDir_() const{
    return travel_dir_;
}
