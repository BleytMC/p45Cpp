#include <iostream>
#include <string>
using namespace std;

class building {
public:
	string door, walls, windows;
};

class house : public building {};
class shop : public building {};
class hotel : public building {};
class castle : public building {};
class mailPost : public building {};



int main() {



	return 0;
}