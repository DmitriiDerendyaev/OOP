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
		cout << "\nВведите заголовок:"; cin >> title;
		cout << "Введите цену:"; cin >> price;
	}
	void putdata()const
	{
		cout << "\nЗаголовок:" << title;
		cout << "\nЦена:" << price;
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
	cout << "Введите объем продаж за 3 месяца:\n ";
	for (int j = 0; j < MONTHS; j++)
	{
		cout << " Месяц " << j + 1 << ":";
		cin >> salesArr[j];
	}
}
//---------------------------------------------------------
void sales::putdata()const
{
	for (int j = 0; j < MONTHS; j++)
	{
		cout << "\nПродажи за месяц" << j + 1 << ":";
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
		cout << "Введите число страниц:"; cin >> pages;
		sales::getdata();
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\nСтраниц:" << pages;
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
		cout << "Введите время звучания:"; cin >> time;
		sales::getdata();
	}
	void putdata()const
	{
		publication::putdata();
		cout << "\nВремя звучания:" << time;
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

		cout << "\nВведите первую букву типа диска: ";
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