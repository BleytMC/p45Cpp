#include <iostream>
using namespace std;



class myString {
	char* str;
	int lenght;

	void copyStr(const char* str) {
		this->lenght = strlen(str);
		this->str = new char[this->lenght + 1];
		for (int i = 0; i < this->lenght; i++) this->str[i] = str[i];
		this->str[this->lenght] = '\0';
	}

public:
	myString() {
		str = nullptr;
		lenght = 0;
	}

	myString(const char* str) {
		copyStr(str);
	}

	myString(const myString& other) {
		copyStr(other.str);
	}

	int getLenght() const {
		return lenght;
	}

	char* getStr() const {
		return str;
	}

	~myString() {
		delete[] str;
	}

};

ostream& operator<<(ostream& os, const myString& str) {
	os << str.getStr() << endl;
	return os;
}

istream& operator>>(istream& is, myString& str) {
	is >> str.getStr();
	return is;
}




int main() {

	myString s1("Hello world");
	myString s2;

	cout << s1;

	cin >> s2;

	cout << s2;





	return 0;
}