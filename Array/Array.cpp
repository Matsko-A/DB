#include <iostream>
#include <stdexcept>
#include <random>
using namespace std;

/**
 * @brief 
 * @param arr 
 * @param size 
*/
void arrayInput(int* arr, const int size);

/**
 * @brief 
 * @param arr 
 * @param size 
 * @return 
*/
int arraySum(int* arr, const int size);

/**
 * @brief 
 * @param arr 
 * @param size 
*/
void arrayPrint(int* arr, const int size);

/**
 * @brief 
 * @param size  
*/
void errorSize(const int size);

void arrayInput(int* arr, const int size) {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> uniformIntDistribution(0, 100);

	for (int i = 0; i < size; i++) {
		arr[i] = uniformIntDistribution(gen);
	}
}

int arraySum(int* arr, const int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count += arr[i];
	}
	
	return count;
}

void arrayPrint(int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << arr[i] << "] ";
	}
}

void errorSize(const int size) {
	if (size <= 0) throw invalid_argument("Error size array");
}

int main() {
	setlocale(LC_ALL, "rus");

	int size = 0;
	cout << "Введите размер массива: ";
	cin >> size;

	try {
		errorSize(size);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
		return -1;
	}

	int* arr = new int[size];

	arrayInput(arr, size);
	
	cout << "Элементы массива: ";
	arrayPrint(arr, size);
	cout << endl;

	cout << "Сумма элементов массива: " << arraySum(arr, size) << endl;
	return 0;
}
