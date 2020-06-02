#include <iostream>
#include <unistd.h>
#include "board.h"
#include "utils.h"
#include "snake.h"


int main()
{
    Board b{60,20};
    Pixel food{30,30,FOOD_CHAR};
    Snake s{10,10,food,15};
    b.Display_();
    return 0;
}
