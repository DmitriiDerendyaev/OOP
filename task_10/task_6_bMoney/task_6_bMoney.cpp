#include <iostream>
#include <string.h>   // для функций strcpy, strcat
#include <stdlib.h>   // для функции exit
#include <string>
#include <cmath>
#include <iomanip>
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


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
	bMoney(long double total_d) : total(total_d)
	{ }
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

	void display_dollar()
	{
		cout << setprecision(19) << "Dollar: $" << round(total) << endl;
		cout << "Dollar 30 Euro 40 k MAYU!" << endl;
	}


	friend bMoney operator * (long double value, bMoney b2) {
		bMoney total_dollar;
		total_dollar.total = value * b2.total;
		return total_dollar;
	}
	
	friend bMoney operator / (long double value, bMoney b2) {
		bMoney total_dollar;
		total_dollar.total = value / b2.total;
		return total_dollar;
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


void task11()
{
	bMoney mon1/*{100}*/;
	bMoney mon_result;

	mon1.mstold_get();

	mon_result = 30 * mon1;
	
	mon_result.display_dollar();

	mon_result = 1000 / mon1;

	mon_result.display_dollar();
}

int main()
{
	task11();

	return 0;
}