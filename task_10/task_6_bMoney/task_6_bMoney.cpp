//#include "stdafx.h"
#include <iostream>
#include <string.h>   // для функций strcpy, strcat
#include <stdlib.h>   // для функции exit
#include <string>
#include <cmath>
#include <iomanip>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class bMoney;

class sterling
{
private:
	long funt;
	int shilling;
	int pence;
	float dec_funtic;
public:
	sterling();
	sterling(double dec_funt);
	sterling(long funt, int shilling, int pence);
	sterling(bMoney exchange);
	void setSterling();
	void getSterling();
	long get_funt();
	int get_shilling();
	int get_pence();
	operator double();
	sterling operator+(sterling);
	sterling operator-(sterling);
	sterling operator*(double);
	sterling operator/(sterling);
	sterling operator/(double);
};

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
	bMoney(sterling exchange)//кааааак?
	{
		long fu = exchange.get_funt();
		int s = exchange.get_shilling();
		int pe = exchange.get_pence();
		total = (fu + (s * 12 + pe) / 2.4 / 100) * 50;
	}
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

	double get_double_dollar()
	{
		return total;
	}
	bMoney operator+(bMoney);
	bMoney operator-(bMoney);
	bMoney operator*(long double);//цена за единицу времени, затраченного на изделие
	long double operator/(bMoney);//Общая цена, деленная на цену за изделие
	bMoney operator/(long double);//Общая цена, деленная на кличество изделий

	friend bMoney operator*(long double, const bMoney&);
	friend bMoney operator/(long double, const bMoney&);

	friend std::ostream& operator<<(std::ostream& out, const bMoney& mon);

	void convertDollar_display()
	{
		strDollar += to_string(round(total));

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

	void display_dollar()
	{
		cout << setprecision(19) << "Dollar: $" << round(total) << endl;
		cout << "Dollar 30 Euro 40 k MAYU!" << endl;
	}

};


std::ostream& operator<<(std::ostream& out, const bMoney& mon) {
	out << mon.total;
}

bMoney operator*(long double val, const bMoney& other) {
	return other.total * val;//why
}

bMoney operator/(long double val, const bMoney& other) {
	return bMoney{ val / other.total };
}

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

int main()
{

	setlocale(0, "Russian");
	sterling ster{ 100.1 };
	cout << 30.3 * ster << "\n";
	cout << 200.2 / ster;

	return 0;
}

