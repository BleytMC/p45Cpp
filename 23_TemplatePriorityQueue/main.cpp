#include <iostream>
using namespace std;

void line(int lenght) {
    for (int i = 0; i < lenght; i++) cout << "-";
    cout << endl;
}


template<class T>
class priorityItem {
    T data;
    int priority;
public:
    priorityItem() {
        data = T();
        priority = 0;
    }

    priorityItem(T data, int priority) {
        this->data = data;
        this->priority = priority;
    }

    void print() const {
        cout << "Data: " << data << " | Priority: " << priority << endl;
    }

    int getPriority() const {
        return priority;
    }
};

template<class T>
ostream& operator<< (ostream& os, const priorityItem<T>& obj) {
    obj.print();
    return os;
}

template<class T>
class vector {
private:
    priorityItem<T>* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(const vector& other) {
        this->data = new priorityItem[other.size];
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

    void add_element_start(priorityItem<T> number) {
        priorityItem<T>* p = new priorityItem<T>[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_end(priorityItem<T> number) {
        priorityItem<T>* p = new priorityItem<T>[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_need(int wher, priorityItem<T> number) {
        priorityItem<T>* p = new priorityItem<T>[size + 1];

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
        priorityItem<T>* p = new priorityItem<T>[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        priorityItem<T>* p = new priorityItem<T>[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        priorityItem<T>* p = new priorityItem<T>[size - 1];

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

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    int get_size() const {
        return size;
    }

    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    priorityItem<T>& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    priorityItem<T>& operator[](unsigned int index) const {
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
class queue {
    vector<T> data;
public:

    void push(priorityItem<T> value) {
        if (isEmpty()) data.add_element_end(value);
        else {
            int i = 0;
            while (i < data.get_size() && data[i].getPriority() <= value.getPriority()) {
                i++;
            }
            data.add_element_need(i, value);
        }
    }

    void print() const {
        data.print_v();
    }

    bool isEmpty() const {
        return data.isEmpty();
    }

    priorityItem<T> top() const {
        if (!isEmpty()) return data[0];
        throw exception("Queue is empty");
    }

    priorityItem<T> pop() {
        if (!isEmpty()) {
            priorityItem buf = data[0];
            data.deletee_element_first();
            return buf;
        }
        throw exception("Queue is empty");
    }

    void clear() {
        data.delete_array();
    }

};



int main() {

    queue<char> q;

    q.push(priorityItem<char>('j', 5));
    q.push(priorityItem<char>('h', 2));
    q.push(priorityItem<char>('k', 3));
    q.push(priorityItem<char>('l', 8));
    q.push(priorityItem<char>('g', 6));

    q.print();






    return 0;
}