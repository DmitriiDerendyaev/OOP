#include <iostream>

using namespace std;

class publication // базовый класс
{
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\nВведите заголовок:"; cin >> title;
		cout << "Введите цену:"; cin >> price;
	}
	void putdata()const
	{
		cout << "\nЗаголовок:" << title;
		cout << "\nЦена:" << price;
	}
};

class sales
{
private:
	enum { MONTHS = 3 };
	float salesArr[MONTHS];
public:
	void getdata();
	void putdata()const;
};

class book :private publication // порожденный класс
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Введите число страниц:"; cin >> pages;
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\nСтраниц:" << pages;
	}
};

class tape :private publication // порожденный класс
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "Введите время звучания:"; cin >> time;
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\nВремя звучания:" << time;
	}
};

