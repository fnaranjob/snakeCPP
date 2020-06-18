#include "utils.h"


int RandomCoord(int min, int max){
    return static_cast<int>(rand()%(max-min+1) + min);
}

int GetIndex(int x, int y, int w){
    return y*w+x;
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
