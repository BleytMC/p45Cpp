#include <iostream>
#include <string>
using namespace std;

// 1

class component {
	string companyName;
public:
	component(string companyName) {
		this->companyName = companyName;
	}

	void set(string companyName) {
		this->companyName = companyName;
	}

	string get() {
		return companyName;
	}
};

class gpu : public component {
public:
	gpu(string companyName) : component(companyName) {}
};

class memory : public component {
public:
	memory(string companyName) : component(companyName) {}
};

class graphicCard : public gpu, public memory {
public:
	graphicCard(string gpuCompanyName, string memoryCompanyName) : gpu(gpuCompanyName), memory(memoryCompanyName) {}
};

// 2

class character {
public:
	int hp;
};

class warrior : public virtual character {};

class boss : public virtual character {};

class bossWarrior : public warrior, public boss {};



int main() {

	/*character c;
	c.hp = 100;*/



	/*graphicCard gc("Nvidia", "Samsung");

	cout << gc.gpu::get() << endl;
	cout << gc.memory::get() << endl;*/




	return 0;
}