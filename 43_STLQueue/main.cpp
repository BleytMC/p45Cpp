#include <iostream>
#include <string>
#include <queue>
using namespace std;

class client {
	int priority;
	string surname;
public:
	client() {
		priority = 0;
		surname = "";
	}
	client(int priority, string surname) {
		this->priority = priority;
		this->surname = surname;
	}
	int getPriority() const {
		return priority;
	}
	string getSurname() const {
		return surname;
	}
};

bool operator<(const client& a, const client& b) {
	return a.getPriority() < b.getPriority();
}

ostream& operator<<(ostream& os, const client& obj) {
	os << obj.getPriority() << " - " << obj.getSurname() << endl;
	return os;
}


int main() {

	priority_queue<client> clients;

	clients.push(client(10, "Ggths"));
	clients.push(client(15, "Kefkmn"));
	clients.push(client(1, "Dgrgbv"));
	clients.push(client(3, "Bnytrj"));
	clients.push(client(7, "Edsfas"));

	while (!clients.empty()) {
		cout << clients.top();
		clients.pop();
	}

	
	return 0;
}