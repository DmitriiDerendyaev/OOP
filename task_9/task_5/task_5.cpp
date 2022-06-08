#include <iostream>

const int SZ = 5;

int main()
{
	setlocale(LC_ALL, "Russian");

	float arr1[SZ];
	float arr2[SZ];
	float arr3[SZ];

	void addarrays(float*, float*, float*, const int);

	std::cout << "¬ведите елементы первого массива(max - 5): ";
	for (int i = 0; i < SZ; i++)
	{
		float temp;
		std::cin >> temp;
		*(arr1 + i) = temp;
	}

	std::cout << "¬ведите елементы второго массива(max - 5): ";
	for (int i = 0; i < SZ; i++)
	{
		float temp;
		std::cin >> temp;
		*(arr2 + i) = temp;
	}

	addarrays(arr1, arr2, arr3, SZ);

	std::cout << "—умма двух массивов: ";
	for (int i = 0; i < SZ; i++)
	{
		std::cout << *(arr3 + i) << ' ';
	}

	return 0;
}

void addarrays(float* arr1, float* arr2, float* arr3, const int size_array)
{
	for (int i = 0; i < size_array; i++)
	{
		*(arr3 + i) = *(arr1 + i) + *(arr2 + i);
	}
}