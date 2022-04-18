//#include "stdafx.h"
#include <iostream>
#include <string.h>   // для функций strcpy, strcat
#include <stdlib.h>   // для функции exit
#include <string>
#include <cmath>
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

Distance Distance::operator+(Distance d2)// вернуть сумму
{
	int f = feet + d2.feet; // сложить футы
	float i = inches + d2.inches; // сложить дюймы
	if (i >= 12.0) // если сумма дюймов превышает 12.0,
	{ // уменьшить число дюймов
		i -= 12.0; // на 12.0 и 
		f++; // увеличить число футов н 1
	} // вернуть временное 
	return Distance(f, i);// значение расстояния, равное сумме
}

Distance Distance::operator-(Distance d2) // вернуть разность
{
	int f = feet - d2.feet; // разность футов
	float i = inches - d2.inches; // разность дюймов
	if (i < 0) // если число дюймов меньше 0,
	{ // увеличить их количество на 
		i += 12.0; // 12.0 и 
		f--; // уменьшить число футов на 1
	} // вернуть временное расстояние,
	return Distance(f, i); // равное разности
}

class String // пользовательский строковый тип
{
private:
	enum { SZ = 100 }; // размер объектов String
	char str[SZ]; // содержит С-строку
public:
	String() // конструктор без аргументов
	{
		strcpy_s(str, "");
	}
	String(char s[])
	{
		strcpy_s(str, s);
	}
	//String(char s[]) // конструктор с 1 аргументом
	//{
	//	strcpy(str, s);
	//}
	void display() // вывод строки
	{
		cout << str;
	}
	String operator+=(String ss)// прибавление строки к
	// имеющейся
	{// результат сохраняется в имеющейся строке
		if (strlen(str) + strlen(ss.str) >= SZ)
		{
			cout << "\nПереполнение строки"; exit(1);
		}
		strcat(str, ss.str);// добавить аргументную строку
		return String(str); // вернуть временный String
	}
};

class times
{
private:
	int hrs, mins, secs;
public:

