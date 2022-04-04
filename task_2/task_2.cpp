#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <map>


using namespace std;

void task1()
{
	unsigned long n;

	cout << "\nEnter a number: ";
	cin >> n;
	for (int j = 1; j <= 200; j++)
	{
		cout << setw(5) << j * n << " ";
		if (j % 10 == 0)
			cout << endl;
	}
}

void task2()
{
	int response;
	double temper;
	cout << "\nType 1 to convert fahrenheit to celsius," << "\n2 to convert celsius to fahrenheit : "; 
		cin >> response;
	if( response == 1 )
	{
		cout << "Enter temperature in fahrenheit: "; cin >> temper;
		cout << "In celsius that's " << 5.0 / 9.0 * (temper - 32.0);
	}
	 else
	{
	cout << "Enter temperature in celsius: "; cin >> temper;
	cout << "In fahrenheit that's " << 9.0 / 5.0 * temper + 32.0;
	}
	cout << endl;
}

void task3()
{
	char ch; unsigned long total = 0;
	cout << "\nEnter a number: "; 
	while ((ch = _getche())!= '\r')
		//quit on Enter 
		total = total*10 + ch-'0'; //add digit to total*10
		cout << "\nNumber is: " << total	<< endl;
}

void task4()
{
	char request = 'y', oper;
	float a, b;
	while (request != 'n')
	{
		cout << "¬ведите операнд, операцию и еще один операнд через пробел: " << endl;
		cin >> a >> oper >> b;
		switch (oper)
		{
		case '*':
		{
			cout << a << " * " << b << " = " << a * b << endl;
			break;
		}
		case '+':
		{
			cout << a << " + " << b << " = " << a + b << endl;
			break;
		}
		case '-':
		{
			cout << a << " - " << b << " = " << a - b << endl;
			break;
		}
		case '/':
		{
			cout << a << " / " << b << " = " << a / b << endl;
			break;
		}
		default:
			break;
		}
		cout << "’отите повторить операцию?(y/n) \n ¬ведите(y/n): ";
		cin >> request;
	}
}

void task5()
{
	int amount;
	cout << "¬ведите количество строк: ";
	cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		cout << setw((amount - i)/2);
		cout << "X";
		for (int j = 1; j < i + 1; j++)
		{
			cout << "XX";
		}
		/*cout << " ";*/
		cout << endl;
	}
}

void task6()
{
	unsigned int numb; 
	unsigned long fact = 1;
	
	cout << "Enter a number: "; 
	cin >> numb;
	while (numb != 0)
	{
		for (int j = numb; j > 0; j--)
			fact *= j;
		cout << "Factorial is " << fact << endl;
		cout << "Enter a number: ";
		cin >> numb;
	}
}

void task7()
{
	float start_sum, percent;
	int amount_year;
	cout << "¬ведите начальную сумму вклада: ";
	cin >> start_sum;
	cout << "¬ведите количество лет: ";
	cin >> amount_year;
	cout << "¬ведите процентную ставку: ";
	cin >> percent;

	for (int current_year = 0; current_year < amount_year; current_year++)
	{
		start_sum = start_sum * (percent / 100 + 1);
	}

	cout << "„ерез " << amount_year << " лет вы получите: " << start_sum << endl;
}

void task8()
{
	int fu_1, shi_1, pen_1, fu_2, shi_2, pen_2, new_pen_1, new_pen_2, total_pen;
	char request = 'y';
	while (request != 'n')
	{
		cout << "¬ведите первую сумму(каждый разр€д через пробел): ";
		cin >> fu_1 >> shi_1 >> pen_1;

		cout << "¬ведите вторую сумму(каждый разр€д через пробел): ";
		cin >> fu_2 >> shi_2 >> pen_2;

		new_pen_1 = fu_1 * 20 * 12 + shi_1 * 12 + pen_1;
		new_pen_2 = fu_2 * 20 * 12 + shi_2 * 12 + pen_2;

		total_pen = new_pen_1 + new_pen_2;//total amount of penny

		pen_2 = total_pen % 12;
		shi_2 = total_pen / 12;
		fu_2 = shi_2 / 20;
		shi_2 = shi_2 % 20;

		cout << "¬сего: " << fu_2 << '.' << shi_2 << '.' << pen_2 << endl;

		cout << "’отите произвести еще один рассчет? \n ¬ведите ответ(y/n): ";
		cin >> request;
	}
	

}

