#pragma once
#include <curses.h>
#include <queue>
#include "./SnakePiece/SnakePiece.h"

enum Direction
{
    up = -1,
    down = 1,
    left = -2,
    right = 2
};

class Snake
{
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;

public:
    Snake();

    void addPiece(SnakePiece piece);

    void removePiece();

    SnakePiece tail();

    SnakePiece head();

    Direction getDirection();

    void setDirection(Direction d);

    SnakePiece nextHead();
};