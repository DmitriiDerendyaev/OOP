#include <iostream>
#include <string>
using namespace std;
class publication {
private:
	string title;
	float price;
public:
	virtual void getdata() {
		cout << "\nEnter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
	}
	virtual void putdata() {
		cout << "\n\nTitle: " << title;
		cout << "\nPrice: " << price;
	}
	virtual bool isOveersize() = 0;
};
class book : public publication {
private:
	int pages;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter number of pages: ";
		cin >> pages;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPages: " << pages;
	}
	bool isOveersize() {
		return (pages > 800);
	}
};
class tape : public publication {
private:
	float time;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter playing time: "; cin >> time;
	}
	void putdata() {
		publication::putdata();
		cout << "\nPlaying time: " << time;
	}
	bool isOveersize() {
		return (time > 90);
	}
};
int main() 
{
	setlocale(LC_ALL, "Russian");

	publication* pubarr[100];
	int n = 0;
	char user_choice;
	do {
		cout << "\nEnter data for book or tape (b/t)?";
		cin >> user_choice;
		if (user_choice == 'b')
			pubarr[n] = new book;
		else
			pubarr[n] = new tape;
		pubarr[n]->getdata();
		if (pubarr[n++]->isOveersize()) {
			cout << "Превышение размера!\n";
			delete pubarr[--n];
		}
		cout << "Enter another (y/n)?";
		cin >> user_choice;
	} while (user_choice == 'y');

	for (int j = 0; j < n; j++)
		pubarr[j]->putdata();
	return 0;
}