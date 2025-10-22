#include <iostream>
#include <iomanip>
#include <list>
#include <string>
using namespace std;


template<class T>
void print(list<T> l) {
	for (int el : l) cout << el << " ";
	cout << endl;
}



int main() {
	srand(time(0));

	//list<int> l = { 3, 5, 9, 10, -2, 3, 5 };
	
	//l.push_back(10);
	//l.push_front(20);
	//l.pop_front();
	//l.pop_back();

	////l.clear();

	//list<int>::iterator it = l.begin();
	//it++;
	//it--;
	//advance(it, 5);

	/*list<int>::iterator it = l.begin();
	advance(it, 2);
	l.insert(it, 11);
	advance(it, 4);
	l.erase(it);*/

	//l.sort();
	//l.reverse();
	//print(l);


	list<int> l;
	for (int i = 0; i < 10; i++) l.push_back(rand() % 101 - 50);
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) cout << *it << " ";





	return 0;
}