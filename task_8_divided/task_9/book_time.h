#include <iostream>
#include <string>

using namespace std;

class publication
{
private:
	string title;
	float price;
public:
	void setdata()
	{
		cout << "\n������� ��������� �����: ";
		cin >> title;

		cout << "\n������� ����: ";
		cin >> price;
	}
	void getdata()
	{
		cout << "\n���������:" << title;
		cout << "\n����:" << price;
	}
};

class publication2 : public publication
{
private:
	int day;
	int month;
	int year;
public:
	publication2() : day(0), month(0), year(0)
	{ }
	publication2(int d, int m, int y) : day(d), month(m), year(y)
	{ }
	void setdata()
	{
		publication::setdata();
		cout << "Enter the date(XX/YY/ZZZZ): ";
		cin >> day >> month >> year;
	}
	void getdata()
	{
		publication::getdata();
		cout << "\nDate publication: " << day << '/' << month << '/' << year << "\n";
	}
};

class book : public publication2
{
private:
	int pages;
public:
	void setdata()
	{
		publication2::setdata();
		cout << "������� ����� �������: ";
		cin >> pages;
	}
	void getdata()
	{
		publication2::getdata();
		cout << "\n�������:" << pages;
	}
};


class tape : private publication2
{
private:
	float time;
public:
	void setdata()
	{
		publication2::setdata();
		cout << "������� ����� ��������:";
		cin >> time;
	}
	void getdata()
	{
		publication2::getdata();
		cout << "\n����� ��������:" << time;
	}
};