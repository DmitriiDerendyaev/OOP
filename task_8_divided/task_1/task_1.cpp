#include <iostream>
#include "book_1.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//publication pub1;
	book book1;
	tape tape1;

	//pub1.set_data();
	book1.set_data();
	tape1.set_data();

	cout << endl << endl;

	//pub1.get_data();
	book1.get_data();
	tape1.get_data();

	return 0;
}
