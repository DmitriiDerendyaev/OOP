#include <iostream>

using namespace std;

const int LEN = 80; //maximum length of names
////////////////////////////////////////////////////////////////
class employee //employee class
{
private: 
	char name[LEN];
	unsigned long number;
public: void getdata() {
	cout << "\nEnter last name: "; 
	cin >> name;
	cout << "Enter number: "; 
	cin >> number;
}
	void putdata() const
	{
		cout << "\n Name: " << name;
		cout << "\n Number: " << number;
	}
};

class employee2 : private employee
{
private:
	double compensation;
	enum period {hourly, weekly, monthly};
	period current_period;
	char user_choice;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Введите компенсацию: ";
		cin >> compensation;

		cout << "Введите период оплаты(первая буква от: hourly, weekly, monthly): ";
		cin >> user_choice;

		switch (user_choice)
		{
		case 'h':
		{
			current_period = hourly;
			break;
		}
		case 'w':
		{
			current_period = weekly; 
			break;
		}
		case 'm':
		{
			current_period = monthly; 
			break;
		}
		}
	}
	void putdata()
	{
		cout << "\nКомпенсация: " << compensation;
		cout << "\nПериод оплаты: ";
		switch (current_period)
		{
		case hourly:
		{
			cout << "Почасовая"; break;
		}
		case weekly:
		{
			cout << "Еженедельная"; break;
		}
		case monthly:
		{
			cout << "Ежемесячная"; break;
		}
		}
	}
};

class manager : public employee2 // менеджер
{
private:
	char title[LEN]; // должность, например вице-президент
	double dues; // сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee2::getdata();
		cout << " Введите должность: "; 
		cin >> title;
		cout << " Введите сумму взносов в гольф-клуб: "; 
		cin >> dues;
	}
	void putdata()
	{
		employee2::putdata();
		cout << "\n Должность: " << title;
		cout << "\n Сумма взносов в гольф-клуб: " << dues;
	}
};

class scientist : public employee2 // ученый
{
private:
	int pubs;                     // количество публикаций
public:
	void getdata()
	{
		employee2::getdata();
		cout << "  Введите количество публикаций: "; cin >> pubs;
	}
	void putdata()
	{
		employee2::putdata();
		cout << "\n  Количество публикаций: " << pubs;
	}
};

class laborer : public employee2   // рабочий
{
};

