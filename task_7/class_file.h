#include <iostream>
#include <cstring>
#include <process.h>

using namespace std;

class Distance //English Distance class 
{
	private:
		int feet; 
		float inches;
	public: //constructor (no args)
		Distance() : feet(0), inches(0.0)
		{ } //constructor (two args)
		Distance(int ft, float in) : feet(ft), inches(in)
		{ }
		void getdist() //get length from user
		{
			cout << "\nEnter feet: "; cin >> feet;
			cout << "Enter inches: "; cin >> inches;
		}
		void showdist() const 
		{//display distance 
			cout << feet << "\'-" << inches << '\"'; 
		}
			Distance operator+(Distance d2);
			Distance operator-(Distance d2);
			//add 2 distances
};

Distance Distance::operator+(Distance d2)// ������� �����
{
	int f = feet + d2.feet; // ������� ����
	float i = inches + d2.inches; // ������� �����
	if (i >= 12.0) // ���� ����� ������ ��������� 12.0,
	{ // ��������� ����� ������
		i -= 12.0; // �� 12.0 � 
		f++; // ��������� ����� ����� � 1
	} // ������� ��������� 
	return Distance(f, i);// �������� ����������, ������ �����
}

Distance Distance::operator-(Distance d2) // ������� ��������
{
	int f = feet - d2.feet; // �������� �����
	float i = inches - d2.inches; // �������� ������
	if (i < 0) // ���� ����� ������ ������ 0,
	{ // ��������� �� ���������� �� 
		i += 12.0; // 12.0 � 
		f--; // ��������� ����� ����� �� 1
	} // ������� ��������� ����������,
	return Distance(f, i); // ������ ��������
}

class String // ���������������� ��������� ���
{
private:
	enum { SZ = 100 }; // ������ �������� String
	char str[SZ]; // �������� �-������
public:
	String() // ����������� ��� ����������
	{
		strcpy(str, "");
	}
	String(char s[]) // ����������� � 1 ����������
	{
		strcpy(str, s);
	}
	void display() // ����� ������
	{
		cout << str;
	}
	String operator+=(String ss)// ����������� ������ �
	// ���������
	{// ��������� ����������� � ��������� ������
		if (strlen(str) + strlen(ss.str) >= SZ)
		{
			cout << "\n������������ ������"; exit(1);
		}
		strcat(str, ss.str);// �������� ����������� ������
		return String(str); // ������� ��������� String
	}
};