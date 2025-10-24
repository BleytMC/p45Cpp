#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

	stack<int> s1;

	s1.push(4);
	s1.push(10);
	s1.push(5);
	s1.push(7);

	cout << s1.top() << endl;

	s1.pop();

	cout << s1.top() << endl;

	stack<int> s2;

	s2.push(100);
	s2.push(200);
	s2.push(300);

	s1.swap(s2);

	return 0;
}