#include <iostream>
using namespace std;



void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}


template<class T>
class vector {
    T* data;
    int size;
public:
    vector() {
        data = nullptr;
        size = 0;
    }

    //vector(int size) { // 10
    //    // this->data = new int[size];
    //    for (int i = 0; i < size; i++)
    //        add_element_end(rand() % 101 - 50);
    //}

    vector(const vector<T>& other) {
        this->data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
            // *(this->data + i) = *(other.data + i);
        }
    }



    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i);
        line(100);
    }

    void add_element_end(T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    int getSize() const {
        return size;
    }



    void add_element_start(T number) {
        T* p = new T[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    vector operator=(const vector& other) {
        if (this == &other) return *this;
        if (this->data) delete[] this->data;
        this->data = new T[other.size];
        for (int i = 0; i < other.size; i++) this->data[i] = other.data[i];
        this->size = other.size;
        return *this;
    }

    T& getElementByIndex(unsigned int index) {
        if (index >= this->size) throw exception("Index out of range");
        return data[index];
    }

    T& operator[](unsigned int index) const {
        if (index >= this->size) throw exception("Index out of range");
        return data[index];
    }


    ~vector() {
        delete[] data;
    }
};

template<class T>
ostream& operator<<(ostream& os, const vector<T>& obj) {
    line(100);
    for (int i = 0; i < obj.getSize(); i++) os << obj[i] << " ";
    line(100);
    os << endl;
    return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& obj) {
    for (int i = 0; i < obj.getSize(); i++) is >> obj[i];
    return is;
}



template<class T>
class point {

    T x, y, z;

public:

    point() { x = y = z = 0; }
    point(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    template<class T>
    friend double distance(point<T> p1, point<T> p2);

    void print() const {
        cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl;
    }
};

template<class T>
double distance(point<T> p1, point<T> p2) {
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)) + ((p1.z - p2.z) * (p1.z - p2.z)));
}

template<class T>
ostream& operator<<(ostream& os, const point<T> obj) {
    obj.print();
    return os;
}



int main() {

    //vector<int> v;
    //v.add_element_end(100);
    //v.add_element_end(500);
    //v.add_element_end(300);
    //v.add_element_end(400);
    //v.add_element_end(200);

    //cout << v;

    ///*v.getElementByIndex(2) = 1000;*/
    //v[2] = 600;

    //cout << v;

    //cin >> v;

    //cout << v;

    //vector<double> v2;
    //v2.add_element_end(5.34);
    //v2.add_element_end(3.7);
    //v2.add_element_end(21.643);
    //v2.add_element_end(9.6);
    //v2.add_element_end(0.1);

    //cout << v2;

    ///*v.getElementByIndex(2) = 1000;*/
    //v2[2] = 78.32;

    //cout << v2;

    //cin >> v2;

    //cout << v2;

    vector<point<int>> points;
    points.add_element_end(point<int>(3, 4, 5));
    points.add_element_end(point<int>(9, 3, 7));
    points.add_element_end(point<int>(-3, 1, 9));
    points.add_element_end(point<int>(-11, 4, 1));
    points.add_element_end(point<int>(7, 1, 4));

    points.print();



	return 0;
}