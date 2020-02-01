#include "pattern.h"
#include <windows.h>
#include <iostream>

Board::Board(): _width(15), _height(15) {
    boarden = "\
+-------------------------------+\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|-------------------------------|\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|-------------------------------|\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|-------------------------------|\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
|       |       |       |       |\n\
+-------------------------------+\n\
        use wasd to control";
}

void Board::draw() {
    COORD co;
    co.X = 0;
    co.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
    std::cout << boarden;
}

Cell::Cell() {
    _cols = 4;
    _rows = 4;

    _value = new int*[_rows];
    for (int j = 0; j < _rows; j++) {
        _value[j] = new int[_cols];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j ++) {
            _value[i][j] = 0;
        }
    }
}

Cell::Cell(int cols, int rows): _cols(cols), _rows(rows) {
    _value = new int*[_rows];
    for (int j = 0; j < _rows; j++) {
        _value[j] = new int[_cols];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j ++) {
            _value[i][j] = 0;
        }
    } 
}

Cell::~Cell() {
    for (int i = 0; i < _rows; i++) {
        delete []_value[i];
    }
    delete []_value;
}

void Cell::move(Command command) {
    switch(command) {
        case Up: {
            for (int x = 0; x < _cols; x++) {
                for (int y = 0; y < _rows; y++) {
                    if (_value[y][x]) continue;
                    for (int z = y+1; z < _rows; z++) {
                        if (_value[z][x]) {
                            _value[y][x] = _value[z][x];
                            _value[z][x] = 0;
                            break;
                        }
                    }
                }
            }
        }
        case Down: {
            for (int x = 0; x < _cols; x++) {
                for (int y = _rows-1; y >= 0; y--) {
                    if (_value[y][x]) continue;
                    for (int z = y-1; z >= 0; z--) {
                        if (_value[z][x]) {
                            _value[y][x] = _value[z][x];
                            _value[z][x] = 0;
                            break;
                        }
                    }
                }
            }   
        }
        case Left: {
            for (int y = 0; y < _rows; y++) {
                for (int x = 0; x < _cols; x++) {
                    if (_value[y][x]) continue;
                    for (int z = x+1; z < _cols; z++) {
                        if (_value[z][x]) {
                            _value[y][x] = _value[z][x];
                            _value[z][x] = 0;
                            break;
                        }
                    }
                }
            }
        }
        case Right: {
            for (int y = 0; y < _rows; y++) {
                for (int x = _cols-1; x >= 0; x--) {
                    if (_value[y][x]) continue;
                    for (int z = x-1; z >= 0; z--) {
                        if (_value[z][x]) {
                            _value[y][x] = _value[z][x];
                            _value[z][x] = 0;
                            break;
                        }
                    }
                }
            }   
        }
    }
}

bool Cell::checkFull() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            if (_value[i][j] == 0) return false;
        }
    }

    Command commands[4] = {Up, Down, Left, Right};

    int tempSave[_rows][_cols];
    exportMat(tempSave);

    for (int i = 0; i < 4; i++) {
        move(commands[i]);
        for (int k = 0; k < _rows; k++) {
            for (int j = 0; j < _cols; j++) {
                if (_value[i][j] == 0) return false;
            }
        }
        importMat(tempSave);
    }

    importMat(tempSave);
    return true;    
}

void Cell::exportMat (int (&save)[4][4]) {
    for (int y = 0; y < _rows; y++) {
        for (int x = 0; x < _cols; x++) {
            save[y][x] = _value[y][x];
        }
    }
}

void Cell::importMat(const int (&mat)[4][4]) {
    for (int y = 0; y < _rows; y++) {
        for (int x = 0; x < _cols; x++) {
            _value[y][x] = mat[y][x];
        }
    }   
}