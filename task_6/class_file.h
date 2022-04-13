#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

using namespace std;

class employee
{
private:
	string name;
	long number;
public:
	employee() : name(), number()
	{ }
	void getdata()
	{
		cout << "Введите имя сотрудника: ";
		cin >> name;
		cout << "Введите номер сотрудника: ";
		cin >> number;
	}
	void putdata()
	{
		cout << number << ": " << name << endl;
	}
};

class Distance // класс английских расстояний
{
private:
	int feet;
	float inches;
public:
	Distance() // конструктор (без аргументов)
	{
		feet = 0; inches = 0;
	}
	Distance(int ft, float in)// конструктор (2 аргумента) 
	{
		feet = ft; inches = in;
	}
	void getdist() // получить расстояние 
	// от пользователя
	{
		cout << "\nВведите футы:"; cin >> feet;
		cout << "Введите дюймы:"; cin >> inches;
	}
	void showdist() // вывод расстояния
	{
		cout << feet << "\'-" << inches << '\"';
	}
	void add_dist(Distance, Distance);// объявления
	void div_dist(Distance, int);
};

void Distance::add_dist(Distance d2, Distance d3)
{
	inches = d2.inches + d3.inches;
	feet = 0;
	if (inches >= 12.0)
	{
		inches -= 12.0;
		feet++;
	}
	feet += d2.feet + d3.feet; 
}

void Distance::div_dist(Distance d2, int divisor)
{
	float fltfeet = d2.feet + d2.inches / 12.0;
	fltfeet /= divisor; 
	feet = int(fltfeet);
	inches = (fltfeet - feet) * 12.0;
}


class fraction
{
private:
	int numenator;
	int denominator;
public:
	fraction() : numenator(1), denominator(1)
	{ }
	fraction(int a, int b) : numenator(a), denominator(b)
	{ }
	void get_fraction()
	{
		char ch;
		cin >> numenator >> ch >> denominator;
	}
	
	/*void addition_fraction(fraction first, fraction second)
	{
		numenator = first.numenator * second.denominator + second.numenator * first.denominator;
		denominator = first.denominator * second.numenator;
	}*/

	/*fraction addition_fraction(fraction addition)
	{
		fraction temp;

		temp.numenator = addition.numenator * denominator + numenator * addition.denominator;
		temp.denominator = addition.denominator * numenator;

		return temp;
	}*/

	fraction addition_fraction(fraction addition)
	{
		fraction temp;

		temp.numenator = addition.numenator * denominator + numenator * addition.denominator;
		temp.denominator = addition.denominator * denominator;

		return temp;
	}


	void multiplication_fraction_by_number(fraction current_fraction, int amount)
	{
		denominator = current_fraction.denominator * amount;
	}
	
