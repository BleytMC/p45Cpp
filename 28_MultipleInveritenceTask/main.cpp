#include <iostream>
#include <string>
using namespace std;

class circle {
    float radius;
public:
    circle(int radius) {
        this->radius = radius;
    }

    float perimeter() {
        return 2 * 3.14 * radius;
    }

    float are() {
        return 3.14 * radius * radius;
    }
};

class square {
    float side;
public:
    square(int side) {
        this->side = side;
    }

    float perimeter() {
        return side * 4;
    }

    float area() {
        return side * side;
    }
};

class circleInSquare : public circle, public square {
public:
    circleInSquare(int radius, int side) : circle(radius), square(side) {

    }
};

int main() {



    return 0;
}