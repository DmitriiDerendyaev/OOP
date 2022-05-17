#include <iostream>
#include "pstring_mod.h"

using namespace std;

int main() {
	Pstring2 s1 = "123456789";
	Pstring2 s2 = "";
	cout << "source string: " << s1 << endl;

	cout << "\nleft = ";
	s2 = s1.left(2);
	s2.display();

	cout << "\nright = ";
	s1.right(2).display();

	cout << "\nmid = ";
	s1.mid(3, 5).display();

	cout << endl;
	return 0;
}
