#include <iostream>
#include <curses.h>
#include "./Board/Board.h"
#include "./Game/Game.h"

constexpr int BOARD_DIM = 15;
constexpr int BOARD_ROWS = BOARD_DIM;
constexpr int BOARD_COLS = BOARD_DIM * 2;

int main()
{
    initscr();
    refresh();
    noecho();
    curs_set(0);

    Game game(BOARD_ROWS, BOARD_COLS, 500);
    while (!game.isOver())
    {
        game.processInput();
        game.updateState();
        game.redraw();
    }
    endwin();

    std::cout << "Game Over" << std::endl;
}