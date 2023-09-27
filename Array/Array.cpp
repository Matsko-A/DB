#include <iostream>
#include <stdexcept>
#include <random>
#include <string>
using namespace std;

/**
 * @brief Функция заполнения массива arr
 * @param arr массив
 * @param size размер массива
*/
void arrayInput(int* arr, size_t size);

/**
 * @brief Функция сложения всех элементов массива
 * @param arr массив
 * @param size размер массива
 * @return Возвращает сумму всех элементов массива
*/
int arraySum(int* arr, size_t size);

/**
 * @brief Функция вывода элементов массива в строку с помощью to_string
 * @param arr массив
 * @param size размер массива
*/
void arrayPrint(int* arr, size_t size);

/**
 * @brief Функция ввода размера массива 
 * @param message строка ввода массива
 * @return Возвращает размер массива равный 0 или больше
*/
size_t get_size(const string& message);

int main() {
	setlocale(LC_ALL, "rus");

	string message = "Введите размер массива: ";
	size_t size = 0;

	try {
		size = get_size(message);
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
		return -1;
	}

	int* arr = new int[size];

	arrayInput(arr, size);
	
	cout << "Элементы массива: ";
	arrayPrint(arr, size);
	cout << endl;

	cout << "Сумма элементов массива: " << arraySum(arr, size) << endl;

	if (arr != nullptr) {
		delete[] arr;
		arr = nullptr;
	}

	return 0;
}

void arrayInput(int* arr, size_t size) {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> uniformIntDistribution(0, 100);

	for (int i = 0; i < size; i++) {
		arr[i] = uniformIntDistribution(gen);
	}
}

int arraySum(int* arr, size_t size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count += arr[i];
	}

	return count;
}

void arrayPrint(int* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << to_string(arr[i]) << "] ";
	}
}

size_t get_size(const string& message) {
	int  size = -1;
	cout << message;
	cin >> size;

	if (size < 0) {
		throw out_of_range("Неправильный размер. Значение должно быть больше или равно нулю.");
	}

	return size;
}