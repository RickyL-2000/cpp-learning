#include "general.h"
#include "pattern.h"
#include <iostream>
#include <windows.h>

int main() {
    GameControl control;
    Board board;
    Snake snake;
    Food food(snake);

    board.draw();

    while (true) {
        snake.draw();
        food.draw();

        // getchar();

        if (control.state() == gameOver) {
            control.terminate(board);
            break;
        }

        Command command = control.input();
        if (command == Terminate) {
            control.changeState();
            continue;
        }

        snake.move(command);
        snake.tryEat(food);

        if (snake.checkEatSelf()) control.changeState();

        if (snake.checkHitWall(board)) control.changeState();

        Sleep(control.difficulty());

    }

    getchar();

    return 0;
}