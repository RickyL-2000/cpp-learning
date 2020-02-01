#include "general.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

void GameControl::gameOver(int b_width, int b_height) {
    COORD co;
    co.X = b_width - 3;
    co.Y = b_height / 2 + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
    std::cout << "Game Over!";
}

Command GameControl::input() {
    char ch = ' ';
    if (_kbhit()) ch = _getch();

    switch(ch) {
        case 'w': return Up;
        case 's': return Down;
        case 'a': return Left;
        case 'd': return Right;
        case 'q': return Quit;
    }
}