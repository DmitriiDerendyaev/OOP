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
	//String s1 = "Happy, New Year!"; // ���������� ����������� � ����� ����������
	//String s2 = "���, ��������!"; // ���������� ����������� � ����� ����������
	//String s3; // ���������� ����������� ��� ����������
	//s3 = s1 += s2;// ��������� s2 � s1, ��������� - � s3
	//cout << "\ns1 ="; s1.display(); // ������� s1
	//cout << "\ns2 ="; s2.display(); // ������� s2
	//cout << "\ns3 ="; s3.display(); // ������� s3
	//cout << endl;
}

void task3()
{
	times time1(5, 59, 59);// ������� � ����������������
	times time2(4, 30, 30);// ��� �������
	times time3; // ��� ���� ����� �������
	time3 = time1 + time2; // ������� ��� �������� �������
	cout << "\ntime3 ="; time3.display(); // ������� ���������
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
	//gamma = delta + alpha; // ������ ������������
	//
	//delta = -2147483647;
	//gamma = delta - alpha; // ������ ������������
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
		case '-�':
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
	
}

void task9()
{

}

void task10()
{
	
}

void task11()
{
	
}

void task12()
{
	
}

class function_file
{
};