	void lowterms() //Сокращение дроби
	{
		long tnum, tden, temp, gcd;
		tnum = labs(numenator); // Используем неотрицательные значения
		tden = labs(denominator); // Нужен cmath 
		if (tden == 0)
		{ // Проверка знаменателя
			cout << "Недопустимый знаменатель";
			exit(1);
		}
		else if (tnum == 0)
		{
			numenator = 0;
			denominator = 1;
			return;
		}
		// Нахождение наибольшего общего делителя 
		while (tnum != 0)
		{
			if (tnum < tden)
			{ // Если числитель больше знаменателя, меняем их местами.
				temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;// Делим числитель и знаменатель на НОД. 
		numenator = numenator / gcd;
		denominator = denominator / gcd;
	}
	void display_fraction()
	{
		lowterms();
		cout << numenator << '/' << denominator << endl;
	}
};

enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
//////////////////////////////////////////////////////
class card
{
private:
	int number;
	Suit suit;
public:
	card() // конструктор
	{ }
	void set(int n, Suit s) // установка значения
	{
		suit = s; number = n;
	}
	void display(); // показ карты
};
/////////////////////////////////////////////////////////////
void card::display()
{
	if (number >= 2 && number <= 10)
		cout << number;
	else
	{
		switch (number)
		{
		case jack: cout << 'J'; break;
		case queen: cout << 'Q'; break;
		case king: cout << 'K'; break;
		case ace: cout << 'A'; break;
		}
	}
	switch (suit)
	{
	case clubs: cout << static_cast<char>(5); break;
	case diamonds: cout << static_cast<char>(4); break;
	case hearts: cout << static_cast<char>(3); break;
	case spades: cout << static_cast<char>(6); break;
	}
}

class dollarPadayPlizz
{
private:
	string strDollOchenMalenkiy;
	long double total;
public:
	long double mstold()
	{
		cout << "Введите строку гос.долга США, закончив строку знаком $: ";
		getline(cin, strDollOchenMalenkiy, '$');

		int value = strDollOchenMalenkiy.length();
		int n = 0;

		string temp_number;

		for (int i = 0; i < value; i++)
		{
			if (strDollOchenMalenkiy[i] != ',' && strDollOchenMalenkiy[i] != '$')
			{
				temp_number.push_back(strDollOchenMalenkiy[i]);
			}
		}
		total = stold(temp_number);
		
		return total;
	}
	void display_dollar()
	{
		cout << setprecision(19) << "Величина гос.долга США близка к сумме, равной: $" << total << endl;
		cout << "Dollar 30 Euro 40 k MAYU!" << endl;
	}

};

const int size_array = 10;

class safearay
{
private:
	int arr[size_array];
public:
	void putel(int n, int value)
	{
		if (n < 0 || n > size_array - 1)
		{
			cout << "WARNING!!! Stack overflow!" << endl;
			exit(1);
		}
		else
		{
			arr[n] = value;
		}
	}
	
	int getel(int n)
	{
		if (n < 0 || n > size_array - 1)
		{
			cout << "WARNING!!! Stack overflow!" << endl;
			exit(1);
		}
		else
		{
			return arr[n];
		}
	}
};

const int MAXIM = 5;

class Queue
{
private:
	int que[MAXIM]; // очередь в виде массива
	int head; // вершина очереди
	int tail;
public:
	Queue() // конструктор
	{
		head = -1;
		tail = -1;
	}

	bool isFull()
	{
		if (head == 0 && tail == MAXIM - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty()
	{
		if (head == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void put_queue(int var) // поместить в очередь
	{
		if (isFull())
		{
			cout << "\nStack overflow!" << endl;
			cout << var << " can't be inserted/" << endl;
		}
		else
		{
			if (head == -1)
			{
				head = 0;
			}
			tail = (tail + 1) % MAXIM;
			cout << "Inserted №" << tail << "; Val: " << var << endl;
			que[tail] = var;
		}
	}
	int get_queue() // взять из очереди
	{
		int temp;
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			temp = que[head];
			if (head == tail)
			{
				head = -1;
				tail = -1;
			}
			else
			{
				head = (head + 1) % MAXIM;
			}
			return temp;
		}
	}

	void display_queue()
	{
		int i;
		if (isEmpty())
		{
			cout << "Empty" << endl;
		}
		else
		{
			for (i = head; i != tail; i = (i + 1) % MAXIM)
			{
				cout << que[i];
			}
			cout << que[i];
		}
	}
};

const int matrix_size = 10;

class matrix
{
private:
	int martix_array[matrix_size][matrix_size];
	int rows, column;
public:
	matrix(int n, int m): rows(n), column(m)
	{ }
	void putel(int n, int m, int value)
	{
		if (n < 0 || n > matrix_size - 1 || m < 0 || m > matrix_size - 1)
		{
			cout << "WARNING!!! Stack overflow!" << endl;
			exit(1);
		}
		else
		{
			martix_array[n][m] = value;
		}
	}

	int getel(int n, int m)
	{
		if (n < 0 || n > matrix_size - 1 || m < 0 || m > matrix_size - 1)
		{
			cout << "WARNING!!! Stack overflow!" << endl;
			exit(1);
		}
		else
		{
			return martix_array[n][m];
		}
	}


};

class new_dollar
{
private:
	string strDollar;
	string signDollar;
	string clearDollar;
	long double first_value;
public:
	void set_value()
	{
		cout << "Введите сумму в долларах: ";
		cin >> first_value;
		if (first_value > 9999999999999990.00)
		{
			cout << "Too big number. Try to enter number smaller than it.";
			exit(1);
		}
	}
	void ldtoms()
	{
		strDollar += to_string(first_value);
	}

	void convertDollar()
	{
		signDollar += '$';
		signDollar += strDollar;
		
		reverse(signDollar.begin(), signDollar.end());

		clearDollar += signDollar.substr(signDollar.find(',') - 2);

		if(clearDollar.size() > 5)
			clearDollar.insert(6, " ");
		else if (clearDollar.size() > 9)
			clearDollar.insert(10, " ");
		else if (clearDollar.size() > 13)
			clearDollar.insert(14, " ");
		else if (clearDollar.size() > 17)
			clearDollar.insert(18, " ");
		else if (clearDollar.size() > 21)
			clearDollar.insert(22, " ");

		reverse(clearDollar.begin(), clearDollar.end());
	}

	void display_string()
	{
		cout << clearDollar << endl;
	}

};

class bMoney
{
private:
	string dollar;
	long double total;

	string strDollar;
	string signDollar;
	string clearDollar;
	long double first_value;
public:
	long double mstold_get()
	{
		cout << "Введите строку гос.долга США, закончив строку знаком $: ";
		getline(cin, dollar, '$');

		int value = dollar.length();
		int n = 0;

		string temp_number;

		for (int i = 0; i < value; i++)
		{
			if (dollar[i] != ',' && dollar[i] != '$')
			{
				temp_number.push_back(dollar[i]);
			}
		}
		total = stold(temp_number);

		return total;
	}

	bMoney* madd(bMoney first, bMoney second)
	{
		//bMoney result;

		total = first.total + second.total;

		return this;
	}

	void convertDollar_display(/*bMoney total*/)
	{
		strDollar += to_string(/*total.*/total);

		signDollar += '$';
		signDollar += strDollar;

		reverse(signDollar.begin(), signDollar.end());

		clearDollar += signDollar.substr(signDollar.find(',') - 2);

		if (clearDollar.size() > 5)
			clearDollar.insert(6, " ");
		else if (clearDollar.size() > 9)
			clearDollar.insert(10, " ");
		else if (clearDollar.size() > 13)
			clearDollar.insert(14, " ");
		else if (clearDollar.size() > 17)
			clearDollar.insert(18, " ");
		else if (clearDollar.size() > 21)
			clearDollar.insert(22, " ");

		reverse(clearDollar.begin(), clearDollar.end());
	
		cout << clearDollar << endl;
	}

};