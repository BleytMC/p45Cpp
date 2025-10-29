#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
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

int getAmount(vector<int> v, function<bool(int)> fn) {
	int count = 0;
	for (int el : v) if (fn(el)) count++;
	return count;
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

int getLenght(int a) {
	int count = 0;
	while (a) {
		a /= 10;
		count++;
	}
	return count;
}


class employee {
	string name;
	double salary;
public:
	employee(string name, int salary) {
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


class student {
	string name, surname, course;
	float averageMark;
public:
	student(string name, string surname, string course, float averageMark) {
		this->name = name;
		this->surname = surname;
		this->course = course;
		this->averageMark = averageMark;
	}

	void print() const {
		cout << "Student: " << name << " " << surname << "\n\tStudying in " << course << "\n\tAverage mark: " << averageMark;
	}

	string getCourse() const {
		return course;
	}

	float getAverageMark() const {
		return averageMark;
	}
};

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}


void mySort(vector<int>& v, function<bool(int, int)> fn) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = v.size() - 1; j > i; j--) {
			if (fn(v[j], v[j - 1]))
				swap(v[j], v[j - 1]);
		}
	}

}


bool operator<(const employee& a, const employee& b) {
	return a.getName() < b.getName();
}


int main() {


	/*vector<int> v = { 10, 4, 6, -2, 3, 3, 66, 33, 11, 100, -2 };
	printVector(v, isEven);
	printVector(v, isOdd);
	printVector(v, isPositive);
	printVector(v, isPrime);
	printVector(v, isNegative);*/

	// Анонімні(лямба функції(lambda))
	// [](){}

	
	/*function<void(int)> f = [](int a) {
		cout << "Value: " << a;
		};

	f(100);*/

	/*function<void(int)> f = [](int a) {
		cout << "Value: " << a;
		}(100);*/

	/*vector<int> v = { 10, 4, 6, -2, 3, 3, 66, 33, 11, 100, -2 };*/
	/*printVector(v, [](int a) {return a % 2 == 0;});
	printVector(v, [](int a) {return a % 2 != 0; });
	printVector(v, [](int a) {
		return a > 0;
	});
	printVector(v, [](int a) {
		if (a < 0) return false;
		for (int i = 2; i < a; i++) if (a % i == 0) return false;
		return true;
	});
	printVector(v, [](int a) {
		return a < 0;
	});*/

	/*int n;
	cin >> n;

	cout << getAmount(v, [](int a) {return a % 2 == 0; }) << endl;
	cout << getAmount(v, [](int a) {return a > 0; }) << endl;
	cout << getAmount(v, [n](int a) {return getLenght(a) == n; }) << endl;*/


	/*vector<int> v = { 10, 4, 6, -2, 3, 3, 66, 33, 11, 100, -2 };

	int count = count_if(v.begin(), v.end(), [](int a) {return a % 2 != 0; });
	cout << count;*/


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
	};*/


	/*cout << count_if(employees.begin(), employees.end(), [](const employee& e) {return e.getSalary() > 60000; }) << endl;
	cout << count_if(employees.begin(), employees.end(), [](const employee& e) {return e.getName()[0] == 'A'; }) << endl;*/


	//for_each(employees.begin(), employees.end(), [](const employee& e) {e.print(); });

	/*vector<int> v = { 10, 4, 6, -2, 3, 3, 66, 33, 11, 100, -2 };
	int sum = 0;
	for_each(v.begin(), v.end(), [&sum](int a) {sum += a; });
	cout << sum;*/


	/*vector<student> students = {
		student("John", "Doe", "Computer Science", 8.7),
		student("Jane", "Smith", "Mathematics", 9.2),
		student("Tom", "Brown", "Physics", 7.9),
		student("Alice", "Davis", "Biology", 8.5),
		student("Bob", "Miller", "Engineering", 9.0),
		student("Charlie", "Wilson", "Computer Science", 8.8),
		student("David", "Moore", "Literature", 9.1),
		student("Emily", "Taylor", "Psychology", 8.4),
		student("Frank", "Anderson", "Economics", 7.8),
		student("Grace", "Thomas", "History", 8.2),
		student("Hannah", "Jackson", "Political Science", 8.9),
		student("Ian", "White", "Computer Science", 9.5),
		student("Jack", "Harris", "Arts", 8.7),
		student("Kathy", "Clark", "Chemistry", 8.6),
		student("Liam", "Lewis", "Mathematics", 9.3)
	};

	for_each(students.begin(), students.end(), [](const student& s) {if (s.getCourse() == "Computer Science" && s.getAverageMark() > 9) s.print(); });*/


	//vector<int> v = { 10, 4, 6, -2, 3, 3, 66, 33, 11, 100, -2 };

	////sort(v.begin(), v.end(), [](int a, int b) {return a > b; });

	//mySort(v, [](int a, int b) {return a < b; });

	//for (int el : v) cout << el << " ";



	vector<employee> employees = {
		employee("Henry Ford", 55000.50),
		employee("Diana Prince", 90000.25),
		employee("Charlie Brown", 50000.00),
		employee("Ivy Green", 68000.00),
		employee("Alice Smith", 60000.00),
		employee("Jack Taylor", 80000.10),
		employee("Frank White", 72000.75),
		employee("Eve Adams", 65000.00),
		employee("Arace Kelly", 88000.00),
		employee("Bob Johnson", 75000.50)
	};

	//sort(employees.begin(), employees.end(), [](employee a, employee b) {return a.getSalary() > b.getSalary(); });

	sort(employees.begin(), employees.end());

	for_each(employees.begin(), employees.end(), [](const employee& e) {e.print(); });



	return 0;
}