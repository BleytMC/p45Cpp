#include <iostream>
using namespace std;


namespace d2 {
    class point {
        int x, y;
    public:
        point(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void print() const {
            cout << "X: " << x << " Y: " << y << endl;
        }
    };
}

namespace d3 {
    class point {
        int x, y, z;
    public:
        point(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        void print() const {
            cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
        }
    };
}

namespace dynamicStructures {
    namespace lists {
        namespace single {
            struct element {
                int data;
                element* next = nullptr;
            };

            class list {
                element* head, * tail;
                int size;
            public:
                list() {
                    head = tail = nullptr;
                    size = 0;
                }

                void fillRandom(int size) {
                    for (int i = 0; i < size; i++) addHead(rand() % 101 - 50);
                }

                void addHead(int value) {
                    element* newElement = new element;
                    newElement->data = value;
                    if (size == 0) head = tail = newElement;
                    else {
                        newElement->next = head;
                        head = newElement;
                    }
                    newElement = nullptr;
                    size++;
                }

                void addTail(int value) {
                    element* newElement = new element;
                    newElement->data = value;
                    if (size == 0) head = tail = newElement;
                    else {
                        tail->next = newElement;
                        tail = newElement;
                    }
                    newElement = nullptr;
                    size++;
                }

                void removeHead() {
                    if (size == 0) return;
                    element* p = head;
                    head = head->next;
                    delete p;
                    p = nullptr;
                    size--;
                }

                void removeTail() {
                    if (size == 0) return;
                    if (size == 1) {
                        removeHead();
                        return;
                    }
                    element* p = head;
                    while (p->next != tail) p = p->next;
                    p->next = nullptr;
                    delete tail;
                    tail = p;
                    p = nullptr;
                    size--;
                }

                void addPosition(int value, int position) {
                    if (position > size) return;
                    if (position == 0) addHead(value);
                    else if (position == size) addTail(value);
                    else {
                        element* p = head;
                        for (int i = 0; i < position - 1; i++) p = p->next;
                        element* newElement = new element;
                        newElement->data = value;
                        newElement->next = p->next;
                        p->next = newElement;
                        p = nullptr;
                        size++;
                    }
                }

                void removePosition(int position) {
                    if (position >= size) return;
                    if (position == 0) removeHead();
                    else if (position == size - 1) removeTail();
                    else {
                        element* p = head;
                        for (int i = 0; i < position - 1; i++) p = p->next;
                        element* p2 = p->next->next;
                        delete p->next;
                        p->next = p2;
                        p = nullptr;
                        p2 = nullptr;
                        size--;
                    }
                }

                void clear() {
                    int p = size;
                    for (int i = 0; i < p; i++) removeHead();
                }

                void print() const {
                    if (size == 0) return;
                    element* p = head;
                    while (p) {
                        cout << p->data << " ";
                        p = p->next;
                    }
                }

                ~list() { clear(); }


            };
        }

        namespace d {
            struct element {
                int data = 0;
                element* next = nullptr, * prev = nullptr;
            };

            class list {
                element* head, * tail;
                int size;

                void copy(const list& other) {
                    element* p = other.head;
                    while (p->next) {
                        addTail(p->data);
                        p = p->next;
                    }
                    addTail(p->data);
                }

            public:
                list() {
                    head = tail = nullptr;
                    size = 0;
                }

                list(const list& other) {
                    copy(other);
                }

                void fillRandom(int size) {
                    for (int i = 0; i < size; i++) addHead(rand() % 101 - 50);
                }

                void addHead(int value) {
                    element* newElement = new element;
                    newElement->data = value;
                    if (size == 0) head = tail = newElement;
                    else {
                        newElement->next = head;
                        head->prev = newElement;
                        head = newElement;
                    }
                    newElement = nullptr;
                    size++;
                }

                void addTail(int value) {
                    element* newElement = new element;
                    newElement->data = value;
                    if (size == 0) head = tail = newElement;
                    else {
                        tail->next = newElement;
                        newElement->prev = tail;
                        tail = newElement;
                    }
                    newElement = nullptr;
                    size++;
                }

                void removeHead() {
                    if (size == 0) return;
                    element* p = head;
                    head = head->next;
                    if (size > 1) head->prev = nullptr;
                    delete p;
                    p = nullptr;
                    size--;
                }

