#include "general.h"
#include "pattern.h"
#include <iostream>

int main() {
    GameControl control;
    Board board;

    while (true) {
        if (control.state() == gameOver) break;
        board.draw();

        Command command = control.input();
        if (command == Quit) {
            control.changeState(gameOver);
            continue;
        }
    }

    control.gameOver(board.width(), board.height());

    getchar();
    return 0;
}