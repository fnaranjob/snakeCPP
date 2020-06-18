#include "board.h"
#include "utils.h"
#include "pixel.h"

Board::Board(int w, int h)
    :width_{w}, height_{h}, food_(RandomCoord(2,w-2),RandomCoord(2,h-2), PixelType::FOOD_CHAR), snake_(w,h,food_, kInitialSnakeLen)
{
    PixelType char_to_insert{PixelType::EMPTY};

    for(int y=0; y<height_; ++y){
        for(int x=0; x<width_; ++x ){
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
        int x = it->GetX_();
        int y = it->GetY_();
        content_.at(GetIndex(x, y, width_)) = Pixel(x,y,pix_type);
    }

}

bool Board::Update_(Direction dir)
{
    if (dir == Direction::NONE)
        return false; //Snake is not moving, nothing to update

    auto head = snake_.GetElements_().front();
    auto tail = snake_.GetElements_().back();
    int head_x = head.GetX_();
    int head_y = head.GetY_();
    int tail_x = tail.GetX_();
    int tail_y = tail.GetY_();
    bool grow{ false };

    Pixel* destination{&head};

    switch (dir) {
    case Direction::UP:
        destination = &content_.at(GetIndex(head_x, head_y - 1, width_));
        break;
    case Direction::DOWN:
        destination = &content_.at(GetIndex(head_x, head_y + 1, width_));
        break;
    case Direction::LEFT:
        destination = &content_.at(GetIndex(head_x - 1, head_y, width_));
        break;
    case Direction::RIGHT:
        destination = &content_.at(GetIndex(head_x + 1, head_y, width_));
        break;
    case Direction::NONE:
        break;
    }

    content_.at(GetIndex(head_x, head_y, width_)) = Pixel(head_x, head_y, PixelType::SNAKE_BODY_CHAR);
    
    if (destination->GetType_() == PixelType::SNAKE_BODY_CHAR || destination->GetType_() == PixelType::BORDER_CHAR)
        return true; //Collision occured

    grow = tail_y == food_.GetY_() && tail_x==food_.GetX_();

    if (grow) {
        int x, y;
        do {
            x = RandomCoord(2, width_ - 2);
            y = RandomCoord(2, height_ - 2);
            destination = &content_.at(GetIndex(x, y, width_));
        } while (destination->GetType_() != PixelType::EMPTY);
        food_.SetPos_(x, y);//move food
        content_.at(GetIndex(x, y, width_)) = Pixel(x,y,PixelType::FOOD_CHAR);
    }else
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

int Board::GetWidth_() const
{
    return width_;
}

int Board::GetHeight_() const
{
    return height_;
}
