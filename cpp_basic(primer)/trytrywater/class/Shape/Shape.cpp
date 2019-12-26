#include <iostream>

class Shape{
protected:
    double width, height;
public:
    // default constructor
    Shape() {width = 1; height = 1;}
    Shape(double a, double b) {width = a; height = b;}
    virtual ~Shape();   // destructor
    virtual double area() {std::cout << "Base area unknown" << std::endl;}
    virtual void draw();
};

// inherity
class Rectangle : public Shape{
public:
    Rectangle(double a, double b) : Shape(a, b) {}

};