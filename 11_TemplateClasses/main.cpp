#include <iostream>
using namespace std;



template<class T>
class myClass {

	T a;

public:

	myClass() { a = 0; }
	myClass(T a) { this->a = a; }
	void set(T a) { this->a = a; }
	T get() { return a; }
	void print() const { cout << a << endl; }

};


template<class T>
class point {

	T x, y, z;

public:

	point() { x = y = z = 0; }
	point(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	template<class T>
	friend double distance(point<T> p1, point<T> p2);
};

template<class T>
double distance(point<T> p1, point<T> p2) {
	return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)) + ((p1.z - p2.z) * (p1.z - p2.z)));
}




int main() {

	/*myClass<int> obj1(100);
	obj1.print();

	myClass<double> obj2(23.6);
	obj2.print();

	myClass<bool> obj3(1);
	obj3.print();

	myClass<char> obj4('h');
	obj4.print();*/

	point<int> p1(1, 4, 9);
	point<int> p2(7, 5, 12);
	cout << distance(p1, p2);





	return 0;
}