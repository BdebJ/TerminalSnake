#pragma once
#include <curses.h>
#include "../Drawable.h"

constexpr chtype FOOD_ICON = 'O';

class Food : public Drawable
{
public:
    Food(int y, int x);
};