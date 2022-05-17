#include <iostream>
#include "book_time.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//publication pub1;
	book book1;
	tape tape1;

	//pub1.set_data();
	book1.setdata();
	tape1.setdata();

	cout << endl << endl;

	//pub1.get_data();
	book1.book::getdata();
	tape1.tape::getdata();

	return 0;
}