void task9()
{
	int visitor_amount, chair_amount, variation_amount = 1;

	cout << "¬ведите количество приглашенных гостей: ";
	cin >> visitor_amount;
	cout << "¬ведите количество стульев в комнате: ";
	cin >> chair_amount;

	int visitor_amount_max = visitor_amount;

	for (visitor_amount; visitor_amount > visitor_amount_max - chair_amount; visitor_amount--)
	{
		variation_amount *= visitor_amount;
	}

	cout << " оличество возможных рассадок гостей: " << variation_amount << endl;
}

void task10()
{
	float start_sum, finish_sum, percent;
	int amount_years = 0;
	cout << "¬ведите начальную сумму вклада: ";
	cin >> start_sum;
	cout << "¬ведите планиуремую сумму: ";
	cin >> finish_sum;
	cout << "¬ведите процентную ставку: ";
	cin >> percent;

	while (start_sum < finish_sum)
	{
		start_sum = start_sum * (percent / 100 + 1);
		amount_years++;
	}

	cout << "„ерез " << amount_years << " лет вы получите: " << start_sum << endl;
}

string total(int pen_1, int pen_2, string oper)
{
	string total;
	int pen, shi, fu, total_pen;

	if (oper == "sum")
		total_pen = pen_1 + pen_2;
	else if (oper == "sub")
		total_pen = pen_1 - pen_2;
	else if (oper == "mult_first")
		total_pen = pen_1 * pen_2;
	else if (oper == "mult_second")
		total_pen = pen_1 * pen_2;
	else if (oper == "div_first")
		total_pen = pen_1 / pen_2;
	else if (oper == "div_second")
		total_pen = pen_1 / pen_2;

	pen = total_pen % 12;
	shi = total_pen / 12;
	fu = shi / 20;
	shi = shi % 20;

	total = '$' + to_string(fu) + '.' + to_string(shi) + '.' + to_string(pen);

	return total;
}

