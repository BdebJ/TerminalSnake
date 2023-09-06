#include "Board.h"

Board::Board()
{
    construct(0, 0, 300);
}

Board::Board(int height, int width, int speed)
{
    construct(height, width, speed);
}

void Board::construct(int height, int width, int speed)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    this->height = height;
    this->width = width;

    start_row = (yMax / 2) - (height / 2);
    start_col = (xMax / 2) - (width / 2);
    timeout = speed;

    board_win = newwin(height, width, start_row, start_col);
    setTimeout(speed);
    keypad(board_win, true);
}

void Board::initialize()
{
    clear();
    refresh();
}

void Board::addBorder()
{
    box(board_win, 0, 0);
}

void Board::add(Drawable drawable)
{
    addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
}

void Board::addAt(int y, int x, chtype ch)
{
    mvwaddch(board_win, y, x, ch);
}

chtype Board::getInput()
{
    return wgetch(board_win);
}

void Board::getEmptyCoordinates(int& y, int& x)
{
    while (mvwinch(board_win, y = rand() % height, x = rand() % width) != ' ');
}

chtype Board::getCharAt(int y, int x)
{
    return mvwinch(board_win, y, x);
}

void Board::clear()
{
    wclear(board_win);
    addBorder();
}

void Board::refresh()
{
    wrefresh(board_win);
}

void Board::setTimeout(int timeout)
{
    wtimeout(board_win, timeout);
}

int Board::getTimeout()
{
    return timeout;
}

int Board::getStartRow()
{
    return start_row;
}

int Board::getStartCol()
{
    return start_col;
}