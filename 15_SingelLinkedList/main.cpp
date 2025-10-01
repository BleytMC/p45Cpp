#include <iostream>
using namespace std;


// Динамічні структури даних(ДСД) - це структури даних, пам'ять для яких виділяється по мірі ноебхідності.

// Вектор(Vector)
// Списки(Однозв'язні, Двозв'язні)
// Стек
// Черга(Проста, Кільцева, Черга з пріоритетами, Дек)
// Дерева(Бінарне дерво)

// Донозв'язний список - це ДСД, в якому об'єкти складаються з елементів, що містять певну інформацію і вказівник на інший елемент



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




int main() {
	srand(time(0));

	list l;
	l.fillRandom(7);
	int a, b, choice;

	do {
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
	} while (choice);




	return 0;
}