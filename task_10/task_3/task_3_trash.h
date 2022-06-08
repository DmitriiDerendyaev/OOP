#include <iostream>
using namespace std;

class Distance {
private:
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0) {}//конструктор без аргумеентов
	Distance(float fltfeet) {//конструктор перевода из float в distace
		feet = static_cast<int>(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft, float in) : feet(ft), inches(in) {}//конструктор с двумя аргументами
	void showdist() {
		cout << feet << "\'-" << inches << '\"';
	}
	friend Distance operator * (Distance, Distance);//прототип дружественной перегрузки
};
Distance operator * (Distance d1, Distance d2) {
	float fltfeet1 = d1.feet + d1.inches / 12;
	float fltfeet2 = d2.feet + d2.inches / 12;
	float multfeet = fltfeet1 * fltfeet2;
	return Distance(multfeet);
}
int main() {
	Distance dist1(3, 6.0);
	Distance dist2(2, 3.0);
	Distance dist3;
	Distance Wdist;
	Wdist = dist3 * dist2;
	dist3 = dist1 * dist2;
	dist3 = 10.0 * dist3;
	cout << "dist1 = ";
	dist1.showdist();
	cout << "\ndist2 = ";
	dist2.showdist();
	cout << "\ndist3 = ";
	dist3.showdist();
	cout << "\nWdist = ";
	Wdist.showdist();
	return 0;
}