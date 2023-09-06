#pragma once
#include <curses.h>
#include <time.h>
#include "../Drawable/Food/Food.h"
#include "../Drawable/Empty/Empty.h"
#include "../Board/Board.h"
#include "../Drawable/Snake/Snake.h"
#include "../Score/Scoreboard.h"

class Game
{
    Board board;
    bool game_over;
    Food* food;
    Snake snake;

    Scoreboard scoreboard;
    int score;

    void createFood();

    void handleNextPiece(SnakePiece next);

    void eatFood();

public:
    Game(int height, int width, int speed);

    ~Game();

    void initialize();

    void processInput();

    void updateState();

    void redraw();

    bool isOver();

    int getScore();
};