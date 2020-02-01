#ifndef PATTERN_H
#define PATTERN_H

#include <string>
#include "general.h"

class Board {
private:
    int _width;
    int _height;
    std::string boarden;
public:
    Board();
    int width() const {return _width;}
    int height() const {return _height;}
    // Board(int wid, int hei): _width(wid), _height(hei) {}
    void draw();
};

class Cell {
private:
    int _cols;
    int _rows;
    int** _value;
public:
    Cell();
    Cell(int cols, int rows);
    ~Cell();

    /**
     * move at one direction 
     */
    void move(Command command);

    /**
     * @return true if full 
     */
    bool checkFull();

    void exportMat (int (&save)[4][4]);
    void importMat(const int (&mat)[4][4]);

    void draw();

    void generate();
};

#endif