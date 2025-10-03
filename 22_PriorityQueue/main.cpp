#include <iostream>
using namespace std;

void line(int lenght) {
    for (int i = 0; i < lenght; i++) cout << "-";
    cout << endl;
}


class priorityItem {
	int data;
	int priority;
public:
	priorityItem() {
		data = 0;
		priority = 0;
	}

	priorityItem(int data, int priority) {
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


ostream& operator<< (ostream& os, const priorityItem& obj) {
	obj.print();
	return os;
}


class vector {
private:
    priorityItem* data;
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

    void add_element_start(priorityItem number) {
        priorityItem* p = new priorityItem[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_end(priorityItem number) {
        priorityItem* p = new priorityItem[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_need(int wher, priorityItem number) {
        priorityItem* p = new priorityItem[size + 1];

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
        priorityItem* p = new priorityItem[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        priorityItem* p = new priorityItem[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        priorityItem* p = new priorityItem[size - 1];

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

    priorityItem& get_element_by_index(unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }

    priorityItem& operator[](unsigned int index) const {
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

class queue {
    vector data;
public:

    void push(priorityItem value) {
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

    priorityItem top() const {
        if (!isEmpty()) return data[0];
        throw exception("Queue is empty");
    }

    priorityItem pop() {
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

    queue q;

    q.push(priorityItem(1222, 5));
    q.push(priorityItem(3523, 2));
    q.push(priorityItem(12, 3));
    q.push(priorityItem(45, 8));
    q.push(priorityItem(123, 6));

    q.print();






	return 0;
}