#pragma once
#include <curses.h>
#include "../../Drawable.h"

constexpr chtype SNAKE_HEAD_ICON = '@';
constexpr chtype SNAKE_BODY_ICON = '#';

class SnakePiece : public Drawable
{
public:
    SnakePiece(int y, int x, chtype icon = SNAKE_BODY_ICON);
};