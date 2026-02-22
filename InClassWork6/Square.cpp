#include "Square.h"

int Square::getSide() const {
    return side;
}

void Square::setSide(int s) {
    if (s > 0)
        side = s;
    else
        cout << "Side length must be positive." << endl;
}

Square::Square() {} // default constructor

Square::Square(int s) // constructor that takes side as parameter
{ 
    setSide(s);
}

double Square::getArea() const 
{
    return side * side;
}

double Square::getPerimeter() const 
{
    return 4 * side;
}
