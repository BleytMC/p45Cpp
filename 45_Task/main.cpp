#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <conio.h>
using namespace std;


void printWord(map<string, string>::iterator it) {
	cout << it->first << " - " << it->second << endl;
}

void printDict(map<string, string> dict) {
	for (map<string, string>::iterator it = dict.begin(); it != dict.end(); it++) {
		printWord(it);
	}
}

map<string, string>::iterator find(map<string, string>& dict, string target) {
	auto it = dict.find(target);
	if (it != dict.end()) return it;
	else return dict.begin();
}

void addWord(map<string, string>& dict, string ua, string en) {
	dict.insert(make_pair(ua, en));
}

void removeWord(map<string, string>& dict, const string& target) {
	auto it = dict.find(target);
	if (it != dict.end()) {
		dict.erase(it);
	}
}


void menu() {
	cout << "0 - Exit" << endl;
	cout << "1 - Add word" << endl;
	cout << "2 - Remove word" << endl;
	cout << "3 - Find word" << endl;
}


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	map<string, string> dict = {
		{"кіт", "cat"},
		{"собака", "dog"},
		{"машина", "car"}
	};

	int choice;
	string ua, en;

	do {
		_getch();
		system("cls");
		printDict(dict);
		cout << endl;
		menu();
		cin >> choice;
		switch(choice) {
			case 1:
				cout << "\nEnter ukrainian word: ";
				cin >> ua;
				cout << "Enter english word: ";
				cin >> en;
				addWord(dict, ua, en);
				break;
			case 2:
				cout << "\nEnter ukrainian word: ";
				cin >> ua;
				removeWord(dict, ua);
				break;
			case 3:
				cout << "Enter ukrainian word: ";
				cin >> ua;
				printWord(find(dict, ua));
				break;
		}
	} while (choice);




	return 0;
}