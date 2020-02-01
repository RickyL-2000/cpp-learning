#include "general.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

void Board::draw() {
    COORD co;
    co.X = 0;
    co.Y = 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);

    std::cout << _wall;
}

GameControl::GameControl() {
    _state = running;
    _diff = 500;
};

void GameControl::terminate(Board& board) {
    COORD co;
    co.X = board.W() * 3 / 2;
    co.Y = board.H() / 2;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);

    std::cout << "Game Over";
}

Command GameControl::input() {
    char ch = ' ';
    if (_kbhit()) ch = _getch();

    switch (ch) {
        case 'w': return Up;
        case 's': return Down;
        case 'a': return Left;
        case 'd': return Right;
        case 'q': return Terminate;
        case ' ': return noCommand;
    }
}