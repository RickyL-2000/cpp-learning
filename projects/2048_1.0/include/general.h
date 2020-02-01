#ifndef GENERAL_H
#define GENERAL_H

class Board;

enum Command {
    Up,
    Down,
    Left,
    Right,
    Quit,
};

enum GameState {
    running,
    gameOver,
};

class GameControl {
private:
    GameState _state;

    /**
     * score 
     */
    int _tot;
    int _max;
public:
    GameControl(): _state(running), _tot(0), _max(0) {}
    GameState state() const {return _state; }
    void gameOver(int b_width, int b_height);
    void changeState(GameState state) {_state = state;}

    /**
     * @return command from kb 
     */
    Command input();

    /**
     * show the total and max score 
     */
    void showScore();
};

#endif