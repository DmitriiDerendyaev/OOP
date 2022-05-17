// constructors in derived class
#include <iostream> 
using namespace std;
////////////////////////////////////////////////////////////////
class Counter {
protected: //NOTE: not private
	unsigned int count; //count 
public:
	Counter() : count(0) //constructor, no args
	{ }
	Counter(int c) : count(c) //constructor, one arg
	{ }
	unsigned int get_count() const //return count
	{
		return count;
	}
	Counter operator++() //incr count (prefix)
	{
		return Counter(++count);
	}
};
////////////////////////////////////////////////////////////////
class CountDn : protected Counter
{
public:
	CountDn() : Counter() //constructor, no args
	{ }
	CountDn(int c) : Counter(c) //constructor, 1 arg
	{ }
	CountDn operator --() //decr count (prefix)
	{
		return CountDn(--count);
	}
};

class CountAll : public CountDn
{
public:
	CountAll(): CountDn()
	{ }
	CountAll(int a): CountDn(a)
	{ }
	CountAll operator++(int)
	{
		return CountAll(CountDn::count++);
	}
	CountAll operator--(int)
	{
		return CountAll(CountDn::count--);
	}

	/*CountAll operator++(int)
	{
		CountAll temp = *this;
		++count;
		return temp;
	}

	CountAll operator--(int)
	{
		CountAll temp = *this;
		--count;
		return temp;
	}*/

	void print()
	{
		cout << count << endl;
	}
};