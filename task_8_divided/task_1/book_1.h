#include <iostream>
#include <string>

using namespace std;

class publication
{
private:
	string title;
	float price;
public:
	void set_data()
	{
		cout << "\nВведите заголовок книги: ";
		cin >> title;

		cout << "\nВведите цену: ";
		cin >> price;
	}
	void get_data()
	{
		cout << "\nЗаголовок:" << title;
		cout << "\nЦена:" << price;
	}
};

class book : public publication
{
private:
	int pages;
public:
	void set_data()
	{
		publication::set_data();
		cout << "Введите число страниц: ";
		cin >> pages;
	}
	void get_data()
	{
		publication::get_data();
		cout << "\nСтраниц:" << pages;
	}
};

class tape : private publication
{
private:
	float time;
public:
	void set_data()
	{
		publication::set_data();
		cout << "Введите время звучания:";
		cin >> time;
	}
	void get_data()
	{
		publication::get_data();
		cout << "\nВремя звучания:" << time;
	}
};