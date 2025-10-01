#include <iostream>
using namespace std;

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}


class vector {
    int* data;
    int size;
public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(int size) { // 10
        // this->data = new int[size];
        for (int i = 0; i < size; i++)
            add_element_end(rand() % 101 - 50);
    }

    vector(const vector& other) {
        this->data = new int[other.size];
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
            cout << *(data + i) << " ";
        line(100);
    }

    void add_element_end(int number) {
        int* p = new int[size + 1];

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



    void add_element_start(int number) {
        int* p = new int[size + 1];

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
        this->data = new int[other.size];
        for (int i = 0; i < other.size; i++) this->data[i] = other.data[i];
        this->size = other.size;
        return *this;
    }

    int& getElementByIndex(unsigned int index) {
        if (index >= this->size) throw exception("Index out of range");
        return data[index];
    }

    int& operator[](unsigned int index) const {
        if (index >= this->size) throw exception("Index out of range");
        return data[index];
    }


    ~vector() {
        delete[] data;
    }
};

ostream& operator<<(ostream& os, const vector& obj) {
    line(100);
    for (int i = 0; i < obj.getSize(); i++) os << obj[i] << " ";
    line(100);
    os << endl;
    return os;
}

istream& operator>>(istream& is, vector& obj) {
    for (int i = 0; i < obj.getSize(); i++) is >> obj[i];
    return is;
}




//void set_array(int* arr, int size) {
//  for (int i = 0; i < size; i++)
//    *(arr + i) = rand() % 101 - 50;
//}







int main() {
    setlocale(LC_CTYPE, "ukr");
    srand(time(0));


    /*vector v;
    v.add_element_end(100);
    v.add_element_end(200);
    v.add_element_end(300);

    v.add_element_start(50);
    v.add_element_start(78);

    v.print();*/


    /*vector v1(10);
    v1.print();

    vector v2 = v1;


    v2.print();*/

    vector v;
    v.add_element_end(100);
    v.add_element_end(500);
    v.add_element_end(300);
    v.add_element_end(400);
    v.add_element_end(200);

    cout << v;

    /*v.getElementByIndex(2) = 1000;*/
    v[2] = 600;

    cout << v;

    cin >> v;

    cout << v;



    return 0;
}