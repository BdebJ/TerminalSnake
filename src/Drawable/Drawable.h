#pragma once
#include <curses.h>

class Drawable
{
protected:
    int y, x;
    chtype icon;

public:
    Drawable();

    Drawable(int y, int x, chtype ch);

    int getX();

    int getY();

    chtype getIcon();
};

