#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;



class employee {
	string name;
	double salary;
public:
	employee(string name, double salary) {
		this->name = name;
		this->salary = salary;
	}

	void print() const {
		cout << "Name: " << name << "\nSalary: " << salary << endl << endl;
	}

	double getSalary() const {
		return salary;
	}

	string getName() const {
		return name;
	}
};



int main() {



	//vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };

	/*auto res = find(v.begin(), v.end(), 675);
	if (res != v.end()) cout << "Found " << *res;
	else cout << "Not found";*/

	/*auto res = find_if(v.begin(), v.end(), [](int a) {return a < 0; });
	if (res != v.end()) cout << "Found " << *res;
	else cout << "Not found";*/


	/*vector<employee> employees = {
		employee("Alice Smith", 60000.00),
		employee("Bob Johnson", 75000.50),
		employee("Charlie Brown", 50000.00),
		employee("Diana Prince", 90000.25),
		employee("Eve Adams", 65000.00),
		employee("Frank White", 72000.75),
		employee("Arace Kelly", 88000.00),
		employee("Henry Ford", 55000.50),
		employee("Ivy Green", 68000.00),
		employee("Jack Taylor", 80000.10)
	};

	char s = 'D';

	auto res = find_if(employees.begin(), employees.end(), [s](const employee& e) {return e.getName()[0] == s; });
	res->print();*/


	/*vector<employee> employees = {
		employee("Alice Smith", 60000.00),
		employee("Bob Johnson", 75000.50),
		employee("Charlie Brown", 50000.00),
		employee("Diana Prince", 90000.25),
		employee("Eve Adams", 65000.00),
		employee("Frank White", 72000.75),
		employee("Arace Kelly", 88000.00),
		employee("Henry Ford", 55000.50),
		employee("Ivy Green", 68000.00),
		employee("Jack Taylor", 80000.10)
	};

	vector<employee> result;

	copy_if(employees.begin(), employees.end(), back_inserter(result), [](const employee& e) {return e.getName()[0] == 'A'; });
	for (employee e : result) e.print();*/


	/*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };
	vector<int> result;

	copy_if(v.begin(), v.end(), back_inserter(result), [](int a) {return a % 2 == 0; });
	for (int a : result) cout << a << " ";*/


	/*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3, 22, 97, 33, 11, 100, 3, -2 };

	auto it = remove(v.begin(), v.end(), 3);
	v.erase(it, v.end());

	for (int a : v) cout << a << " ";*/


	/*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3, 22, 97, 33, 11, 100, 3, -2 };

	auto it = remove_if(v.begin(), v.end(), [](int a){return a < 0; });
	v.erase(it, v.end());

	for (int a : v) cout << a << " ";*/


	/*vector<employee> employees = {
		employee("Alice Smith", 60000.00),
		employee("Bob Johnson", 75000.50),
		employee("Charlie Brown", 50000.00),
		employee("Diana Prince", 90000.25),
		employee("Eve Adams", 65000.00),
		employee("Frank White", 72000.75),
		employee("Arace Kelly", 88000.00),
		employee("Henry Ford", 55000.50),
		employee("Ivy Green", 68000.00),
		employee("Jack Taylor", 80000.10)
	};

	auto it = remove_if(employees.begin(), employees.end(), [](const employee& e) {return e.getSalary() > 80000; });
	employees.erase(it, employees.end());

	for (employee e : employees) e.print();*/


	/*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3, 22, 97, 33, 11, 100, 3, -2 };

	auto it = min_element(v.begin(), v.end());

	cout << *it;*/


	/*vector<employee> employees = {
		employee("Alice Smith", 60000.00),
		employee("Bob Johnson", 75000.50),
		employee("Charlie Brown", 50000.00),
		employee("Diana Prince", 90000.25),
		employee("Eve Adams", 65000.00),
		employee("Frank White", 72000.75),
		employee("Arace Kelly", 88000.00),
		employee("Henry Ford", 55000.50),
		employee("Ivy Green", 68000.00),
		employee("Jack Taylor", 80000.10)
	};

	auto it = minmax_element(employees.begin(), employees.end(), [](const employee& a, const employee& b) {return a.getSalary() < b.getSalary(); });
	it.first->print();
	it.second->print();*/

	
	// accumulate

	
	/*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3, 22, 97, 33, 11, 100, 3, -2 };

	int res = accumulate(v.begin(), v.end(), 0, [](int prev, int current) { return current % 2 == 0 ? prev + current : prev; });

	cout << res;*/


	vector<employee> employees = {
		employee("Alice Smith", 60000.00),
		employee("Bob Johnson", 75000.50),
		employee("Charlie Brown", 50000.00),
		employee("Diana Prince", 90000.25),
		employee("Eve Adams", 65000.00),
		employee("Frank White", 72000.75),
		employee("Arace Kelly", 88000.00),
		employee("Henry Ford", 55000.50),
		employee("Ivy Green", 68000.00),
		employee("Jack Taylor", 80000.10)
	};

	double res = accumulate(employees.begin(), employees.end(), 0.0, [](double prev, const employee& e) {return prev + e.getSalary(); });
	cout << fixed << setprecision(2) << res;






	return 0;
}	