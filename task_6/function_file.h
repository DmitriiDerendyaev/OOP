#include <iostream>
#include <cstring>
#include "class_file.h"

using namespace std;

void task1()
{
	setlocale(LC_ALL, "Russian");
	void reversit(char[]); //прототип
	const int MAX = 80;
	char str[MAX];

	cout << "Введите строку, которую вы хотите перевернуть: ";

	//cin >> str;
	//cin.getline(str, MAX);
	cin.get(str, MAX, '$');

	reversit(str);
	cout << "Перевернутая строка: " << str << endl;
	cin.clear();
	cin.sync();
	cin.ignore();
}

void reversit(char s[])
{
	int len = strlen(s);

	for (int i = 0; i < len / 2; i++)
	{
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

void task2()
{
	employee emp[100];
	int amount = 0;
	char answer;

	do {
		cout << "Введите данные о работнике с номером: " << amount + 1 << ' ';
		emp[amount++].getdata();
		cout << "Продолжить (y/n): ";
		cin >> answer;
	} while (answer != 'n');

	for (int i = 0; i < amount; i++)
	{
		emp[i].putdata();
	}
}

void task3()
{
	Distance distarr[100];
	Distance total(0, 0.0), average;
	int count = 0;
	char ch;

	do {
		cout << "\nВведите расстояние ";
		distarr[count++].getdist();
		cout << "\nПродолжить (y/n)?";
		cin >> ch;
	} while (ch != 'n');
	for (int j = 0; j < count; j++)
		total.add_dist(total, distarr[j]);
	average.div_dist(total, count);
	cout << "\nСреднее:"; 
	average.showdist();
	cout << endl;
}

int maxint(int arr[], int amount)
{
	int max_current = 0, max_index = 0;
	for (int i = 0; i < amount; i++)
	{
		if (arr[i] > max_current)
		{
			max_current = arr[i];
			max_index = i;
		}
	}
	return max_index;
}

void task4()
{
	const int MAX = 100;
	int arr[MAX], amount = 0;

	do {
		cout << "Введите число с номером " << amount + 1 << " : ";
		cin >> arr[amount++];
	} while (arr[amount - 1] != 0);

	cout << "Наибольший значение массива: " << arr[maxint(arr, amount)] << "; С индексом: " << maxint(arr, amount) + 1 << endl;
}

//void task5()
//{
//	fraction fraction_array[100], temp_fraction(0, 0), total(0, 0);
//	char answer;
//	int amount = 0;
//
//	do {
//		cout << "Введите дробь номер " << amount + 1 << " : ";
//		fraction_array[amount++].get_fraction();
//		cout << "Хотите ввести еще одну дробь?(y/n): ";
//		cin >> answer;
//	} while (answer != 'n');
//
//	if (amount < 2)
//	{
//		temp_fraction.addition_fraction(fraction_array[0], fraction_array[1]);
//	}
//	else if (amount >= 2)
//	{
//		for (int i = 1; i < amount; i++)
//		{
//			//temp_fraction.addition_fraction(fraction_array[i], fraction_array[i + 1]);
//			total = temp_fraction.addition_fraction(fraction_array[i]);
//		}
//		total.display_fraction();
//	}
//	else
//	{
//		temp_fraction.display_fraction();
//	}
//}

void task5()
{
	fraction fraction_array[100];
	char answer;
	int amount = 0;

	do {
		cout << "Введите дробь номер " << amount + 1 << " : ";
		fraction_array[amount++].get_fraction();
		cout << "Хотите ввести еще одну дробь?(y/n): ";
		cin >> answer;
	} while (answer != 'n');

	for (int i = 1; i < amount; i++)
	{
		fraction_array[0] = fraction_array[0].addition_fraction(fraction_array[i]);
	}

	fraction_array[0].multiplication_fraction_by_number(fraction_array[0], amount);

	fraction_array[0].display_fraction();

}

void task6()
{
	card deck[52];
	int j;
	cout << endl;
	for (j = 0; j < 52; j++) // создаем упорядоченную колоду карт
	{
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num, su);
	}
	// показываем исходную колоду
	cout << "Исходная колода:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << " ";
		if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
			cout << endl;
	}
	srand(time(NULL)); // инициализируем генератор случайных чисел
	for (j = 0; j < 52; j++)
	{
		int k = rand() % 52; // выбираем случайную карту
		card temp = deck[j]; // и меняем ее с текущей
		deck[j] = deck[k];
		deck[k] = temp;
	}
	// показываем перемешанную колоду
	cout << "\nПеремешанная колода:\n";
	for (j = 0; j < 52; j++)
	{
		deck[j].display();
		cout << " ";
		if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
			cout << endl << endl;
	}
}

void task7()
{
	const int amount_enter = 3;

	dollarPadayPlizz dollar[amount_enter];

	for (int i = 0; i < amount_enter; i++)
	{
		cout << "Итерация №" << i + 1 << ": " << endl;
		dollar[i].mstold();

		dollar[i].display_dollar();
	}
}

void task8()
{
	safearay sal;
	int temp = 12345, i;

	sal.putel(7, temp);

	temp = sal.getel(7);

	cout << temp << endl;

	cout << "\nВведите индекс элемента: ";
	cin >> i;
	cout << "\nВведите значение элемента: ";
	cin >> temp;
	sal.putel(i, temp);

	cout << "Введите индекс элемента, который вы хотите вывести на экран: ";
	cin >> i;
	cout << sal.getel(i) << endl;

}

void task9()
{
	Queue s1;
	
	s1.put_queue(1);
	s1.put_queue(2);
	s1.put_queue(3);
	s1.put_queue(4);
	s1.put_queue(5);
	s1.put_queue(6);
	s1.put_queue(7);

	cout << endl << endl;

	s1.display_queue();

	cout << endl << endl;

	cout << "Element: " << s1.get_queue() << endl;
	cout << "Element: " << s1.get_queue() << endl;

	cout << endl << endl;

	s1.display_queue();

	cout << endl << endl;
}

void task10()
{
	matrix ml(7, 7);
	int temp = 12345, i, j;

	ml.putel(4, 4, temp);

	temp = ml.getel(4, 4);

	cout << temp << endl;

	cout << "\nВведите индекс элемента: ";
	cin >> i >> j;
	cout << "\nВведите значение элемента: ";
	cin >> temp;
	ml.putel(i, j, temp);

	cout << "Введите индекс элемента, который вы хотите вывести на экран: ";
	cin >> i >> j;
	cout << ml.getel(i, j) << endl;
}

void task11()
{
	new_dollar shecel;

	shecel.set_value();
	shecel.ldtoms();
	shecel.convertDollar();
	shecel.display_string();
}

void task12()
{
	bMoney first, second, total, result;

	first.mstold_get();
	second.mstold_get();

	total.madd(first, second)->convertDollar_display();

	//total.convertDollar_display();
}


