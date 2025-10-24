#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

void func1() {
	cout << "Func 1()" << endl;
}

void func2() {
	cout << "Func 2()" << endl;
}


void printVector(vector<int> v, function<bool(int)> fn) {
	for (int el : v) if (fn(el)) cout << el << " ";
	cout << endl;
}

bool isEven(int a) {
	return a % 2 == 0;
}

bool isOdd(int a) {
	return a % 2 != 0;
}

bool isPositive(int a) {
	return a > 0;
}

bool isNegative(int a) {
	return a < 0;
}

bool isPrime(int a) {
	if (a < 0) return false;
	for (int i = 2; i < a; i++) if (a % i == 0) return false;
	return true;
}


int main() {


	vector<int> v = { 10, 4, 6, -2, 3, 3, 66, 33, 11, 100, -2 };
	printVector(v, isEven);
	printVector(v, isOdd);
	printVector(v, isPositive);
	printVector(v, isPrime);



	//function<void()> p;
	//p = func1;
	////func1();
	//p();

	//p = func2;
	//p();






	return 0;
}