#include "Scoreboard.h"

Scoreboard::Scoreboard(int width, int y, int x)
{
    score_win = newwin(1, width, y, x);
}

void Scoreboard::initialize(int initial_score)
{
    clear();
    mvwprintw(score_win, 0, 0, "Score:");
    updateScore(initial_score);
    refresh();
}

void Scoreboard::updateScore(int score)
{
    mvwprintw(score_win, 0, score_win->_maxx - 10, "%d", score);
}

void Scoreboard::clear()
{
    wclear(score_win);
}

void Scoreboard::refresh()
{
    wrefresh(score_win);
}