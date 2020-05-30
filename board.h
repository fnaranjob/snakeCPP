#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
private:
    const char BORDER_CHAR = '*';
    int width;
    int height;
    std::vector<int> content;
    std::pair<int,int> food_pos;
    //Snake s;

public:
    Board(int width, int height);
    void display() const;
    void reset();
};

#endif // BOARD_H
