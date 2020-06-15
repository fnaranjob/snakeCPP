#include "utils.h"


size_t RandomCoord(size_t min, size_t max){
    return static_cast<size_t>(rand()%(max-min+1) + min);
}

size_t GetIndex(size_t x, size_t y, size_t w){
    return (y-1)*w+x-1;
}

COLOUR GetColor(PixelType p_type)
{
	COLOUR foreground_color;
	COLOUR background_color = COLOUR::BG_DARK_BLUE;
	switch (p_type) {
		case PixelType::EMPTY:
		case PixelType::BORDER_CHAR:
			foreground_color = COLOUR::FG_WHITE;
			break;
		case PixelType::FOOD_CHAR:
			foreground_color = COLOUR::FG_RED;
			break;
		case PixelType::SNAKE_BODY_CHAR:
		case PixelType::SNAKE_HEAD_CHAR:
			foreground_color = COLOUR::FG_GREEN;
	}
	
    return static_cast<COLOUR>(background_color + foreground_color);
}
