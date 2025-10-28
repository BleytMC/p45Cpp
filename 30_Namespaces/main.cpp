#include <iostream>
#include <string>
using namespace std;

// Простори імен - це область оголошення даних і типів, яка забезпечує логічний зв'язок між ними

namespace ns1 {
	class myClass {

	};
}

namespace ns2 {
	class myClass {

	};
}

using namespace ns1;

int main() {

	myClass ms1;



	return 0;
}