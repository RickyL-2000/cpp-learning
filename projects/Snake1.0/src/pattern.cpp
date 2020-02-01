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

        if (i == 0) printf("S");
        else printf("D");
    }
}

void Snake::move(Command command) {
    int lastX = _pos[_len-1][0],
        lastY = _pos[_len-1][1];
    for (size_t i = _len-1; i > 0; i--) {
        _pos[i][0] = _pos[i-1][0];
        _pos[i][1] = _pos[i-1][1];
    }
    changeDirection(command);
    switch (_dir) {
        case Up: {
            _pos[0][0] = _pos[1][0];
            _pos[0][1] = _pos[1][1] - 1;
            break;
        }
        case Down: {
            _pos[0][0] = _pos[1][0];
            _pos[0][1] = _pos[1][1] + 1;
            break;
        }
        case Left: {
            _pos[0][0] = _pos[1][0] - 1;
            _pos[0][1] = _pos[1][1];
            break;
        }
        case Right: {
            _pos[0][0] = _pos[1][0] + 1;
            _pos[0][1] = _pos[1][1];
            break;
        }
    }

    // clear the last part of the body
    COORD co;
    co.X = lastX * 2 + 1;
    co.Y = lastY + 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
    printf(" ");
}

void Snake::changeDirection(Command command) {
    switch (command) {
        case Up: {
            if (_dir != Down) _dir = Up;
            break;
        }
        case Down: {
            if (_dir != Up) _dir = Down;
            break;
        }
        case Left: {
            if (_dir != Right) _dir = Left;
            break;
        }
        case Right: {
            if (_dir != Left) _dir = Right;
            break;
        }
        case Terminate:
        case noCommand: break;
    }
}

void Snake::tryEat(Food& food) {
    if (_pos[0][0] != food.X() && _pos[0][1] != food.Y()) return;

    food.prod(*this);
    _len++;     // @bug
}

bool Snake::checkEatSelf() {
    for (size_t i = 1; i < _len; i++) {
        if (_pos[i][0] == _pos[0][0] && _pos[i][1] == _pos[0][1])
            return true;
    }
    return false;
}

bool Snake::checkHitWall(Board& board) {
    if (_pos[0][0] < 0 || _pos[0][0] >= board.W() || _pos[0][1] < 0 || _pos[0][1] >= board.H()+1)
        return true;
    return false;
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