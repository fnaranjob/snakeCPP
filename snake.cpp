#include "snake.h"
#include <stdlib.h>
#include <iostream>

Snake::Snake(size_t board_w, size_t board_h, Pixel food, size_t init_len)
    :travel_dir_{NONE}
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
    elements_.emplace_back(head_x,head_y,SNAKE_HEAD_CHAR);

    for(size_t i=0; i<(init_len-1); ++i)
        elements_.emplace_back(--head_x,head_y,SNAKE_BODY_CHAR);

    //for(const auto &pix: elements_){
    //    std::cout<<"( "<<pix.GetX()<<", "<<pix.GetY()<<")"<<std::endl;
    //}
}

void Snake::Update_(Direction dir, bool grow){
    auto head=elements_.front();
    if(dir!=travel_dir_)
        travel_dir_=dir;

    switch (travel_dir_) {
    case UP:
        head.SetPos_(head.GetX_(),head.GetY_()+1);
        break;
    case DOWN:
        head.SetPos_(head.GetX_(),head.GetY_()-1);
        break;
    case LEFT:
        head.SetPos_(head.GetX_()-1,head.GetY_());
        break;
    case RIGHT:
        head.SetPos_(head.GetX_()+1,head.GetY_());
        break;
    case NONE:
        break;
    }
}

const std::deque<Pixel> &Snake::GetElements_() const{
    return elements_;
}

Direction Snake::GetDir_() const{
    return travel_dir_;
}
