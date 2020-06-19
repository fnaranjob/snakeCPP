#ifndef __GAME_H__
#define __GAME_H__
#include "olcConsoleGameEngine.h"
#include "board.h"

class Game : public olcConsoleGameEngine
{

private:
	Board board_;
	float accum_time_;
	float update_time_;
	Direction travel_dir_;
	bool game_over_;

public:
	Game(int width, int height) : board_(width, height), accum_time_{ 0.0 }, update_time_{ 0.1 },travel_dir_{ Direction::NONE } {
		ConstructConsole(width, height, 15, 20);
	};
	void DrawBoard_(){
		int i{ 0 };
		COLOUR render_color;
		for (const auto pix : board_.GetContent_()) {
			//if food is inside snake, paint snake element with food color
			if(pix.GetType_()==PixelType::SNAKE_BODY_CHAR && pix.GetX_()==board_.GetFood_().GetX_() && pix.GetY_()==board_.GetFood_().GetY_())
				render_color = GetColor(PixelType::FOOD_CHAR);
			else
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
		if (m_keys[VK_UP].bHeld && travel_dir_ != Direction::DOWN)
			travel_dir_ = Direction::UP;
		else if (m_keys[VK_LEFT].bHeld && travel_dir_ != Direction::RIGHT)
			travel_dir_ = Direction::LEFT;
		else if (m_keys[VK_RIGHT].bHeld && travel_dir_ != Direction::LEFT)
			travel_dir_ = Direction::RIGHT;
		else if (m_keys[VK_DOWN].bHeld && travel_dir_ != Direction::UP)
			travel_dir_ = Direction::DOWN;
		else if (m_keys[VK_SPACE].bHeld)
			travel_dir_ = Direction::NONE;

		//Display update
		if (accum_time_ >= update_time_){
			game_over_=board_.Update_(travel_dir_);
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