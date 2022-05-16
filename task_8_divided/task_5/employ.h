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
		cout << "������� �����������: ";
		cin >> compensation;

		cout << "������� ������ ������(������ ����� ��: hourly, weekly, monthly): ";
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
		cout << "\n�����������: " << compensation;
		cout << "\n������ ������: ";
		switch (current_period)
		{
		case hourly:
		{
			cout << "���������"; break;
		}
		case weekly:
		{
			cout << "������������"; break;
		}
		case monthly:
		{
			cout << "�����������"; break;
		}
		}
	}
};

class manager : public employee2 // ��������
{
private:
	char title[LEN]; // ���������, �������� ����-���������
	double dues; // ����� ������� � �����-����
public:
	void getdata()
	{
		employee2::getdata();
		cout << " ������� ���������: "; 
		cin >> title;
		cout << " ������� ����� ������� � �����-����: "; 
		cin >> dues;
	}
	void putdata()
	{
		employee2::putdata();
		cout << "\n ���������: " << title;
		cout << "\n ����� ������� � �����-����: " << dues;
	}
};

class scientist : public employee2 // ������
{
private:
	int pubs;                     // ���������� ����������
public:
	void getdata()
	{
		employee2::getdata();
		cout << "  ������� ���������� ����������: "; cin >> pubs;
	}
	void putdata()
	{
		employee2::putdata();
		cout << "\n  ���������� ����������: " << pubs;
	}
};

class laborer : public employee2   // �������
{
};

