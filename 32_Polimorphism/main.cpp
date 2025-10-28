#include <iostream>
#include <string>
using namespace std;

// Поліморфізм - здатність коду при 
// поcтійному інтерфейсі(зовнішньому вигдяді)
// працювати по різному, в залежності від ситуації
// момент виконання програми

// Раннє зв'язування - тип об'єкта відомий на етапі компіляції і 
// виклик метода з кодом цього метода зв'язується на етапі копміляції.
// Компілятор при ранньому зв'язуванні орієнтується на тип об'єкта.

// Якщо зв'язування виклику метода з кодом самого мктода відбувається на етапі виконання програми, то таке зв'язування називається пізнім.


class A {
public:
	virtual void func() {
		cout << "Class A, func\n";
	}
};

class B : public A {
public:
	void func() override {
		cout << "Class B, func\n";
	}
};

class C : public A {
public:
	void func() override {
		cout << "Class C, func\n";
	}
};


class vehicle {
protected:
	string name, color;
public:
	vehicle(string name, string color) {
		this->name = name;
		this->color = color;
	}

	virtual void drive() = 0;
};

class car : public vehicle {
public:
	car(string name, string color) : vehicle(name, color) {}

	void drive() override {
		cout << "I am driving car " << color << " " << name << " car\n";
	}
};

class bus : public vehicle {
public:
	bus(string name, string color) : vehicle(name, color) {}

	void drive() override {
		cout << "I am driving car " << color << " " << name << " bus\n";
	}
};

class moto : public vehicle {
public:
	moto(string name, string color) : vehicle(name, color) {}

	void drive() override {
		cout << "I am driving car " << color << " " << name << " moto\n";
	}
};


class weapon {
public:
	virtual void shoot() {
		cout << "Weapon Shoot!\n";
	}
};

class gun : public weapon {
public:
	void shoot() override {
		cout << "Gun Shoot!\n";
	}
};

class rifle : public weapon {
public:
	void shoot() override {
		cout << "Rifle Shoot!\n";
	}
};

class machineGun : public weapon {
public:
	void shoot() override {
		cout << "Machine gun Shoot!\n";
	}
};

class player {

public:
	void shootWeapon(weapon* w) {
		w->shoot();
	}
};


class payment {
public:
	virtual void insert() {
		cout << "Inserted payment\n";
	}
};

class cash : public payment {
public:
	void insert() override {
		cout << "Inserted cash\n";
	}
};

class card : public payment {
public:
	void insert() override {
		cout << "Inserted card\n";
	}
};

class nfc : public payment {
public:
	void insert() override {
		cout << "Inserted nfc\n";
	}
};

class ATM {
public:
	virtual void insert(payment* p) {
		p->insert();
	}
};






int main() {


	vehicle* v = new bus("f12", "red");
	v->drive();


	/*vehicle* arr[] = { new car, new bus, new moto };

	for (vehicle* v : arr) {
		v->drive();
	}*/


	/*player p;
	gun g;
	p.shootWeapon(&g);*/


	/*vehicle* v = nullptr;
	car c;
	bus b;
	moto m;

	cout << "1 - car\n";
	cout << "2 - bus\n";
	cout << "3 - moto\n";
	int choice;
	cout << "Enter cour choice: ";
	cin >> choice;
	switch (choice) {
		case 1:
			v = &c;
			break;
		case 2:
			v = &b;
			break;
		case 3:
			v = &m;
			break;
	}
	v->drive();*/

	/*A objA;
	objA.func();

	B objB;
	objB.func();

	C objC;
	objC.func();*/


	/*A objA;
	B objB;
	C objC;*/

	/*A* pA = &objA;
	B* pB = &objB;
	C* pC = &objC;

	pA->func();
	pB->func();
	pC->func();*/

	/*A* pA = nullptr;
	pA = &objB;
	pA->func();
	pA = &objC;
	pA->func();*/





	return 0;
}