#include <iostream>
#include <Windows.h>
#include "board.h"
#include "utils.h"
#include "snake.h"
#include "Game.h"


int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //used for random coordinate generation
    size_t board_width{ 50 };
    size_t board_height{ 25 };
    Game G(board_width, board_height);
    G.Start();
    

    return 0;
}
