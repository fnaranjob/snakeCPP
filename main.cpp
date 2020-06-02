#include <iostream>
#include "board.h"
#include "utils.h"
#include <unistd.h>

int main()
{
    Board b{60,20};
    b.Display_();
    return 0;
}
