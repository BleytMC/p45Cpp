#include <iostream>
#include <string>
#include <map>
#include <windows.h>
using namespace std;


void printWord(map<string, string>::iterator it) {
	cout << it->first << " - " << it->second << endl;
}

void printDict(map<string, string> dict) {
	for (map<string, string>::iterator it = dict.begin(); it != dict.end(); it++) {
		printWord(it);
	}
}

map<string, string>::iterator find(map<string, string> dict, string target) {
	auto it = dict.find(target);
	if (it != dict.end()) return it;
	else return dict.begin();
}



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	map<string, string> dict = {
		{"кіт", "cat"},
		{"собака", "dog"},
		{"машина", "car"}
	};

	printWord(find(dict, "машина"));




	return 0;
}