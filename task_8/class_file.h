#include <iostream>

using namespace std;

class publication // ������� �����
{
private:
	string title;
	float price;
public:
	void getdata()
	{
		cout << "\n������� ���������:"; cin >> title;
		cout << "������� ����:"; cin >> price;
	}
	void putdata()const
	{
		cout << "\n���������:" << title;
		cout << "\n����:" << price;
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

class book :private publication // ����������� �����
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "������� ����� �������:"; cin >> pages;
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\n�������:" << pages;
	}
};

class tape :private publication // ����������� �����
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "������� ����� ��������:"; cin >> time;
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\n����� ��������:" << time;
	}
};

