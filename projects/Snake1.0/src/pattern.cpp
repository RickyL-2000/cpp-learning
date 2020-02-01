#include "pattern.h"
#include <windows.h>
#include <iostream>

Snake::Snake() {
    _len = 2;
    _pos[0][0] = 5;
    _pos[0][1] = 6;
    _pos[1][0] = 5;
    _pos[1][1] = 7;
    _dir = Up;
}

int Snake::getX(int index) {
    // if (index >= _len) 
    return _pos[index][0];
}

int Snake::getY(int index) {
    // if (index >= _len)
    return _pos[index][1];
}

void Snake::draw() {
    for (int i = 0; i < _len; i++) {
        COORD co;
        co.X = _pos[i][0] * 2 + 1;  // TODO: why?
        co.Y = _pos[i][1] + 1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);

        if (i == 0) printf("◇");
        else printf("□");
    }
}

void Snake::tryEat(Food& food) {
    if (_pos[0][0] != food.X() && _pos[0][1] != food.Y()) return;

    food.prod(*this);
    _len++;     // @bug
}

Food::Food(Snake& snake) {
    while(true) {
        _x = rand() % 14 + 1;
        _y = rand() % 14 + 1;
        
        bool isCoincide = false;
        for (size_t i = 0; i < snake.getLen(); i++) {
            if (snake.getX(i) == _x && snake.getY(i) == _y) {
                isCoincide = true;
                break;
            }
        }
        if (!isCoincide) break;
    }
}

void Food::prod(Snake& snake) {
    while(true) {
        _x = rand() % 14 + 1;
        _y = rand() % 14 + 1;
        
        if (!checkCoinc(snake)) break;
    }
}

void Food::draw() {
    COORD co;
    co.X = _x * 2 + 1;
    co.Y = _y + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
    printf("o");
}

bool Food::checkCoinc(Snake& snake) {
    for (size_t i = 0; i < snake.getLen(); i++) {
        if (snake.getX(i) == _x && snake.getY(i) == _y) {
            return true;
        }
    }
    return false;
}