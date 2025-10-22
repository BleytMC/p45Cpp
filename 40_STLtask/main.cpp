#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
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
	os << "Train ¹" << obj.getNumber() << "\n\tDestination station: " << obj.getDestinationStation() << "\n\tDeparture time: " << obj.getDepartureTime() << endl;
	return os;
}


class system {
	vector<train> trains;
public:
	system(train t) {
		trains.push_back(t);
	}
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
	void print() const {
		for (train t : trains) cout << t << endl;
	}
};




int main() {

	system s(train(1, "Station 1", 12, 20));





	return 0;
}