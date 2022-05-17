#include <iostream> 
using namespace std;


const int LEN = 80; //maximum length of names
////////////////////////////////////////////////////////////////

class student //educational background
{
private:
	char school[LEN]; //name of school
	char degree[LEN];
public:
	void getedu()
	{
		cout << " Enter name of school or university: ";
		cin >> school;
		cout << " Enter highest degree earned \n";
		cout << " (Highschool, Bachelor's, Master's, PhD): ";
		cin >> degree;
	}
	void putedu() const
	{
		cout << "\n School or university: " << school;
		cout << "\n Highest degree earned: " << degree;
	}
};
////////////////////////////////////////////////////////////////
class employee {
private: 
	char name[LEN];
	unsigned long number; //employee number
public: void getdata() {
	cout << "\n Enter last name: "; 
	cin >> name;
	cout << " Enter number: "; 
	cin >> number;
}
	  void putdata() const
	  {
		  cout << "\n Name: " << name;
		  cout << "\n Number: " << number;
	  }
};
////////////////////////////////////////////////////////////////
class manager : private employee, private student //management
{
private:
	char title[LEN];
	double dues; //golf club dues
public: void getdata() {
	employee::getdata();
	cout << " Enter title: "; 
	cin >> title;
	cout << " Enter golf club dues: "; 
	cin >> dues;
	student::getedu();
}
void putdata() const
{
	employee::putdata(); 
	cout << "\n Title: " << title; 
	cout << "\n Golf club dues : " << dues; 
	student::putedu();
}
};

class executive : public manager
{
private:
	double prize;
	int stock;
public:
	void getdata()
	{
		manager::getdata();
		cout << "Введите размер премии: ";
		cin >> prize;
		cout << "Введите количество акций: ";
		cin >> stock;
	}
	void putdata()
	{
		manager::putdata();
		cout << "Размер премии: " << prize << endl;
		cout << "Количество акций: " << stock << endl;
	}
};