#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
class publication
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
///////////////////////////////////////////////////////////
class sales
{
private:
	enum { MONTHS = 3 };
	float salesArr[MONTHS];
public:
	void getdata();
	void putdata()const;
};
//---------------------------------------------------------
void sales::getdata()
{
	cout << "������� ����� ������ �� 3 ������:\n ";
	for (int j = 0; j < MONTHS; j++)
	{
		cout << " ����� " << j + 1 << ":";
		cin >> salesArr[j];
	}
}
//---------------------------------------------------------
void sales::putdata()const
{
	for (int j = 0; j < MONTHS; j++)
	{
		cout << "\n������� �� �����" << j + 1 << ":";
		cout << salesArr[j];
	}
}
///////////////////////////////////////////////////////////
class book :private publication, private sales
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << "������� ����� �������:"; cin >> pages;
		sales::getdata();
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\n�������:" << pages;
		sales::putdata();
	}
};
///////////////////////////////////////////////////////////
class tape :private publication, private sales
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata();
		cout << "������� ����� ��������:"; cin >> time;
		sales::getdata();
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\n����� ��������:" << time;
		sales::putdata();
	}
};

class disk :private publication, private sales
{
private:
	enum disketa{ DVD, CD };
	disketa current_disk;
	char user_choise;
public:
	void getdata()
	{
		publication::getdata();

		cout << "\n������� ������ ����� ���� �����: ";
		cin >> user_choise;

		if (user_choise == 'c')
		{
			current_disk = CD;
		}
		else
		{
			current_disk = DVD;
		}

		sales::getdata();
	}

	void putdata()const
	{
		//disketa current_disk;
		publication::putdata();

		cout << "Disk type: ";
		if (current_disk == CD)
		{
			cout << "CD";
		}
		else
		{
			cout << "DVD";
		}

		sales::putdata();
	}
};