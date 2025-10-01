#include <iostream>
#include <iomanip>
using namespace std;


class employee {

	char* surname;
	int id;

	static int count;

public:

	employee(const char* surname) {
		count++;
		this->surname = new char[strlen(surname) + 1];
		strcpy_s(this->surname, strlen(surname) + 1, surname);
		id = count;
	}

	static int getLastId() {
		return count;
	}

	void print() {
		cout << "Surname: " << this->surname << "\tID: " << id << endl;
	}
};

int employee::count = 0;


class myMath {



public:

	static const double pi;

	static int sum(int a, int b) {
		return a + b;
	}

	static int sub(int a, int b) {
		return a - b;
	}

	static int mul(int a, int b) {
		return a * b;
	}

	static int div(int a, int b) {
		return a / b;
	}

	static int square(int a) {
		return a * a;
	}
};

const double myMath::pi = 3.14;

class area {

	static int count;


public:

	static float square(float a) {
		count++;
		return a * a;
	}

	static float rectangle(float a, float b) {
		count++;
		return a * b;
	}

	static float diamond(float d1, float d2) {
		count++;
		return (d1 * d2) / 2;
	}

	static float triangle(float a, float h) {
		count++;
		return (a * h) / 2;
	}

	static float triangle(float a, float b, float c) {
		float p = (a + b + c) / 2;
		count++;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

int area::count = 0;

int main() {

	/*employee e1("Eegeg");
	employee e2("Lfekfn");
	employee e3("Pfejbs");
	employee e4("Vefqf");

	e1.print();
	e2.print();
	e3.print();
	e4.print();

	cout << endl << employee::getLastId();*/

	/*cout << area::triangle(3, 4) << endl << area::triangle(3, 4, 5);*/


	return 0;
}