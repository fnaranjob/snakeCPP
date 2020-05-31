#include "utils.h"

size_t RandomCoord(size_t min, size_t max){
    srand(time(NULL));
    return static_cast<size_t>(rand()%max + min);
}

size_t GetIndex(size_t x, size_t y, size_t w){
    return (x-1)*w+y;
}
