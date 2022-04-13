//#include "stdafx.h"
#include <iostream>
#include <string.h>   // ��� ������� strcpy, strcat
#include <stdlib.h>   // ��� ������� exit
#define _CRT_SECURE_NO_WARNINGS

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
		strcpy_s(str, "");
	}
	String(char s[])
	{
		strcpy_s(str, s);
	}
	//String(char s[]) // ����������� � 1 ����������
	//{
	//	strcpy(str, s);
	//}
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

class times
{
private:
	int hrs, mins, secs;
public:

	times() : hrs(0), mins(0), secs(0) // ����������� ��� �����.
	{ } // ����������� � ����� �����������
	times(int h, int m, int s) :hrs(h), mins(m), secs(s)
	{ }
	void display() // ������ 11:59:59
	{
		cout << hrs << ":" << mins << ":" << secs << endl;
	}
	times operator+(times t2) // ������� ��� �������
	{
		int s = secs + t2.secs; // ������� �������
		int m = mins + t2.mins; // ������� ������
		int h = hrs + t2.hrs; // ������� ����
		if (s > 59) // ���� ������� ����� ������,
		{
			s -= 60; m++;
		} // ��������� �� � ���� ������
		if (m > 59) // ���� ������� ����� �����,
		{
			m -= 60; h++;
		} // ��������� �� � ���� ���
		return times(h, m, s); // ������� ��������� ��������
	}
	times operator-(times t2)
	{
		long int total_sec = (hrs * 3600 + mins * 60 + secs) - (t2.hrs * 3600 + t2.mins * 60 + t2.secs);
		int new_hrs = total_sec / 3600;
		int new_mins = total_sec % 3600 / 60;
		int new_secs = total_sec % 3600 % 60;

		return (times(new_hrs, new_mins, new_secs));
	}

	times operator*(times t2)
	{
		long int total_sec = (hrs * 3600 + mins * 60 + secs) * (t2.hrs * 3600 + t2.mins * 60 + t2.secs);
		int new_hrs = total_sec / 3600;
		int new_mins = total_sec % 3600 / 60;
		int new_secs = total_sec % 3600 % 60;

		return (times(new_hrs, new_mins, new_secs));
	}

	times operator++()
	{
		return (times(++hrs, ++mins, ++secs));
	}
	times operator--()
	{
		return (times(--hrs, --mins, --secs));
	}
	times operator++(int)
	{
		return (times(hrs++, mins++, secs++));
	}
	times operator--(int)
	{
		return (times(hrs--, mins--, secs--));
	}
};

class Int
{
private:
	int i;
public:
	Int() : i(0) // ����������� ��� ����������
	{ }
	Int(int ii) :i(ii) // ����������� � ����� ����������
	{ } // (�� int � Int)
	void putInt() // ����� Int
	{
		cout << i;
	}
	void getInt() // ������ Int � ����������
	{
		cin >> i;
	}
	operator int() // �������� ��������������
	{
		return i;
	} // (Int � int)
	Int operator+(Int i2) // ��������
	{
		return checkit(long double(i) + long double(i2));
	}
	Int operator-(Int i2) // ���������
	{
		return checkit(long double(i) - long double(i2));
	}

	Int operator*(Int i2) // ���������
	{
		return checkit(long double(i) * long double(i2));
	}
	Int operator/(Int i2) // �������
	{
		return checkit(long double(i) / long double(i2));
	}
	Int checkit(long double answer) // ��������
	// �����������
	{
		if (answer > 2147483647.0L || answer < -2147483647.0L)
		{
			cout << "\n������ ������������\n "; exit(1);
		}
		return Int(int(answer));
	}
};

class fraction
{
private:
	int numenator;
	int denominator;
public:
	fraction() :numenator(0), denominator(0)
	{ }
	fraction(int n, int d) : numenator(n), denominator(d)
	{ }
	void set_fraction()
	{
		char slash;
		cout << "Enter a fraction(X/Y): ";
		cin >> numenator >> slash >> denominator;
		/*if (isError(numenator, denominator) == true)
		{
			cout << "Error" << endl;
			exit(1);
		}*/
	}
	void display_fraction()
	{
		lowterms_void();
		cout << "Fraction is: " << numenator << '/' << denominator << endl << endl;
	}
	fraction operator+(fraction);
	fraction operator-(fraction);
	fraction operator*(fraction);
	fraction operator/(fraction);
	bool operator==(fraction);
	bool operator!=(fraction);
	fraction lowterms(fraction);
	void lowterms_void();
	//bool isError(int, int);//Error == true; notError == false;
};

//bool fraction::isError(int numenator, int denominator)
//{
//	if ((numenator == 0 && denominator == 0) || (numenator == 1 && denominator == 1) || (numenator == 1 && denominator == 0) || (numenator == 0 && denominator == 1))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

bool fraction::operator==(fraction current)//������� ����������� ����� ��� ������ �� �����
{
	if (numenator == current.numenator && denominator == current.denominator)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool fraction::operator!=(fraction current)//������� ����������� ����� ��� ������ �� �����
{
	if (numenator != current.numenator && denominator != current.denominator)
	{
		return false;
	}
	else
	{
		return true;
	}
}


fraction fraction::operator+(fraction current)
{
	int new_numenator = numenator * current.denominator + denominator * current.numenator;
	int new_denominator = denominator * current.denominator;
	return fraction(new_numenator, new_denominator);
}

fraction fraction::operator-(fraction current)
{
	int new_numenator = numenator * current.denominator - denominator * current.numenator;
	int new_denominator = denominator * current.denominator;
	return fraction(new_numenator, new_denominator);
}

fraction fraction::operator*(fraction current)
{
	int new_numenator = numenator * current.numenator;
	int new_denominator = denominator * current.denominator;
	return fraction(new_numenator, new_denominator);
}

fraction fraction::operator/(fraction current)
{
	int new_numenator = numenator * current.denominator;
	int new_denominator = denominator * current.numenator;
	return fraction(new_numenator, new_denominator);
}

fraction fraction::lowterms(fraction current)
{
	fraction temp_fraction;
	long tnum, tden, temp, gcd;
	tnum = labs(current.numenator); 
	tden = labs(current.denominator);
	if (tden == 0)
	{ 
		cout << "Denomenator is zero";
		exit(1);
	}
	else if (tnum == 0)
	{
		current.numenator = 0;
		current.denominator = 1;
		//return ;
	}
	while (tnum != 0)
	{
		if (tnum < tden)
		{ 
			temp = tnum;
			tnum = tden;
			tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	current.numenator = current.numenator / gcd;
	current.denominator = current.denominator / gcd;

	temp_fraction.numenator = current.numenator;
	temp_fraction.denominator = current.denominator;

	return temp_fraction;
}

void fraction::lowterms_void()
{
	long tnum, tden, temp, gcd;
	tnum = labs(numenator);
	tden = labs(denominator);
	if (tden == 0)
	{
		cout << "Denomenator is zero";
		exit(1);
	}
	else if (tnum == 0)
	{
		numenator = 0;
		denominator = 1;
		return;
	}
	while (tnum != 0)
	{
		if (tnum < tden)
		{
			temp = tnum;
			tnum = tden;
			tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	numenator = numenator / gcd;
	denominator = denominator / gcd;
}
