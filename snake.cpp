#include "snake.h"

Snake::Snake(int board_w, int board_h, Pixel food, int init_len)
{
    //Validate that snake fits board
    if((board_w - 2*kBorderInitDist - 2)<=init_len){
        exit(EXIT_FAILURE);
    }

    //Calculate snake's head initial coordinates
    int x_min = kBorderInitDist + init_len;
    int x_max = board_w - kBorderInitDist -1;
    int y_min = kBorderInitDist + 1;
    int y_max = board_h - kBorderInitDist -1;
    int head_x = RandomCoord(x_min, x_max);
    int head_y = RandomCoord(y_min, y_max);

    //Avoid placing the snake in the same row as the current food position
    if(head_y==food.GetY_()){
        if(head_y>y_min)
            head_y--;
        else
            head_y++;
    }

    //Create snake elements
    elements_.emplace_back(head_x,head_y, PixelType::SNAKE_HEAD_CHAR);

    for(int i=0; i<(init_len-1); ++i)
        elements_.emplace_back(--head_x,head_y, PixelType::SNAKE_BODY_CHAR);

}

void Snake::Update_(Direction dir, bool grow){

    auto head = elements_.front();
    auto head_x = head.GetX_();
    auto head_y = head.GetY_();
    head.SetType_(PixelType::SNAKE_BODY_CHAR);

    switch (dir) {
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
