#include <iostream>
#include <cstring>
#include "class_file.h"

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
	String s1 = "� ����� �����!"; // ���������� ����������� � ����� ����������
	String s2 = "���, ��������!"; // ���������� ����������� � ����� ����������
	String s3; // ���������� ����������� ��� ����������
	s3 = s1 += s2;// ��������� s2 � s1, ��������� - � s3
	cout << "\ns1 ="; s1.display(); // ������� s1
	cout << "\ns2 ="; s2.display(); // ������� s2
	cout << "\ns3 ="; s3.display(); // ������� s3
	cout << endl;
}

void task3()
{
	
}

void task4()
{
	
}


void task5()
{
	
}

void task6()
{
	
}

void task7()
{
	
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


