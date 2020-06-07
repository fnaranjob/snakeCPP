#include <iostream>
#include <Windows.h>
#include "board.h"
#include "utils.h"
#include "snake.h"


int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //used for random coordinate generation
    Board b{80,20};
    b.Display_();
    b.Update_(Direction::UP);
    
    for (size_t i = 0; i < 20; i++) {
        b.Update_(Direction::LEFT);
        Sleep(100);
        b.Display_();
    }
    

    

    return 0;
}
