#include "board.h"
#include <iostream>

Board::Board(int w, int h)
    :width{w}, height{h}
{
    content.reserve(width*height);
    std::cout<<"Board constructed"<<std::endl;
}

void Board::display() const{

}
