#include <iostream>
using namespace std;

// Двозв'язний список - це ДСД, в якому об'єкти складаються із елементів,
// що містять певну інформацію і два вказівники:
// один на попередній елемент, інший - на наступний елемент.


int menu() {

	cout << "\n\n0 - Exit\n";
	cout << "1 - Add Head\n";
	cout << "2 - Add Tail\n";
	cout << "3 - Delete Head\n";
	cout << "4 - Delete Tail\n";
	cout << "5 - Clear\n";
	cout << "6 - Add in position\n";
	cout << "7 - Remove from position\n\n";

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}


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



int main() {

	srand(time(0));

	list l;
	l.fillRandom(7);
	int a, b, choice;

	/*do {
		system("cls");
		l.print();

		choice = menu();
		if (!choice) break;

		switch (choice)
		{
		case 1:
			cout << "Enter number: ";
			cin >> a;
			l.addHead(a);
			break;
		case 2:
			cout << "Enter number: ";
			cin >> a;
			l.addTail(a);
			break;
		case 3:
			l.removeHead();
			break;
		case 4:
			l.removeTail();
			break;
		case 5:
			l.clear();
			break;
		case 6:
			cout << "Enter number: ";
			cin >> a;
			cout << "Enter position: ";
			cin >> b;
			l.addPosition(a, b);
			break;
		case 7:
			cout << "Enter position: ";
			cin >> a;
			l.removePosition(a);
			break;
		default:
			cout << "Incorrect input";
			break;
		}
	} while (choice);*/

	list l2 = l;
	l.print();
	cout << endl;
	l2.print();
	list l3;
	l3 = l2;
	cout << endl;
	l3.print();



	return 0;
}