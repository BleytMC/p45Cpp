#include <iostream>
#include <string>
using namespace std;


// Черга - ДСД, яка містить набір еелментів, доступ до яких 
// відюувається за принципом FIFO(First In First Out),
// тобто додавання нового елемента відбувається з кінця, а видалення вже існуючих елементів
// відбувається з початку черги.


void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

template<class T>
class vector {
private:
    T* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(int size) {
        for (int i = 0; i < size; i++)
            add_element_end(rand() % 101 - 50);
    }

    vector(const vector& other) {
        this->data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    void print_v() const {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    void set_random(int size) {
        for (int i = 0; i < size; i++) {
            add_element_end(rand() % 101 - 50);
        }
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

    void add_element_need(int wher, T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < wher; i++) {
            p[i] = data[i];
        }

        p[wher] = number;

        for (int i = wher; i < size; i++) {
            p[i + 1] = data[i];
        }

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void deletee_element_last() {
        size--;
        T* p = new T[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        T* p = new T[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        T* p = new T[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != position) {
                p[j++] = data[i];
            }
        }

        delete[] data;
        data = p;
        size--;
        p = nullptr;
    }

    int search_element_position(T element) {
        for (int i = 0; i < size; i++)
            if (data[i] == element)
                return i;
        return -1;
    }

    void delete_search_element(T element) {
        int position = search_element_position(element);
        if (position != -1)
            delete_element_position(position);
    }
    void delete_elements_from_position(int count, int position) {
        for (int i = 0; i < count; i++)
            delete_element_position(position);
    }

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void change_element_by_value(T number, T change_number) {
        int position = search_element_position(number);
        if (position != -1)
            data[position] = change_number;
    }

    void change_element_by_position(int position, T change_number) {
        data[position] = change_number;
    }

    void reverse_array() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    T get_max() {
        if (size == 0) return 0;
        T max_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max_val)
                max_val = data[i];
        return max_val;
    }

    T get_min() {
        if (size == 0) return 0;
        T min_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min_val)
                min_val = data[i];
        return min_val;
    }

    int get_size() const {
        return size;
    }

    T get_element(int index) {
        if (index < 0 || index >= size) return 0;
        return data[index];
    }

    void sort_asc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void sort_desc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] < data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    vector operator=(const vector& other) {
        if (this == &other)
            return *this;

        if (this->data) {
            delete[] this->data;
        }
        this->data = new T[other.size];

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;

        return *this;
    }

    T& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }
    T& operator[](unsigned int index) const {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    bool isEmpty() const {
        return size == 0;
    }


    ~vector() {
        delete[] data;
    }
};

template<class T>
ostream& operator<< (ostream& os, const vector<T>& obj) {
    obj.print_v();
    return os;
}

template<class T>
istream& operator>> (istream& is, vector<T>& obj) {
    obj.set_random(10);
    return is;
}

class ringQueue {
    vector<int> data;
public:

    void push(int value) {
        data.add_element_end(value);
    }

    void print() const {
        data.print_v();
    }

    bool isEmpty() const {
        return data.isEmpty();
    }

    int top() const {
        if (!isEmpty()) return data[0];
        throw exception("Queue is empty");
    }

    int pop() {
        if (!isEmpty()) {
            int buf = data[0];
            data.deletee_element_first();
            data.add_element_end(buf);
            return buf;
        }
        throw exception("Queue is empty");
    }

    void clear() {
        data.delete_array();
    }

    vector<int> getData() {
        return data;
    }

};

void printWheel(vector<ringQueue>  rArr) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) cout << rArr[j].getData()[i] << " ";
        cout << endl;
    }
}

void runWheel(vector<ringQueue>& rArr) {
    for (int i = 0; i < 3; i++) {
        int turns = rand() % 30 + 5;
        for (int j = 0; j < turns; j++) rArr[i].pop();
    }
}



int main() {
    srand(time(0));

    vector<ringQueue> rArr;
    rArr.add_element_end(ringQueue());
    rArr.add_element_end(ringQueue());
    rArr.add_element_end(ringQueue());

    for(int i = 0; i < 3; i++)
        for(int j = 1; j < 8; j++){
            rArr[i].push(j);
        }
    runWheel(rArr);
    printWheel(rArr);





    return 0;
}