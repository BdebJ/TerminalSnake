#pragma once
#include <curses.h>

class Scoreboard
{
    WINDOW* score_win = nullptr;
public:
    Scoreboard() {}
    Scoreboard(int width, int y, int x);

    void initialize(int initial_score);

    void updateScore(int score);

    void clear();

    void refresh();
};