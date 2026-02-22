#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;

class Square 
{
private:
    int side;

public:
    int getSide() const;
    void setSide(int s);

    Square(); // default constructor
    Square(int s); // constructor that takes side as parameter

    double getArea() const;
    double getPerimeter() const;
};

#endif
