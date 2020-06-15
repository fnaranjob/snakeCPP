#ifndef __GAME_H__
#define __GAME_H__
#include "olcConsoleGameEngine.h"
#include "board.h"

class Game : public olcConsoleGameEngine
{

private:
	Board board_;
public:
	Game(size_t width, size_t height): board_(width,height) {
		ConstructConsole(width, height,8,10);
	};
	void DrawBoard_(){
		size_t i{ 0 };
		for (const auto pix : board_.GetContent_()) {
			Draw(i%board_.GetWidth_(),i/board_.GetWidth_(),static_cast<char>(pix.GetType_()));
			i++;
		};
	};
	virtual bool OnUserCreate() {
		return true;
	}
	virtual bool OnUserUpdate(float fEnlapsedTime) {
		DrawBoard_();
		return true;
	}

};

#endif