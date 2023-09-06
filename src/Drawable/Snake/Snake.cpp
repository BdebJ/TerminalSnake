#include "Snake.h"

Snake::Snake()
{
    cur_direction = down;
}

void Snake::addPiece(SnakePiece piece)
{
    prev_pieces.push(piece);
}

void Snake::removePiece()
{
    prev_pieces.pop();
}

SnakePiece Snake::tail()
{
    return prev_pieces.front();
}

SnakePiece Snake::head()
{
    return prev_pieces.back();
}

Direction Snake::getDirection()
{
    return cur_direction;
}

void Snake::setDirection(Direction d)
{
    if (cur_direction + d)
        cur_direction = d;
}

SnakePiece Snake::nextHead()
{
    int row = head().getY();
    int col = head().getX();

    switch (cur_direction)
    {
    case down:
        row++;
        break;
    case up:
        row--;
        break;
    case left:
        col--;
        break;
    case right:
        col++;
        break;
    }

    return SnakePiece(row, col);
}