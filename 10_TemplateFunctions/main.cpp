#include <iostream>
using namespace std;

template<class T>
void print(T* arr, int size) {
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}


template<class T>
T sum(T a, T b) {
	return a + b;
}


template<class T>
T max(T* arr, int size) {
	T max = arr[0];
	for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
	return max;
}

template<class T>
T min(T* arr, int size) {
	T min = arr[0];
	for (int i = 0; i < size; i++) if (arr[i] < min) min = arr[i];
	return min;
}

template<class T>
void sort(T* arr, int size) {
	T* buf = new T[size];
	for (int i = 0; i < size; i++) {
		buf[i] = min(arr, size);
		for (int j = 0; j < size; j++)
			if (arr[j] == min(arr, size)) {
				arr[j] = max(arr, size);
				break;
			}
	}
	for (int i = 0; i < size; i++) arr[i] = buf[i];
}

template<class T>
double average(T* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) sum += arr[i];
	return sum / size;
}







int main() {
	

	//cout << sum(3, 4);

	const int size = 5;
	int arr1[] = { 3, 0, 1 , 19, 4 };
	double arr2[] = { 9.2, -4.2, 1.1 , 19.4, 4.3 };

	print(arr1, size);
	sort(arr1, size);
	print(arr1, size);




	return 0;
}