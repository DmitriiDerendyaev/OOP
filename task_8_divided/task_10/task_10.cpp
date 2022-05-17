#include <iostream>
#include "school_master.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	executive exec;

	exec.getdata();

	cout << endl;

	exec.putdata();
	return 0;
}
