#pragma once
#include <curses.h>
#include <stdlib.h>
#include "../Drawable/Drawable.h"

class Board
{
    WINDOW* board_win;
    int height, width, start_row, start_col;
    int timeout;

    void construct(int height, int width, int speed);
public:
    Board();

    Board(int height, int width, int speed);

    void initialize();

    void addBorder();

    void add(Drawable drawable);

    void addAt(int y, int x, chtype ch);

    chtype getInput();

    void getEmptyCoordinates(int& y, int& x);

    chtype getCharAt(int y, int x);

    void clear();

    void refresh();

    void setTimeout(int timeout);

    int getTimeout();

    int getStartRow();

    int getStartCol();
};