                void removeTail() {
                    if (size == 0) return;
                    element* p = tail;
                    tail = tail->prev;
                    if (size > 1) tail->next = nullptr;
                    delete p;
                    p = nullptr;
                    size--;
                }

                void clear() {
                    while (head) removeHead();
                }

                void addPosition(int value, int position) {
                    if (position > size) return;
                    if (position == 0) addHead(value);
                    else if (position == size) addTail(value);
                    else {
                        element* p = head;
                        for (int i = 0; i < position - 1; i++) p = p->next;
                        element* newElement = new element;
                        newElement->data = value;
                        newElement->next = p->next;
                        p->next = newElement;
                        newElement->prev = p;
                        p = nullptr;
                        size++;
                    }
                }

                void removePosition(int position) {
                    if (position >= size) return;
                    if (position == 0) removeHead();
                    else if (position == size - 1) removeTail();
                    else {
                        element* p = head;
                        for (int i = 0; i < position; i++) p = p->next;
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                        delete p;
                        p = nullptr;
                        size--;
                    }
                }

                void print() const {
                    if (size == 0) return;
                    element* p = head;
                    while (p) {
                        cout << p->data << " ";
                        p = p->next;
                    }
                }

                list& operator=(const list& other) {
                    clear();
                    copy(other);
                    return *this;
                }

                ~list() { clear(); }
            };
        }
    }

    namespace queues {
        void line(int count) {
            cout << "\n";
            for (int i = 0; i < count; i++)
                cout << "-";
            cout << "\n";
        }

        class vector {
        private:
            int* data;
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
                this->data = new int[other.size];
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

            void add_element_need(int wher, int number) {
                int* p = new int[size + 1];

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
                int* p = new int[size];

                for (int i = 0; i < size; i++) {
                    p[i] = data[i];
                }

                delete[] data;
                data = p;
                p = nullptr;
            }

            void deletee_element_first() {
                size--;
                int* p = new int[size];

                for (int i = 0; i < size; i++) {
                    p[i] = data[i + 1];
                }

                delete[] data;
                data = p;
                p = nullptr;
            }

            void delete_element_position(int position) {
                int* p = new int[size - 1];

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

            int search_element_position(int element) {
                for (int i = 0; i < size; i++)
                    if (data[i] == element)
                        return i;
                return -1;
            }

            void delete_search_element(int element) {
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

            void change_element_by_value(int number, int change_number) {
                int position = search_element_position(number);
                if (position != -1)
                    data[position] = change_number;
            }

            void change_element_by_position(int position, int change_number) {
                data[position] = change_number;
            }

            void reverse_array() {
                for (int i = 0; i < size / 2; i++) {
                    swap(data[i], data[size - i - 1]);
                }
            }

            int get_max() {
                if (size == 0) return 0;
                int max_val = data[0];
                for (int i = 1; i < size; i++)
                    if (data[i] > max_val)
                        max_val = data[i];
                return max_val;
            }

            int get_min() {
                if (size == 0) return 0;
                int min_val = data[0];
                for (int i = 1; i < size; i++)
                    if (data[i] < min_val)
                        min_val = data[i];
                return min_val;
            }

            int get_size() const {
                return size;
            }

            int get_element(int index) {
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
                this->data = new int[other.size];

                for (int i = 0; i < other.size; i++)
                {
                    this->data[i] = other.data[i];
                }
                this->size = other.size;

                return *this;
            }

            int& get_element_by_index(unsigned int index) {
                if (index >= size)
                    throw exception("index out of range");

                return data[index];
            }
            int& operator[](unsigned int index) const {
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

        ostream& operator<< (ostream& os, const vector& obj) {
            obj.print_v();
            return os;
        }

        istream& operator>> (istream& is, vector& obj) {
            obj.set_random(10);
            return is;
        }


        class queue {
            vector data;
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
                    return buf;
                }
                throw exception("Queue is empty");
            }

            void clear() {
                data.delete_array();
            }

        };

        class ringQueue {
            vector data;
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

        };

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
    }
}


int main() {

    d2::point p1(1, 2);
    d3::point p2(4, 6, 1);

    p1.print();
    p2.print();




    return 0;
}