void task11()
{
	int fu_1, shi_1, pen_1, fu_2, shi_2, pen_2, new_pen_1, new_pen_2, total_pen;
	char request = 'y';
	//float a, b;
	string first;
	string second;
	int /*oper,*/ a;
	string user_choice;

	map <string, int> oper = { {"sum", 1},
							  {"sub", 2},
							  {"mult_first", 3},
							  {"mult_second", 4},
							  {"div_first", 5},
							  {"div_second", 6}};

	cout << "¬ведите первую сумму(каждый разр€д через пробел): ";
	cin >> fu_1 >> shi_1 >> pen_1;
	first = '$' + to_string(fu_1) + '.' + to_string(shi_1) + '.' + to_string(pen_1);

	cout << "¬ведите вторую сумму(каждый разр€д через пробел): ";
	cin >> fu_2 >> shi_2 >> pen_2;
	second = '$' + to_string(fu_2) + '.' + to_string(shi_2) + '.' + to_string(pen_2);

	new_pen_1 = fu_1 * 20 * 12 + shi_1 * 12 + pen_1;
	new_pen_2 = fu_2 * 20 * 12 + shi_2 * 12 + pen_2;

	while (request != 'n')
	{
		cout << "ƒл€ осуществлени€ операций введите ключевое слово: " << endl <<
			first << " + " << second << " - 'sum'" << endl << first << " - " << second << " - 'sub'" << endl <<
			first << " * " << "a - 'mult_first'" << endl << second << " * " << "a - 'mult_second'" << endl <<
			first << " / " << "a - 'div_first'" << endl << second << " / " << "a - 'div_second'" << endl << endl;
		/*cout << "ƒл€ осуществлени€ операций введите ключевое слово: " << endl <<
			first << " + " << second << " - '1'" << endl << first << " - " << second << " - '2'" << endl <<
			first << " * " << "a - '3'" << endl << second << " * " << "a - '4'" << endl <<
			first << " / " << "a - '5'" << endl << second << " / " << "a - '6'" << endl << endl;*/
		cout << "¬ведите ключевое слово и следуйте интсрукци€м: " << endl;
		//getline(cin, user_choice);
		//cin >> oper;
		cin >> user_choice;

		switch (oper[user_choice])
		{
		case 1:
		{
			cout << first << " + " << second << " = " << total(new_pen_1, new_pen_2, "sum") << endl;
			break;
		}
		case 2:
		{
			cout << first << " - " << second << " = " << total(new_pen_1, new_pen_2, "sub") << endl;
			break;
		}
		
		case 3:
		{
			cout << "¬ведите множитель A: ";
			cin >> a;
			cout << first << " * " << a << " = " << total(new_pen_1, a, "mult_first") << endl;
			break;
		}
		case 4:
		{
			cout << "¬ведите множитель A: ";
			cin >> a;
			cout << second << " * " << a << " = " << total(new_pen_2, a, "mult_second") << endl;
			break;
		}
		case 5:
		{
			cout << "¬ведите множитель A: ";
			cin >> a;
			cout << first << " / " << a << " = " << total(new_pen_1, a, "div_first") << endl;
			break;
		}
		case 6:
		{
			cout << "¬ведите множитель A: ";
			cin >> a;
			cout << second << " / " << a << " = " << total(new_pen_2, a, "div_second") << endl;
			break;
		}
		default:
			break;
		}
		cout << "’отите повторить операцию?(y/n) \n ¬ведите(y/n): ";
		cin >> request;
	}
}

void task12()
{
	int a, b, c, d;
	char slash, operand, request_3 = 'y';
	cout << "¬ведите арифметическое выражение(символы через пробел): ";
	cin >> a >> slash >> b >> operand >> c >> slash >> d;

	while (request_3 != 'n')
	{
		switch (operand)
		{
		case '+':
		{
			cout << (a * d + b * c) << slash << b * d;
			break;
		}
		case '-':
		{
			cout << (a * d - b * c) << slash << b * d;
			break;
		}
		case '*':
		{
			cout << (a * c) << slash << b * d;
			break;
		}
		case '/':
		{
			cout << (a * d) << slash << b * c;
			break;
		}
		default:
			break;
		}
		cout << "’отите повторить операцию?(y/n) \n ¬ведите(y/n): ";
		cin >> request_3;
		if (request_3 == 'y')
		{
			cout << "¬ведите арифметическое выражение(символы через пробел): ";
			cin >> a >> slash >> b >> operand >> c >> slash >> d;
		}
	}
	
}


	int main()
	{
		setlocale(LC_ALL, "Russian");

		int task;
		
		cout << "FAQ: дл€ выхода из программы введите 0." << endl;
		cout << "¬ведите номер задачи: ";
		cin >> task;

		while (task != 0)
		{
			switch (task)
			{
			case 1:
			{
				task1();
				break;
			}
			case 2:
			{
				task2();
				break;
			}
			case 3:
			{
				task3();
				break;
			}
			case 4:
			{
				task4();
				break;
			}
			case 5:
			{
				task5();
				break;
			}
			case 6:
			{
				task6();
				break;
			}
			case 7:
			{
				task7();
				break;
			}
			case 8:
			{
				task8();
				break;
			}
			case 9:
			{
				task9();
				break;
			}
			case 10:
			{
				task10();
				break;
			}
			case 11:
			{
				task11();
				break;
			}
			case 12:
			{
				task12();
				break;
			}
			}
			cout << "¬ведите номер задачи: ";
			cin >> task;

		}

		system("pause");

		return 0;
	}