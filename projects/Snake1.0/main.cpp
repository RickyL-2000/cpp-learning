#include "general.h"
#include "pattern.h"
#include <iostream>

int main() {
    GameControl control;
    Board board;
    Snake snake;
    Food food(snake);

    board.draw();

    while (true) {
        if (control.state() == gameOver) {
            control.terminate(board);
            break;
        }

        Command command = control.input();
        if (command == Terminate) control.changeState();


    }

    getchar();

    return 0;
}