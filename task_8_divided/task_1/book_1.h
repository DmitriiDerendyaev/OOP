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
		cout << "\n������� ��������� �����: ";
		cin >> title;

		cout << "\n������� ����: ";
		cin >> price;
	}
	void get_data()
	{
		cout << "\n���������:" << title;
		cout << "\n����:" << price;
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
		cout << "������� ����� �������: ";
		cin >> pages;
	}
	void get_data()
	{
		publication::get_data();
		cout << "\n�������:" << pages;
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
		cout << "������� ����� ��������:";
		cin >> time;
	}
	void get_data()
	{
		publication::get_data();
		cout << "\n����� ��������:" << time;
	}
};