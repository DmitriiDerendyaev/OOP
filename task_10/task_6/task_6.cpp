#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
class sterling {
private:
	int pounds;
	int shilling;
	int pens;
public:
	sterling() : pounds(0), shilling(0), pens(0) {}
	sterling(double funt_other)
	{
		pounds = static_cast<int>(funt_other);
		int temp_pounds = funt_other - pounds;
		shilling = static_cast<int>(temp_pounds * 20);
		pens = static_cast <int> ((funt_other - pounds) * 240 - shilling * 12);
	}
	sterling(int po, int sh, int pe) : pounds(po), shilling(sh), pens(pe)
	{ }
	sterling(long& sum) : f(sum / (20 * 12)), s(sum % (20 * 12) / 12), p(sum % (20 * 12) % 12) {}
	long sum_p() {
		return f * 20 * 12 + s * 12 + p;
	}
	friend sterling operator + (sterling, sterling&);
	friend sterling operator - (sterling, sterling&);
	friend sterling operator * (sterling, double);
	friend sterling operator / (sterling, sterling);
	friend sterling operator / (sterling, double);
	friend istream& operator >> (istream& is, sterling& w);
	friend ostream& operator << (ostream& os, sterling w);
};
sterling operator + (sterling w, sterling& q) {
	long sum = w.sum_p() + q.sum_p();
	return sterling(sum);
}
sterling operator - (sterling w, sterling& q) {
	long sum = w.sum_p() - q.sum_p();
	return sterling(sum);
}
sterling operator * (sterling w, double q) {
	long sum = w.sum_p() * q;
	return sterling(sum);
}
sterling operator / (sterling w, sterling q) {
	long sum = w.sum_p() / q.sum_p();
	return sterling(sum);
}
sterling operator / (sterling w, double q) {
	long sum = w.sum_p() / q;
	return sterling(sum);
}
ostream& operator << (ostream& os, sterling w) {
	return os << "f" << w.f << "." << w.s << "." << w.p << endl;
}
istream& operator >> (istream& is, sterling& w) {
	char q;
	return is >> q >> w.f >> q >> w.s >> q >> w.p;
}
int main() {
	setlocale(0, "Russian");
	while (true) {
		char error;
		sterling w;
		double f1;
		cout << "Введите сумму в десятичных фунтах: ";
		cin >> f1;
		cout << "Введите сумму в фунтах (в старой системе): ";
		cin >> w;
		cout << "+ = " << sterling(f1) + w;
		cout << "- = " << sterling(f1) - w;
		cout << "* = " << w * 7.0;
		cout << "/ = " << sterling(f1) / w;
		cout << "Продолжить? y/n: ";
		cin >> error;
		if (error == 'n')
			break;
	}
	return 0;
}