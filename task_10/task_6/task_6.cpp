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
	//int summ_of;
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
	sterling(long& sum) : pounds(sum / (20 * 12)), shilling(sum % (20 * 12) / 12), pens(sum % (20 * 12) % 12) {}
	long sum_p() {
		return pounds * 20 * 12 + shilling * 12 + pens;
	}

	long sum_return()
	{
		return pounds * 20 * 12 + shilling * 12 + pens;
	}
	friend sterling operator + (sterling, sterling&);
	friend sterling operator - (sterling, sterling&);
	friend sterling operator * (sterling, double);
	friend sterling operator / (sterling, sterling);
	friend sterling operator / (sterling, double);

	friend sterling operator*(long double, const sterling&);//new overload operators
	friend sterling operator/(long double, const sterling&);

	friend istream& operator >> (istream& is, sterling& w);
	friend ostream& operator << (ostream& os, sterling w);
};
sterling operator + (sterling first, sterling& second) {
	long sum = first.sum_p() + second.sum_p();
	return sterling(sum);
}
sterling operator - (sterling first, sterling& second) {
	long sum = first.sum_p() - second.sum_p();
	return sterling(sum);
}
sterling operator * (sterling first, double second) {
	long sum = first.sum_p() * second;
	return sterling(sum);
}
sterling operator / (sterling first, sterling second) {
	long sum = first.sum_p() / second.sum_p();
	return sterling(sum);
}
sterling operator / (sterling first, double second) {
	long sum = first.sum_p() / second;
	return sterling(sum);
}
ostream& operator << (ostream& output_stream, sterling current) {
	return output_stream << "f" << current.pounds << "." << current.shilling << "." << current.pens << endl;
}
istream& operator >> (istream& input_stream, sterling& current) {
	char q;
	return input_stream >> q >> current.pounds >> q >> current.shilling >> q >> current.pens;
}

///////////////////////////////////////////////

sterling operator*(long double val, const sterling& other) {
	return other * val;
}

sterling operator/(long double val, const sterling& other) {
	long total = other.pounds * 20 * 12 + other.shilling * 12 + other.pens;
	return sterling(val / total);///преобразовать в число
}


int main() 
{

	setlocale(0, "Russian");
	sterling ster{ 100.1 };
	cout << 30.3 * ster << "\n";
	cout << 200.2 / ster;

	return 0;
}