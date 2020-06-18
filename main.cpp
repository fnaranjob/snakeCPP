#include "board.h"
#include "utils.h"
#include "snake.h"
#include "Game.h"


int main()
{
    srand(static_cast<unsigned int>(time(NULL))); //used for random coordinate generation
    int board_width{ 30 };
    int board_height{ 30 };
    Game G(board_width, board_height);
    G.Start();
    

    return 0;
}
