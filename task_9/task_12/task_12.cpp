#include <iostream>

using namespace std;

int pmemory[100];
float fmemory[100];
int fmem_top = 0;
int pmem_top = 0;

class Float
{
private:
	int address;

public:
	Float(float f) {
		fmemory[fmem_top] = f;
		address = fmem_top++;
	}

	int operator&() {
		return address;
	}
};


class ptrFloat
{
private:
	int address;

public:
	ptrFloat(int p) {
		pmemory[pmem_top] = p;
		address = pmem_top++;
	}
	float& operator*()
	{
		return fmemory[pmemory[address]];
	}
};

int main() {

	Float var1 = 1.234;
	Float var2 = 5.678;
	ptrFloat ptr1 = &var1;
	ptrFloat ptr2 = &var2;

	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;

	*ptr1 = 7.123;
	*ptr2 = 8.456;
	
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	
	system("pause");
	
	return 0;
}