#include <iostream>
#include "board.h"
#include "utils.h"
#include "snake.h"


int main()
{
    srand(time(NULL)); //used for random coordinate generation
    Board b{80,20};
    b.Display_();

    return 0;
}
