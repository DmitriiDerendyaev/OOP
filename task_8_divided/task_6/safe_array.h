#include <iostream>

using namespace std;

const int LIMIT = 100; //array size
////////////////////////////////////////////////////////////////
class safearay {
private: 
	int arr[LIMIT]; 
public:
	int& operator [](int n) //note: return by reference
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nIndex out of bounds"; exit(1);
		}
		return arr[n];
	}
};

class new_safearay : private safearay
{
private:
	int begin;
	int ended;
public:
	new_safearay(int a, int b) : begin(a), ended(b) 
	{ }
	int& operator [](int n)
	{
		if (n >= ended)
		{
			return safearay::operator[](LIMIT);
		}
		else
		{
			return safearay::operator[](n - begin);
		}
	}
};