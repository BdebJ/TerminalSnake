#include "Drawable.h"

Drawable::Drawable()
{
    y = x = 0;
    icon = ' ';
}

Drawable::Drawable(int y, int x, chtype ch)
{
    this->y = y;
    this->x = x;
    this->icon = ch;
}

int Drawable::getX()
{
    return x;
}

int Drawable::getY()
{
    return y;
}

chtype Drawable::getIcon()
{
    return icon;
}