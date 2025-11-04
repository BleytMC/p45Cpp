#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <conio.h>
using namespace std;


class car {
	string name;
	int year;
	double engineVolume, price;
public:
	car(string name, int year, double engineVolume, double price) {
		this->name = name;
		this->year = year;
		this->engineVolume = engineVolume;
		this->price = price;
	}

	void print() {
		cout << "Car: " << name << "\n\tMade in " << year << "\n\tEngine volume: " << engineVolume << "L\n\tPrice: " << price << "$\n";
	}

	string getName() const {
		return name;
	}

	int getYear() const {
		return year;
	}

	double getEngineVolume() const {
		return engineVolume;
	}

	double getPrice() const {
		return price;
	}
};

bool operator<(const car& a, const car& b) {
	return a.getPrice() < b.getPrice();
}

class dealership {
	vector<car> cars;
public:
	dealership(vector<car> cars) {
		this->cars = cars;
	}

	void print() {
		for (car c : cars) c.print();
	}

	bool isEmpty() {
		return cars.size() == 0;
	}

	void addCar(car c) {
		cars.push_back(c);
	}

	void removeCar(string name) {
		for (auto it = cars.begin(); it != cars.end(); it++) if (it->getName() == name) cars.erase(it);
	}

	dealership findByName(string name) {
		vector<car> result;
		copy_if(cars.begin(), cars.end(), back_inserter(result), [name](const car& c) {return c.getName().find(name) != -1; });
		return dealership(result);
	}

	dealership findByYear(int year) {
		vector<car> result;
		copy_if(cars.begin(), cars.end(), back_inserter(result), [year](const car& c) {return c.getYear() >= year; });
		return dealership(result);
	}

	dealership findByPrice(int minPrice, int maxPrice) {
		vector<car> result;
		copy_if(cars.begin(), cars.end(), back_inserter(result), [minPrice, maxPrice](const car& c) {return c.getPrice() >= minPrice && c.getPrice() <= maxPrice; });
		return dealership(result);
	}

	car findWithLowestPrice() {
		return *(min_element(cars.begin(), cars.end()));
	}

	car findWithHighestPrice() {
		return *(max_element(cars.begin(), cars.end()));
	}

	void sortByPriceToTop() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getPrice() < b.getPrice(); });
	}

	void sortByPriceToLow() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getPrice() > b.getPrice(); });
	}

	void sortByYearToTop() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getYear() < b.getYear(); });
	}

	void sortByYearToLow() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getYear() > b.getYear(); });
	}

	void sortByEngineVolumeToTop() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getEngineVolume() < b.getEngineVolume(); });
	}

	void sortByEngineVolumeToLow() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getEngineVolume() > b.getEngineVolume(); });
	}
};


void menu() {
	cout << "0 - Exit" << endl;
	cout << "1 - Add car" << endl;
	cout << "2 - Remove car" << endl;
	cout << "3 - Show all cars" << endl;
	cout << "4 - Search by name" << endl;
	cout << "5 - Search by year" << endl;
	cout << "6 - Search by price" << endl;
	cout << "7 - Search the cheapest" << endl;
	cout << "8 - Search the most expensive" << endl;
	cout << "9 - Sort by price from the cheapest" << endl;
	cout << "10 - Sort by price from the most expensive" << endl;
	cout << "11 - Sort by year from the oldest" << endl;
	cout << "12 - Sort by year from the newest" << endl;
	cout << "13 - Sort by engine volume from the smallest" << endl;
	cout << "14 - Sort by engine volume from the biggest" << endl;
}




int main() {


	vector<car> cars = {
		car("Toyota Corolla", 2020, 1.8, 19500.99),
		car("Honda Civic", 2021, 2.0, 21000.50),
		car("BMW X5", 2023, 3.0, 75000.00),
		car("Audi A6", 2022, 2.5, 62000.75),
		car("Ford Focus", 2019, 1.6, 17000.25),
		car("Chevrolet Malibu", 2020, 2.0, 24000.00),
		car("Kia Sportage", 2021, 2.4, 26000.49),
		car("Hyundai Tucson", 2022, 2.5, 28000.99),
		car("Mercedes-Benz E-Class", 2023, 3.0, 82000.50),
		car("Volkswagen Passat", 2018, 1.8, 19000.00),
		car("Mazda CX-5", 2021, 2.5, 27000.30),
		car("Subaru Outback", 2022, 2.5, 32000.75),
		car("Nissan Altima", 2020, 2.0, 23000.00),
		car("Jeep Grand Cherokee", 2023, 3.6, 45000.00),
		car("Tesla Model 3", 2023, 0.0, 55000.99)
	};

	dealership d(cars);

	d.sortByYearToTop();

	d.print();


	int choice, year, a, b;
	string name;
	double engineVolume, price;

	do {
		system("cls");
		menu();
		cin >> choice;
		cout << endl;
		switch (choice) {
			case 1:
				cout << "Enter car name: ";
				cin >> name;
				cout << "Enter year: ";
				cin >> year;
				cout << "Enter engine volume: ";
				cin >> engineVolume;
				cout << "Enter price: ";
				cin >> price;
				d.addCar(car(name, year, engineVolume, price));
				break;
			case 2:
				cout << "Enter car name: ";
				d.removeCar(name);
				break;
			case 3:
				system("cls");
				d.print();
				break;
			case 4:
				cout << "Enter name: ";
				cin >> name;
				system("cls");
				if (d.findByName(name).isEmpty()) cout << "Nothing found";
				else d.findByName(name).print();
				break;
			case 5:
				cout << "Enter year: ";
				cin >> year;
				system("cls");
				if (d.findByYear(year).isEmpty()) cout << "Nothing found";
				else d.findByYear(year).print();
				break;
			case 6:
				cout << "Enter bottom price barrier: ";
				cin >> a;
				cout << "Enter top price barrier: ";
				cin >> b;
				system("cls");
				if (d.findByPrice(a, b).isEmpty()) cout << "Nothing found";
				else d.findByPrice(a, b).print();
				break;
			case 7:
				d.findWithLowestPrice().print();
				break;
			case 8:
				d.findWithHighestPrice().print();
				break;
			case 9:
				d.sortByPriceToTop();
				break;
			case 10:
				d.sortByPriceToLow();
				break;
			case 11:
				d.sortByYearToTop();
				break;
			case 12:
				d.sortByYearToLow();
				break;
			case 13:
				d.sortByEngineVolumeToTop();
				break;
			case 14:
				d.sortByEngineVolumeToLow();
				break;
		}
		if (choice) _getch();
	} while (choice);



	return 0;
}