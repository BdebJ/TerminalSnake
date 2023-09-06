#include "Game.h"

Game::Game(int height, int width, int speed = 300)
{
    board = Board(height, width, speed);

    int sb_row = board.getStartRow() + height;
    int sb_col = board.getStartCol();
    scoreboard = Scoreboard(width, sb_row, sb_col);
    initialize();
}

Game::~Game()
{
    delete food;
    food = nullptr;
}

void Game::createFood()
{
    int y, x;
    board.getEmptyCoordinates(y, x);
    food = new Food(y, x);
    board.add(*food);
}

void Game::handleNextPiece(SnakePiece next)
{
    if (food != nullptr)
    {
        switch (board.getCharAt(next.getY(), next.getX()))
        {
        case FOOD_ICON:
            eatFood();
            break;
        case ' ':
        {
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow, emptyCol));
            snake.removePiece();
            break;
        }
        default:
            game_over = true;
            break;
        }
    }
    board.add(next);
    snake.addPiece(next);
}

void Game::eatFood()
{
    delete food;
    food = nullptr;
    score += 100;
    scoreboard.updateScore(score);
}

void Game::initialize()
{
    food = nullptr;
    board.initialize();

    score = 0;
    scoreboard.initialize(score);
    game_over = false;
    srand(time(NULL));

    snake.setDirection(down);

    handleNextPiece(SnakePiece(1, 1));
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());
    snake.setDirection(right);
    handleNextPiece(snake.nextHead());

    if (food == nullptr)
    {
        createFood();
    }
}

void Game::processInput()
{
    chtype input = board.getInput();

    int old_timeout = board.getTimeout();
    switch (input)
    {
    case KEY_UP:
    case 'w':
        snake.setDirection(up);
        break;
    case KEY_DOWN:
    case 's':
        snake.setDirection(down);
        break;
    case KEY_RIGHT:
    case 'd':
        snake.setDirection(right);
        break;
    case KEY_LEFT:
    case 'a':
        snake.setDirection(left);
        break;
    case 'p':
        board.setTimeout(-1);
        while (board.getInput() != 'p');
        board.setTimeout(old_timeout);
        break;
    default:
        break;
    }
}

void Game::updateState()
{
    handleNextPiece(snake.nextHead());
    if (food == nullptr)
    {
        createFood();
    }
}

void Game::redraw()
{
    board.refresh();
    scoreboard.refresh();
}

bool Game::isOver()
{
    return game_over;
}

int Game::getScore()
{
    return score;
}

