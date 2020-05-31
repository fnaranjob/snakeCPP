#include <iostream>
#include "board.h"
#include "utils.h"
#include <unistd.h>

int main()
{
    Board b{60,20};
    b.Display_();
    for(int i=2;i<20;i++){
        b.PlaceFood_(i,i);
        sleep(1);
        b.Display_();
    }
    return 0;
}
