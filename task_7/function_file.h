#include <iostream>
#include <cstring>
#include "class_file.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void task1()
{
	Distance dist1, dist3;
	
	dist1.getdist();

	Distance dist2(3, 6.25);

	dist3 = dist1 - dist2;

	cout << "\ndist1 ="; 
	dist1.showdist();
	
	cout << "\ndist2 ="; 
	dist2.showdist();
	
	cout << "\ndist3 ="; 
	dist3.showdist();
	
	cout << endl << endl;
}


void task2()
{
	//String s1 = "Happy, New Year!"; // использует конструктор с одним аргументом
	//String s2 = "Ура, товарищи!"; // использует конструктор с одним аргументом
	//String s3; // использует конструктор без аргументов
	//s3 = s1 += s2;// прибавить s2 к s1, результат - в s3
	//cout << "\ns1 ="; s1.display(); // вывести s1
	//cout << "\ns2 ="; s2.display(); // вывести s2
	//cout << "\ns3 ="; s3.display(); // вывести s3
	//cout << endl;
}

void task3()
{
	times time1(5, 59, 59);// создать и инициализировать
	times time2(4, 30, 30);// два времени
	times time3; // еще одно время создать
	time3 = time1 + time2; // сложить два значения времени
	cout << "\ntime3 ="; time3.display(); // вывести результат
	cout << endl;
}

void task4()
{
	Int alpha = 20;
	Int beta = 7;
	Int delta, gamma;

	gamma = alpha + beta; // 27
	cout << "\ngamma ="; 
	gamma.putInt();
	
	gamma = alpha - beta; // 13
	cout << "\ngamma ="; 
	gamma.putInt();
	
	gamma = alpha * beta; // 140 
	cout << "\ngamma ="; 
	gamma.putInt();
	
	gamma = alpha / beta; // 2 
	cout << "\ngamma ="; 
	gamma.putInt();
	
	//delta = 2147483647;
	//gamma = delta + alpha; // ошибка переполнения
	//
	//delta = -2147483647;
	//gamma = delta - alpha; // ошибка переполнения
	cout << endl;
}


void task5()
{
	times test_time(5, 5, 5), temp_time;

	test_time.display();

	temp_time = ++test_time;
	temp_time.display();
	test_time.display();


	temp_time = --test_time;
	temp_time.display();
	test_time.display();

	temp_time = test_time++;
	temp_time.display();
	test_time.display();


	temp_time = test_time--;
	temp_time.display();
	test_time.display();
}

void task6()
{
	times time_first(2, 2, 2), time_second(5, 5, 5);
	times time_total;

	time_total = time_second - time_first;
	time_total.display();

	time_total = time_first * time_second;
	time_total.display();

}

void task7()
{
	fraction first_fraction, second_fraction, total_fraction;
	fraction unit_fraction(1, 1), zero_fraction(0, 0);
	fraction wrong_fraction(0, 1), notDiv_fraction(1, 0);
	char operator_action;

	do
	{
		first_fraction.set_fraction();
		second_fraction.set_fraction();

		if ((first_fraction != unit_fraction && first_fraction != zero_fraction && first_fraction != wrong_fraction && first_fraction != notDiv_fraction) ||
			!(second_fraction == unit_fraction && second_fraction == zero_fraction && second_fraction == wrong_fraction && second_fraction == notDiv_fraction))
		{
			cout << "Entered an exit sign!" << endl;
			break;
		}

		cin >> operator_action;

		switch (operator_action)
		{
		case '+':
		{
			total_fraction = first_fraction + second_fraction;
			break;
		}
		case '-­':
		{
			total_fraction = first_fraction - second_fraction;
			break;
		}
		case '*':
		{
			total_fraction = first_fraction * second_fraction;
			break;
		}
		case '/':
		{
			total_fraction = first_fraction / second_fraction;
			break;
		}
		default:
			break;
		}

		total_fraction.display_fraction();

	} while (true);
}

void task8()
{
	bMoney first_value, second_value, total_value;
	long double time_cost, amount, result;
	char user_answer = 'y';

	while (user_answer == 'y')
	{
		first_value.mstold_get();
		second_value.mstold_get();
		cout << "Enter a time_cost:"; cin >> time_cost;
		cout << "Enter a amount:"; cin >> amount;

		cout << "Result of addition:" << endl;
		total_value = first_value + second_value;
		total_value.convertDollar_display();

		cout << "Result of substraction:" << endl;
		total_value = first_value - second_value;
		total_value.convertDollar_display();

		cout << "Result of multiplication. Cost of time:" << endl;
		total_value = first_value * time_cost;
		total_value.convertDollar_display();

		cout << "Result of division. Cost of element by time:" << endl;
		result = first_value / second_value;
		cout << "$" << result << endl;

		cout << "Result of division. Total cost by amount" << endl;
		total_value = total_value / amount;
		total_value.convertDollar_display();

		cout << "Do you want to continue?(y/n): ";
		cin >> user_answer;
	}
	
	//трай ит ту файнд аут а мистакес

	//second_value = first_value + amount; //- вронг


}

void task9()
{
	safearay sa1;

	sa1.set_range();

	for (int j = 0; j < sa1.get_tail(); j++) //insert elements
		sa1[j] = j * 10; //*left* side of equal sign

	for (int j = 0; j < sa1.get_tail(); j++) //display elements
	{
		int temp = sa1[j]; //*right* side of equal sign
		cout << "Element " << j << " is " << temp << endl;
	} 
}

void task10()
{
	Polar first_pol, second_pol, total_pol;
	decart_coord first_dec, second_dec, total_dec;

	first_pol.set_polar();
	second_pol.set_polar();

	first_dec = first_pol;
	second_dec = second_pol;

	total_dec = first_dec + second_dec;

	total_pol = total_dec;

	total_pol.display_polar();
}

void task11()
{
	sterling first_unit(1.0, 1, 1);
	sterling second_unit, total_unit;
	double amount_double;

	cout << "Введите величину типа Double: ";
	cin >> amount_double;

	second_unit.setSterling();
	cout << endl << endl;



	cout << "Result of addition(sterling + sterling): ";
	total_unit = first_unit + second_unit;
	total_unit.getSterling();

	cout << "Result of substraction(sterling - sterling): ";
	total_unit = first_unit - second_unit;
	total_unit.getSterling();

	cout << "Result of multiplication(sterling * double): ";
	total_unit = first_unit * amount_double;
	total_unit.getSterling();

	cout << "Result of division(sterling / double): ";
	total_unit = first_unit / amount_double;
	total_unit.getSterling();

	cout << "Result of division(sterling / sterling): ";
	total_unit = first_unit / second_unit;
	total_unit.getSterling();

}


void task12()
{
	bMoney bukcs_exchange;
	sterling sterling_exchange;

	cout << "Enter bucks sum(till $): ";
	bukcs_exchange.mstold_get();

	sterling_exchange = bukcs_exchange;

	sterling_exchange.getSterling();
}
