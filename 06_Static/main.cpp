#include <iostream>
using namespace std;

// ������� ���� �� ���� �� ���������������� ��� ��'������ �����
// ������ �� ���� �������� �� ����������� ��'���� � ����� �������

class point {

private:
    // ���, ����
    int x, y;

    // �������, ������
public:

    static int count;
    static int liveObjects;

    point() {
        x = y = 0;
        count++;
        liveObjects++;
    }

    point(int x, int y) {
        this->x = x;
        this->y = y;
        count++;
        liveObjects++;
    }


    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // ������ ��������

    // ������������
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    // ����������
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }


    void print() {
        cout << "X: " << x << ", Y:" << y << "\n";
    }

    ~point() {
        liveObjects--;
    }

};

int point::count = 0;
int point::liveObjects = 0;



int main() {

    point p1(2, 3);
    point p2(6, 1);
    point p3(0, 5);

    {
        point p4(1, 1);
    }

    cout << point::count << endl << point::liveObjects;





    return 0;
}