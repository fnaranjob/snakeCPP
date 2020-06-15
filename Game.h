#ifndef __GAME_H__
#define __GAME_H__
#include "olcConsoleGameEngine.h"
#include "board.h"

class Game : public olcConsoleGameEngine
{

private:
	Board board_;
	float update_time_;
public:
	Game(size_t width, size_t height): board_(width,height), update_time_{ 0.0 } {
		ConstructConsole(width, height, 10, 10);
	};
	void DrawBoard_(){
		size_t i{ 0 };
		COLOUR render_color;
		for (const auto pix : board_.GetContent_()) {
			render_color = GetColor(pix.GetType_());
			Draw(i%board_.GetWidth_(),i/board_.GetWidth_(),static_cast<char>(pix.GetType_()),render_color);
			i++;
		};
	};
	virtual bool OnUserCreate() {
		return true;
	}
	virtual bool OnUserUpdate(float fEnlapsedTime) {
		update_time_ += fEnlapsedTime;
		if (update_time_ >= 0.2){
			board_.Update_(Direction::RIGHT);
			DrawBoard_();
			update_time_ = 0;
		}
			
		return true;
	}

};

#endif