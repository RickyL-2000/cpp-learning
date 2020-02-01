#ifndef GENERAL_H
#define GENERAL_H

#include <string>

enum GameState {
    running,
    gameOver,
};

enum Command {
    Up,
    Down,
    Left,
    Right,
    Terminate,
    noCommand,
};

class Board {
private:
    int _width;
    int _height;
    std::string _wall;

public:
    Board() : _width(15), _height(15) {
        _wall = "\
+------------------------------+\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
+------------------------------+\n\
   type \"asdw\" to control\n\
        \"q\" to quit\
";
}

    int W() {return _width;}
    int H() {return _height;}

    void draw();
};

class GameControl {
private:
    GameState _state;

    /**
     * miliseconds 
     */
    int _diff;
public:
    GameControl();
    int state() {return _state;}
    int difficulty() {return _diff;}
    void changeState() {_state = _state == gameOver ? running : gameOver;} 
    void terminate(Board& board);
    Command input();
};

#endif