	times() : hrs(0), mins(0), secs(0) // конструктор без аргум.
	{ } // конструктор с тремя аргументами
	times(int h, int m, int s) :hrs(h), mins(m), secs(s)
	{ }
	void display() // формат 11:59:59
	{
		cout << hrs << ":" << mins << ":" << secs << endl;
	}
	times operator+(times t2) // сложить два времени
	{
		int s = secs + t2.secs; // сложить секунды
		int m = mins + t2.mins; // сложить минуты
		int h = hrs + t2.hrs; // сложить часы
		if (s > 59) // если слишком много секунд,
		{
			s -= 60; m++;
		} // перенести их в одну минуту
		if (m > 59) // если слишком много минут,
		{
			m -= 60; h++;
		} // перенести их в один час
		return times(h, m, s); // вернуть временное значение
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
	Int() : i(0) // конструктор без аргументов
	{ }
	Int(int ii) :i(ii) // конструктор с одним аргументом
	{ } // (из int в Int)
	void putInt() // вывод Int
	{
		cout << i;
	}
	void getInt() // чтение Int с клавиатуры
	{
		cin >> i;
	}
	operator int() // операция преобразования
	{
		return i;
	} // (Int в int)
	Int operator+(Int i2) // сложение
	{
		return checkit(long double(i) + long double(i2));
	}
	Int operator-(Int i2) // вычитание
	{
		return checkit(long double(i) - long double(i2));
	}

	Int operator*(Int i2) // умножение
	{
		return checkit(long double(i) * long double(i2));
	}
	Int operator/(Int i2) // деление
	{
		return checkit(long double(i) / long double(i2));
	}
	Int checkit(long double answer) // проверка
	// результатов
	{
		if (answer > 2147483647.0L || answer < -2147483647.0L)
		{
			cout << "\nОшибка переполнения\n "; exit(1);
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

bool fraction::operator==(fraction current)//создать константные дроби для выхода из цикла
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

bool fraction::operator!=(fraction current)//создать константные дроби для выхода из цикла
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

class bMoney
{
private:
	string dollar;
	long double total;

	string strDollar;
	string signDollar;
	string clearDollar;
	long double first_value;
public:
	explicit bMoney() = default;
	long double mstold_get()
	{
		cout << "Enter a value of variable till sign $: ";
		getline(cin, dollar, '$');

		int value = dollar.length();
		int n = 0;

		string temp_number;

		for (int i = 0; i < value; i++)
		{
			if (dollar[i] != ',' && dollar[i] != '$')
			{
				temp_number.push_back(dollar[i]);
			}
		}
		total = stold(temp_number);

		return total;
	}
	operator double()
	{
		double double_dollar = total;
	}
	bMoney operator+(bMoney);
	bMoney operator-(bMoney);
	bMoney operator*(long double);//цена за единицу времени, затраченного на изделие
	long double operator/(bMoney);//Общая цена, деленная на цену за изделие
	bMoney operator/(long double);//Общая цена, деленная на кличество изделий

	void convertDollar_display()
	{
		strDollar += to_string(total);

		signDollar += '$';
		signDollar += strDollar;

		reverse(signDollar.begin(), signDollar.end());

		clearDollar += signDollar.substr(signDollar.find(',') - 2);

		if (clearDollar.size() > 5)
			clearDollar.insert(6, " ");
		else if (clearDollar.size() > 9)
			clearDollar.insert(10, " ");
		else if (clearDollar.size() > 13)
			clearDollar.insert(14, " ");
		else if (clearDollar.size() > 17)
			clearDollar.insert(18, " ");
		else if (clearDollar.size() > 21)
			clearDollar.insert(22, " ");

		reverse(clearDollar.begin(), clearDollar.end());

		cout << clearDollar << endl;
	}

};

bMoney bMoney::operator*(long double current)
{
	bMoney total_dollar;
	total_dollar.total = total * current;

	return total_dollar;
}

long double bMoney::operator/(bMoney current)
{
	long double total_dollar;
	total_dollar = total / current.total;

	return total_dollar;
}

bMoney bMoney::operator/(long double current)
{
	bMoney total_dollar;
	total_dollar.total = total / current;

	return total_dollar;
}

bMoney bMoney::operator+(bMoney current)
{
	bMoney total_dollar;
	total_dollar.total = total + current.total;

	return total_dollar;
}

bMoney bMoney::operator-(bMoney current)
{
	bMoney total_dollar;
	total_dollar.total = total - current.total;

	return total_dollar;
}

const int LIMIT = 100; //array size
////////////////////////////////////////////////////////////////
class safearay {
private: 
int arr[LIMIT]; 
int head;
int tail;

public:
	void set_range()
	{
		char spaces;
		int range;
		cout << "Введите верхний и нижний предел масссива. Величина массива <= 100(use enter): " << endl;
		cin >> head;
		cin >> tail;
		
		range = abs(tail - head);
		head = 0;
		tail = range;
	}
	int get_tail()
	{
		return tail;
	}
	int& operator [](int n) //note: return by reference
	{
		if (n < head || n > tail)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return arr[n];
	}
};

//class Polar
//{
//private:
//	float rad;
//	float angle;
//public:
//	Polar() : rad(0), angle(0)
//	{ }
//	Polar(float r, float a): rad(r), angle(a)
//	{ }
//	Polar(decart_coord decart);
//	void set_polar()
//	{
//		cout << "Enter a polar coordinates(rad angle): ";
//		cout << "Rad: "; cin >> rad;
//		cout << "Angle: "; cin >> angle;
//	}
//	void display_polar()
//	{
//		cout << "Rad: " << rad << endl;
//		cout << "Angle: " << angle << endl;
//	}
//	float get_rad()
//	{
//		return rad;
//	}
//	float get_angle()
//	{
//		return angle;
//	}
//
//};
//
//class decart_coord
//{
//private:
//	float x;
//	float y;
//public:
//	decart_coord() : x(0), y(0)
//	{ }
//	decart_coord(float x, float y) : x(x), y(y)
//	{ }
//	decart_coord(Polar pol);
//
//	decart_coord operator+(decart_coord);
//
//	float get_x()
//	{
//		return x;
//	}
//	float get_y()
//	{
//		return y;
//	}
//};
//
//decart_coord decart_coord::operator+(decart_coord current)
//{
//	float temp_x = x + current.x;
//	float temp_y = y + current.y;
//
//	return decart_coord(temp_x, temp_y);
//}
//
//Polar::Polar(decart_coord decart)
//{
//	float x = decart.get_x();
//	float y = decart.get_y();
//	angle = tan(y / x);
//	rad = hypot(x, y);
//}
//
//decart_coord::decart_coord(Polar pol)
//{
//	float angle = pol.get_angle();
//	float rad = pol.get_rad();
//	x = rad * cos(angle);
//	y = rad * sin(angle);
//}

class Polar;

class decart_coord {
private:
	float x;
	float y;
public:
	decart_coord();
	decart_coord(float x, float y);
	decart_coord(Polar pol);
	decart_coord operator+(decart_coord current);
	float get_x();
	float get_y();
};

#define PI 3.14159265

class Polar
{
private:
	float rad;
	float angle;
public:
	Polar() : rad(0), angle(0)
	{ }
	Polar(float r, float a) : rad(r), angle(a)
	{ }
	Polar(decart_coord decart) {
		float x = decart.get_x();
		float y = decart.get_y();
		//angle = atan(y / x) * 180 / PI;
		angle = atan(y / x);
		rad = hypot(x, y);
	}

	void set_polar()
	{
		cout << "Enter a polar coordinates(rad angle): ";
		cout << "Rad: "; cin >> rad;
		cout << "Angle: "; cin >> angle;
	}
	void display_polar()
	{
		cout << "Rad: " << rad << endl;
		cout << "Angle: " << angle << endl;
	}
	float get_rad()
	{
		return rad;
	}
	float get_angle()
	{
		return angle;
	}

};

decart_coord::decart_coord() : x(0), y(0) { }
decart_coord::decart_coord(float x, float y) : x(x), y(y) { }
decart_coord::decart_coord(Polar pol) {
	float angle = pol.get_angle();
	float rad = pol.get_rad();
	x = rad * cos(angle);
	y = rad * sin(angle);
}

decart_coord decart_coord::operator+(decart_coord current) {
	float temp_x = x + current.x;
	float temp_y = y + current.y;
	return decart_coord(temp_x, temp_y);
}

float decart_coord::get_x() {
	return x;
}

float decart_coord::get_y() {
	return y;
}

class sterling
{
private:
	long funt;
	int shilling;
	int pence;
public:
	sterling(): funt(0), shilling(0), pence(0)
	{ }
	sterling(double dec_funt)
	{
		funt = (int)dec_funt;
		shilling = (dec_funt - funt) * 20;
		pence = (dec_funt - funt) * 20 * 12;
	}
	sterling(long funt, int shilling, int pence): funt(funt), shilling(shilling), pence(pence)
	{ }
	sterling(bMoney exchange)
	{
		sterling exchanged_value = sterling(double(exchange) / 50);
		return exchanged_value;
	}
	void setSterling()
	{
		char letter;
		cout << "Enter a sum of sterling($9.19.11): $";
		cin >> funt >> letter >> shilling >> letter >> pence;
	}
	void getSterling()
	{
		char letter = '.';
		cout << "$" << funt << letter << shilling << letter << pence << endl << endl;
	}
	operator double()
	{
		double total_pence = funt * 20 * 12 + shilling * 20 + pence;
		return total_pence;
	}
	sterling operator+(sterling current)
	{
		return sterling(double(sterling(funt, shilling, pence)) + double(current));
	}
	sterling operator-(sterling current)
	{
		return sterling(double(sterling(funt, shilling, pence)) - double(current));
	}
	sterling operator*(double current)
	{
		return sterling(double(sterling(funt, shilling, pence)) * current);
	}
	sterling operator/(sterling current)
	{
		return sterling(double(sterling(funt, shilling, pence)) / double(current));
	}
	sterling operator/(double current)
	{
		return sterling(double(sterling(funt, shilling, pence)) / current);
	}

};
