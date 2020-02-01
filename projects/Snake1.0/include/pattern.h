#ifndef PATTERN_H
#define PATTERN_H

#include "general.h"

class Food;

class Snake {
private:
    int _pos[255][2];
    int _len;
    int _dir;

public:
    Snake();
    int getX(int index);
    int getY(int index);
    int getLen() const {return _len;}

    void draw();

    /**
     * move towards a direction, clear the last part of the body 
     */
    void move(Command command);

    /**
     * check if eat the food, grow or skip 
     */
    void tryEat(Food& food);

    /**
     * change the direction according to kb 
     */
    void changeDirection();

    /**
     * @return true if ate itself
     */
    bool checkEatSelf();
    /**
     * @return true if hit wall 
     */
    void checkHitWall();
};

class Food {
private:
    int _x;
    int _y;
public:
    Food(Snake& snake);
    int X() {return _x;}
    int Y() {return _y;}
    void prod(Snake& snake);
    void draw();
    /**
     * @return true if coincide 
     */
    bool checkCoinc(Snake& snake);
};

// class Obstacle {};

#endif