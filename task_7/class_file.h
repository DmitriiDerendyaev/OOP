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
		strcpy(str, "");
	}
	String(char s[]) // конструктор с 1 аргументом
	{
		strcpy(str, s);
	}
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