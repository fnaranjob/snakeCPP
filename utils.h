#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <stdlib.h>
#include <time.h>

//********************
//CONSTANTS
//********************

namespace color_codes {
    const std::string kReset{"\033[0m"};
    const std::string kBlack{"\033[30m"};
    const std::string kRed{"\033[31m"};
    const std::string kGreen{"\033[32m"};
    const std::string kYellow{"\033[33m"};
    const std::string kBlue{"\033[34m"};
    const std::string kMagenta{"\033[35m"};
    const std::string kCyan{"\033[36m"};
    const std::string kWhite{"\033[37m"};
}


    enum class PixelType :char { SNAKE_BODY_CHAR = 'o', FOOD_CHAR = '@', SNAKE_HEAD_CHAR = 'x', BORDER_CHAR = 'X', EMPTY = ' ' };
    enum class Direction :char { NONE, UP, DOWN, LEFT, RIGHT };
    const std::string kBorderColor = color_codes::kBlue;
    const std::string kFoodColor = color_codes::kRed;
    const std::string kSnakeColor = color_codes::kGreen;

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
