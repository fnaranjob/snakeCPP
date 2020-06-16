#ifndef __GAME_H__
#define __GAME_H__
#include "olcConsoleGameEngine.h"
#include "board.h"
#include <string>

class Game : public olcConsoleGameEngine
{

private:
	Board board_;
	float accum_time_;
	float update_time_;
	Direction current_dir_;
	bool game_over_;

public:
	Game(size_t width, size_t height) : board_(width, height), accum_time_{ 0.0 }, update_time_{ 0.4 },current_dir_{ Direction::NONE } {
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
		accum_time_ += fEnlapsedTime;

		//Input processing
		if (m_keys[VK_UP].bHeld)
			current_dir_ = Direction::UP;
		else if (m_keys[VK_LEFT].bHeld)
			current_dir_ = Direction::LEFT;
		else if (m_keys[VK_RIGHT].bHeld)
			current_dir_ = Direction::RIGHT;
		else if (m_keys[VK_DOWN].bHeld)
			current_dir_ = Direction::DOWN;

		//Display update
		if (accum_time_ >= update_time_){
			game_over_=board_.Update_(current_dir_);
			if (!game_over_)
				DrawBoard_();
			else
				Fill(1, 1, board_.GetWidth_() - 1, board_.GetHeight_() - 1, 'X');
			accum_time_ = 0;
		}
			
		return true;
	}

};

#endif