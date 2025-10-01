#include <iostream>
using namespace std;


template<class T>
class area {

	static int count;


public:

	static double square(T a) {
		count++;
		return a * a;
	}

	static double rectangle(T a, T b) {
		count++;
		return a * b;
	}

	static double diamond(T d1, T d2) {
		count++;
		return (d1 * d2) / 2;
	}

	static double triangle(T a, T h) {
		count++;
		return (a * h) / 2;
	}

	static double triangle(T a, T b, T c) {
		T p = (a + b + c) / 2;
		count++;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

template<class T>
int area<T>::count = 0;




int main() {





	return 0;
}