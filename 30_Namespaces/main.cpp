#include <iostream>
#include <string>
using namespace std;

// �������� ���� - �� ������� ���������� ����� � ����, ��� ��������� ������� ��'���� �� ����

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