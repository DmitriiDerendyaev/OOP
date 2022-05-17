#include "counter.h"
#include <iostream>

using namespace std;
int main()
{
	CountAll first;
	//CountDn second;

	first++;

	first.print();

	first--;

	first.print();

	++first;

	--first;

	return 0;
}

