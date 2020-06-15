#include "utils.h"


size_t RandomCoord(size_t min, size_t max){
    return static_cast<size_t>(rand()%(max-min+1) + min);
}

size_t GetIndex(size_t x, size_t y, size_t w){
    return (y-1)*w+x-1;
}