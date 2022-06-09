Skip to content
Search or jump to…
Pull requests
Issues
Marketplace
Explore

@DmitriiDerendyaev
DmitriiDerendyaev
/
OOP
Private
Code
Issues
1
Pull requests
Actions
Projects
Security
Insights
Settings
OOP / task_8_divided / task_12 / expand_fraction.h

d.s.derendyaev good task_12, but it doesn't workkkk...
Latest commit 563bca1 21 days ago
History
0 contributors
197 lines(180 sloc)  5.17 KB

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

char symbol;

class Fraction
{
protected:
	int numerator;
	int denominator;
public:
	Fraction() { }
	Fraction(int n, int d) : numerator(n), denominator(d)
	{ }
	void get_fraction()
	{
		char slash;
		cin >> numerator >> slash >> denominator;
	}
	void display_fraction()const
	{
		cout << numerator << '/' << denominator;
	}
	Fraction operator + (Fraction current_value) {
		numerator = numerator * current_value.denominator + denominator * current_value.numerator;
		denominator = denominator * current_value.denominator;
		return Fraction(numerator, denominator);
	}
	Fraction operator - (Fraction current_value) {
		numerator = numerator * current_value.denominator - denominator * current_value.numerator;
		denominator = denominator * current_value.denominator;
		return Fraction(numerator, denominator);
	}
	Fraction operator * (Fraction current_value) {
		numerator = numerator * current_value.numerator;
		denominator = denominator * current_value.denominator;
		return Fraction(numerator, denominator);
	}
	Fraction operator / (Fraction current_value) {
		numerator = numerator * current_value.denominator;
		denominator = denominator * current_value.numerator;
		return Fraction(numerator, denominator);
	}
};

class divFraction : public Fraction {//âíóòðè õðàíÿòñÿ âîñüìûå ÷àñòè
public:
	divFraction() : Fraction() {}
	divFraction(int n) : Fraction(n, 8) {}//äðîáíàÿ ÷àñòü ïåííè	ïî 8
	operator double() const {
		return static_cast<double> (numerator) / denominator;
	}
};

class Sterling
{
protected:
	int pounds;
	int shilling;
	int pens;
public:
	Sterling() : pounds(), shilling(), pens()
	{ }
	Sterling(double funt_other)
	{
		pounds = static_cast<int>(funt_other);
		int temp_pounds = funt_other - pounds;
		shilling = static_cast<int>(temp_pounds * 20);
		pens = static_cast <int> ((funt_other - pounds) * 240 - shilling * 12);
	}
	Sterling(int po, int sh, int pe) : pounds(po), shilling(sh), pens(pe)
	{ }
	void getSterling()
	{
		cin >> pounds >> symbol >> shilling >> symbol >> pens;
	}
	void putSterling()const
	{
		cout << pounds << '.' << shilling << '.' << pens;
	}
	operator double() const
	{
		return (pounds + shilling / 20.0 + pens / 240.0);
	}

	Sterling getConvertedSterling(int sum_pens) {
		long x = sum_pens / 240;
		int y = sum_pens % (20 * 12) / 12;
		int z = sum_pens % (20 * 12) % 12;
		return Sterling(x, y, z);
	}

	Sterling operator+(Sterling);
	Sterling operator-(Sterling);
	Sterling operator*(double);
	Sterling operator/(Sterling);
	Sterling operator/(double);
};

Sterling Sterling::operator+(Sterling current_value)
{
	int sum_pens = (pounds * 240 + shilling * 12 + pens) + (current_value.pounds * 240 + current_value.shilling * 12 +
		current_value.pens);
	return (getConvertedSterling(sum_pens));
}

Sterling Sterling::operator-(Sterling current_value)
{
	int sum_pens = (pounds * 240 + shilling * 12 + pens) - (current_value.pounds * 240 + current_value.shilling * 12 +
		current_value.pens);
	return (getConvertedSterling(sum_pens));
}

Sterling Sterling::operator*(double current_value)
{
	int sum_pens = (pounds * 240 + shilling * 12 + pens) * (current_value);
	return (getConvertedSterling(sum_pens));
}

Sterling Sterling::operator/(Sterling current_value)
{
	int sum_pens = (pounds * 240 + shilling * 12 + pens) / (current_value.pounds * 240 + current_value.shilling * 12 +
		current_value.pens);
	return (getConvertedSterling(sum_pens));
}

Sterling Sterling::operator/(double value)
{
	int sum_pens = (pounds * 240 + shilling * 12 + pens) / (value);
	return (getConvertedSterling(sum_pens));
}

class sterfrac :public Sterling, public Fraction
{
private:
	divFraction amount_eights;
public:
	sterfrac() : Sterling(), amount_eights(0)//êîíñòðóêòîð ïî ìàòåðèíñêîìó êëàññó è çàïîëíåíèå êîëè÷åñòâà âîñüìûõ â íîëü
	{ }
	sterfrac(double other_funt)
	{
		pounds = other_funt;
		shilling = (other_funt - pounds) * 20;
		pens = ((other_funt - pounds) * 20 - shilling) * 12;
		amount_eights = static_cast<int>(round((((other_funt - pounds) * 20 - shilling) * 12 - pens) * 8));
	}
	sterfrac(int po, int sh, int pe, divFraction eights) : Sterling(po, sh, pe), amount_eights(eights)
	{ }
	void getSterling()
	{
		cout << "Ââåäèòå êîëè÷åñòâî â ôîðìàòå(X.XX.XX-Y/Y'): ";
		cin >> pounds >> symbol >> shilling >> pens;
		cin >> symbol;
		amount_eights.get_fraction();
	}
	void putSterling()const
	{
		Sterling::putSterling();
		cout << '-';
		amount_eights.display_fraction();
	}

	operator double() const {
		return (Sterling::operator double() + amount_eights / 240.0);
	}

	sterfrac operator+(sterfrac);
	sterfrac operator-(sterfrac);
	sterfrac operator*(double);
	double operator/(sterfrac);
	sterfrac operator/(double);
};

sterfrac sterfrac::operator+(sterfrac current_value)
{
	return sterfrac((double)*this + (double)current_value);
}

sterfrac sterfrac::operator-(sterfrac current_value)
{
	return sterfrac((double)*this - (double)current_value);
}
sterfrac sterfrac::operator*(double current_value)
{
	return sterfrac((double)*this * current_value);
}
double sterfrac::operator/(sterfrac current_value)
{
	return sterfrac((double)*this / (double)current_value);
}
sterfrac sterfrac::operator/(double current_value)
{
	return sterfrac((double)*this / current_value);
}
