#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <stdlib.h>
#include <time.h>

//********************
//CONSTANTS
//********************

    enum class PixelType :char { SNAKE_BODY_CHAR = 'o', FOOD_CHAR = '@', SNAKE_HEAD_CHAR = 'x', BORDER_CHAR = 'X', EMPTY = ' ' };
    enum class Direction :char { NONE, UP, DOWN, LEFT, RIGHT };

    //Initial min distance from the board's border for the snake to appear when created
    const size_t kBorderInitDist = 2;

    //Initial snake length
    const size_t kInitialSnakeLen = 7;



//********************
//UTILITY FUNCTIONS
//********************


size_t RandomCoord(size_t min, size_t max);
size_t GetIndex(size_t x, size_t y, size_t w);


#endif // UTILS_H
