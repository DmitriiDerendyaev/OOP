#include <iostream>
#include "function_file.h"
#include <cstring>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int task;
	cout << "FAQ: дл€ выхода из программы введите 0." << endl;
	cout << "¬ведите номер задачи: ";
	cin >> task;
	while (task != 0)
	{
		switch (task)
		{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			task5();
			break;
		}
		case 6:
		{
			task6();
			break;
		}
		case 7:
		{
			task7();
			break;
		}
		case 8:
		{
			task8();
			break;
		}
		case 9:
		{
			task9();
			break;
		}
		case 10:
		{
			task10();
			break;
		}
		case 11:
		{
			task11();
			break;
		}
		case 12:
		{
			task12();
			break;
		}
		}
		cout << "¬ведите номер задачи: ";
		cin >> task;
	}
	system("pause");
}