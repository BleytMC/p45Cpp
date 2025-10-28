#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

struct timeStruct {
	int hour;
	int minute;
	timeStruct() {
		hour = minute = 0;
	}
	timeStruct(int hour, int minute) {
		this->hour = hour;
		this->minute = minute;
	}
	void set(int hour, int minute) {
		this->hour = hour;
		this->minute = minute;
	}
};

ostream& operator << (ostream& os, const timeStruct& obj) {
	if (obj.hour < 10) os << "0";
	os << obj.hour << ":";
	if (obj.minute < 10) os << "0";
	os << obj.minute;
	return os;
}

class train {
	int number;
	string destinationStation;
	timeStruct departureTime;
public:
	train() {
		number = 0;
		destinationStation = "No destination";
		departureTime.set(0, 0);
	}
	train(int number, string destinationStation, int departureHour, int departureMinute) {
		this->number = number;
		this->destinationStation = destinationStation;
		this->departureTime.set(departureHour, departureMinute);
	}
	void set(int number, string destinationStation, int departureHour, int departureMinute) {
		this->number = number;
		this->destinationStation = destinationStation;
		this->departureTime.set(departureHour, departureMinute);
	}
	int getNumber() const {
		return number;
	}
	string getDestinationStation() const {
		return destinationStation;
	}
	timeStruct getDepartureTime() const {
		return departureTime;
	}
};

ostream& operator << (ostream& os, const train& obj) {
	os << "Train ¹" << obj.getNumber() << "\n\tDestination station: " << obj.getDestinationStation() << "\n\tDeparture time: " << obj.getDepartureTime();
	return os;
}


class sys {
	vector<train> trains;
public:
	void addTrain(train t) {
		trains.push_back(t);
	}
	void removeTrain(int trainNumber) {
		for (vector<train>::iterator it = trains.begin(); it != trains.end(); it++) {
			if ((*it).getNumber() == trainNumber) {
				trains.erase(it);
				break;
			}
		}
	}
	void print(int detailed) const {
		for (train t : trains) {
			if (t.getNumber() == detailed) cout << t << endl;
			else cout << "Train ¹" << t.getNumber() << endl;
		}
	}
};


void menu() {
	cout << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Add new train" << endl;
	cout << "2 - Get more info" << endl;
}



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	sys s;

	s.addTrain(train(1, "Station 1", 12, 20));
	s.addTrain(train(2, "Station 1", 12, 45));
	s.addTrain(train(5, "Station 2", 15, 10));
	s.addTrain(train(9, "Station 3", 11, 15));
	s.addTrain(train(12, "Station 1", 11, 30));
	s.addTrain(train(65, "Station 2", 16, 00));
	
	string station;
	int choice, detailed = -1, number, hour, minute;
	do {
		system("cls");
		s.print(detailed);
		menu();
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter train number: ";
				cin >> number;
				cout << "Enter destination station: ";
				cin >> station;
				cout << "Enter departure time: ";
				cin >> hour >> minute;
				s.addTrain(train(number, station, hour, minute));
				break;
			case 2:
				cout << "Enter train number: ";
				cin >> detailed;
				break;
		}
	} while (choice);





	return 0;
}