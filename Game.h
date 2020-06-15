#ifndef __GAME_H__
#define __GAME_H__
#include "olcConsoleGameEngine.h"
#include "board.h"

class Game : public olcConsoleGameEngine
{

private:
	Board board_;
	float update_time_;
	Direction current_dir_;
public:
	Game(size_t width, size_t height) : board_(width, height), update_time_{ 0.0 }, current_dir_{ Direction::NONE } {
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
		if (m_keys[VK_UP].bHeld)
			current_dir_ = Direction::UP;
		else if (m_keys[VK_LEFT].bHeld)
			current_dir_ = Direction::LEFT;
		else if (m_keys[VK_RIGHT].bHeld)
			current_dir_ = Direction::RIGHT;
		else if (m_keys[VK_DOWN].bHeld)
			current_dir_ = Direction::DOWN;

		if (update_time_ >= 0.2){
			board_.Update_(current_dir_);
			DrawBoard_();
			update_time_ = 0;
		}
			
		return true;
	}

};

#endif