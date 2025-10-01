#include <iostream>
#include <iomanip>
using namespace std;


#define ROWS 4
#define COLS 3



class matrix {


    int data[ROWS][COLS] = {
        {10, 2, 4},
        {-3, 12, 4},
        {10, 55, 51},
        {-2, 2, 5},
    };

public:

    void print() const {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << setw(5) << data[i][j];
            }
            cout << endl;
        }
    }

    int& operator()(unsigned int row, unsigned int col) {
        if (row >= ROWS || col >= COLS) throw exception("Index out of range");
        return data[row][col];
    }


};





class myClass {
    double x;
public:

    myClass() {
        x = 0;
    }

    myClass(double x) {
        this->x = x;
    }

    /*myClass operator+(const myClass& other) {
        myClass res;
        res.x = this->x + other.x;
        return res;
    }*/

    void print() const {
        cout << "x: " << x << "\n";
    }

    double getX() const {
        return this->x;
    }

    void setX(double x) {
        this->x = x;
    }

    operator int() {
        return (int)x;
    }
};

myClass operator+(const myClass& a, const myClass& b) {
    return myClass(a.getX() + b.getX());
}

myClass operator-(const myClass& a, const myClass& b) {
    return myClass(a.getX() - b.getX());
}

bool operator==(const myClass& a, const myClass& b) {
    return a.getX() == b.getX();
}

bool operator!=(const myClass& a, const myClass& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const myClass& obj) {
    os << obj.getX() << "\n";
    return os;
}

istream& operator>>(istream& is, myClass& obj) {
    double x;
    is >> x;
    obj.setX(x);
    return is;
}




int main() {

    /*myClass a(5);
    myClass b(4);

    myClass res = a - b;

    res.print();*/

    /*matrix m;

    m(2, 1) = 2000;

    m.print();*/

    myClass obj;

    //obj.print();

    cin >> obj;

    cout << obj;
    cout << (int)obj;



    return 0;
}