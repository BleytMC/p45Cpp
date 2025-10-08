#include <iostream>
#include <string>
using namespace std;


// Бінарне дерево - це ДСД, яка складається із вузлів,
// кожен з яких крім даних містить посилання на декілька інших вузлів
// а саме:
// - посилання на лівого нащадка
// - посилання на правого нащадка
// - посилання на предка

// Алгоритм побудови бінарного дерева:
// Перший елемент вставляється в корінь дерева.
// Якщо наступний елемент більший за попередній,
// то він вставляється в праву гілку,
// якщо менший, то в ліву



struct bus {
	int number;
	string name, surname;
	

	bus() {
		number = 0;
		name = "No name";
		surname = "No surname";
	}

	bus(int key, string name, string surname) {
		this->number = number;
		this->name = name;
		this->surname = surname;
	}
};

struct element {
	bus key;
	element* left, * right, * parent;

	element() {
		key.number = 0;
		left = right = parent = nullptr;
	}
};

class tree {
	element* root;
	int count;
public:
	tree() {
		root = nullptr;
		count = 0;
	}

	void insert(bus b) {
		element* node = new element;
		node->key = b;
		element* ptr = nullptr, * tmp = root;
		while (tmp) {
			ptr = tmp;
			if (node->key.number < tmp->key.number) tmp = tmp->left;
			else tmp = tmp->right;
		}
		if (ptr == nullptr) root = node;
		else if (node->key.number < ptr->key.number) ptr->left = node;
		else ptr->right = node;
		count++;
	}

	void print(element* node) const {
		if (node) {
			print(node->left);
			cout << node->key.number << " " << node->key.name << " " << node->key.surname << endl;
			print(node->right);
		}
	}

	element* getRoot() const {
		return root;
	}

	element* getMin(element* node) const {
		if (!node) return nullptr;
		while (node->left) node = node->left;
		return node;
	}

	element* getMax(element* node) const {
		if (!node) return nullptr;
		while (node->right) node = node->right;
		return node;
	}

	element* search(element* node, int key) {
		while (node && node->key.number != key) {
			if (key < node->key.number) node = node->left;
			else node = node->right;
		}
		return node;
	}
};



int main() {





	tree t;

	t.insert(bus(122, "Jtheg", "Veggs"));
	t.insert(bus(54, "Gsafg", "Qeewf"));

	t.print(t.getRoot());

	






	return 0;
}