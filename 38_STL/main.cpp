#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


// STL(Standart Template Library)

// vector
// list
// queue
// stack
// map, multi_map, set, multi_set

// контейнер
// ітератори - це сутності, які потрібні для взаємодії з елементами та методами контейнера.
// алгоритми
// функтори


template<class T>
void printVector(vector<T> v) {
	for (T el : v) cout << el << " ";
	cout << endl;
}


class point {
	int x, y;
public:
	point() {
		x = y = 0;
	}

	point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	friend ostream& operator << (ostream& os, const point& obj);
};


ostream& operator << (ostream& os, const point& obj) {
	os << "x = " << obj.x << "  " << "y = " << obj.y << "\n";
	return os;
}


int main() {

	//vector<int> v = { 10, -3, 0, 4, 11, 3, 9 };
	//v.push_back(100);

	///*for (int i = 0; i < v.size(); i++) {
	//	cout << v[i] << " ";
	//}*/

	//printVector(v);
	//v[2] = 200;
	//printVector(v);

	//v.pop_back();
	//printVector(v);

	//cout << endl;


	///*vector<int>::iterator it = v.begin();*/

	///*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << " ";
	//}

	//int i = 0;
	//cout << endl;
	//for (vector<int>::iterator it = v.begin(); i < v.size(); i++) {
	//	cout << *(it + i) << " ";
	//}*/

	//vector<int>::iterator it = v.begin();
	//cout << *(it + 2);


	//vector<int> v = { 10, -3, 0, 4, 11, 3, 9 };

	//vector<int>::iterator it = v.begin();

	//advance(it, 5);
	//cout << distance(v.begin(), it);

	/*v.insert(it + 5, 500);
	it = v.begin();
	v.insert(it + 5, 432);
	it = v.begin();
	v.insert(it + 5, 21);
	it = v.begin();
	v.insert(it + 5, 324);
	it = v.begin();
	printVector(v);*/

	//printVector(v);
	//v.erase(it + 2);
	//printVector(v);


	//vector<string> countries = { "USA", "Ukraine", "France", "Spain", "Germany" };
	//vector<string>::iterator it = countries.begin();
	//
	//countries.insert(it, "Italy");
	//printVector(countries);

	//vector<point> points = { point(1, 2), point(4, 5), point(10, -2) };
	//printVector(points);

	//vector<int> nums;
	//for (int i = 1; i < 11; i++) nums.push_back(i * i);
	//printVector(nums);


	int rows = 10, cols = 10;
	vector<vector<int>> v(rows);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			v[i].push_back(i * j);
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(3) << v[i][j];
		}
		cout << endl;
	}






	return 0;
}