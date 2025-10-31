#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;


class car {
	string name;
	int year;
	double engineValue, price;
public:
	car(string name, int year, double engineValue, double price) {
		this->name = name;
		this->year = year;
		this->engineValue = engineValue;
		this->price = price;
	}

	void print() {
		cout << "Car: " << name << "\n\tMade in " << year << "\n\tEngine value: " << engineValue << "L\n\tPrice: " << price << "$\n";
	}

	string getName() const {
		return name;
	}

	int getYear() const {
		return year;
	}

	double getEngineValue() const {
		return engineValue;
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
		copy_if(cars.begin(), cars.end(), back_inserter(result), [year](const car& c) {return c.getYear() > year; });
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

	void sortByEngineValueToTop() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getEngineValue() < b.getEngineValue(); });
	}

	void sortByEngineValueToLow() {
		sort(cars.begin(), cars.end(), [](car a, car b) {return a.getEngineValue() > b.getEngineValue(); });
	}
};




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



	return 0;
}