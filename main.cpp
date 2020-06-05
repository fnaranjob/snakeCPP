#include <iostream>
#include <unistd.h>
#include "board.h"
#include "utils.h"
#include "snake.h"


int main()
{
    srand(time(NULL)); //used for random coordinate generation
    Board b{50,20};
    b.Display_();

    return 0;
}
