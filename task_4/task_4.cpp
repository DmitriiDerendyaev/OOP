#include <iostream>
#include <cmath>

using namespace std;

char yesorno = 'y', letter;

float circarea(float rad)
{
	float area;
	area = pow(rad, 2) * 3.14;

	return area;
}

void task1()
{
	float r = 0;
	cout << "Для вычисления площади окружности введите РАДИУС: ";
	cin >> r;

	cout << "Площадь окружности при радиусе R = " << r << " равна: S = " << circarea(r) << endl;
}

double power(double num, int step = 2)
{
	double result_power = num;
	
	for (int i = 1; i < step; i++)
		result_power *= num;

	return result_power;
}

void task2()
{
	yesorno = 'y'; //char
	double num = 1;
	int step = 2;

	cout << "Вы хотите возвести число в степень отличную от числа 2?\n(y/n): ";
	cin >> yesorno;

	if (yesorno == 'y')
	{
		cout << "Введите число и показатель степени(use space): ";
		cin >> num >> step;
		cout << "Число " << num << " в степени " << step << " равняется: " << power(num, step) << endl;
	}
	else if (yesorno == 'n')
	{
		cout << "Введите число, которое вы хотите возвести во вторую степень: ";
		cin >> num;
		cout << "Число " << num << " в степени 2 равняется: " << power(num) << endl;
	}
	else
	{
		cout << "Введен некорректный ответ!";
	}
}

void zeroSmaller(int& first, int& second)
{
	if (first < second)
	{
		first = 0;
	}
	else
	{
		second = 0;
	}
}

void task3()
{
	int first, second;
	cout << "Введите 2 числа(use space): ";
	cin >> first >> second;

	zeroSmaller(first, second);

	cout << "После присваивания наименьшему значению 0, введенные числа выглядят так:\n Первое число: " << first << "\nВторое число: " << second << endl;

}

struct Distance
{
	int feet;
	float inches;
};

Distance max_distance(Distance first, Distance second)
{
	if (first.feet > second.feet)
	{
		return first;
	}
	else if ((first.feet == second.feet) and (first.inches > second.inches))
	{
		return first;
	}
	else
	{
		return second;
	}
}

void dist_disp(Distance dd)
{
	cout << dd.feet << '.' << dd.inches;
}

void task4()
{
	Distance d1, d2, d3;
	cout << "Введите первое значение (feet inches||use space): ";
	cin >> d1.feet >> d1.inches;

	cout << "Введите второе значение (feet inches||use space): ";
	cin >> d2.feet >> d2.inches;

	d3 = max_distance(d1, d2);

	cout << "\nПервое значение равно: "; dist_disp(d1);
	cout << "\nВторое значение равно: "; dist_disp(d2);
	cout << "\nМаксимальное значение равно: "; dist_disp(d3);
	cout << endl;
}

struct times
{
	int hours;
	int minutes;
	int seconds;
};

long hms_to_sec(times hms)
{
	long sum_sec;

	sum_sec = hms.hours * 3600 + hms.minutes * 60 + hms.seconds;

	return sum_sec;
}

long hms_to_sec(int hours, int minutes, int seconds)
{
	long sum_sec;

	sum_sec = hours * 3600 + minutes * 60 + seconds;

	return sum_sec;
}

void time_disp(times hms, char letter = ':')
{
	cout << hms.hours << letter << hms.minutes << letter << hms.seconds;
}

void task5()
{
	yesorno = 'y';//char

	times hms;
	int hours, minutes, seconds;


	while (yesorno == 'y')
	{
		cout << "Введите текущее время в формате(hh:mm:ss): ";
		cin >> hours >> letter >> minutes >> letter >> seconds;
		
		hms.hours = hours;
		hms.minutes = minutes;
		hms.seconds = seconds;

		time_disp(hms, letter);

		cout << " = " << hms_to_sec(hms) << "секунд\n\n";

		cout << "Хотите ввести еще одно значение?(y/n): ";
		cin >> yesorno;
	}
}

long time_to_secs(times hms)
{
	long sum_sec;

	sum_sec = hms.hours * 3600 + hms.minutes * 60 + hms.seconds;

	return sum_sec;
}

times secs_to_time(long seconds)
{
	times hms;

	hms.hours = (int)(seconds / 3600);
	hms.minutes = (seconds - hms.hours * 3600) / 60;
	hms.seconds = seconds - hms.hours * 3600 - hms.minutes * 60;

	return hms;
}

void task6()
{
	times first_enter, second_enter, total;
	char h;
	long totalsec2;

	cout << "Введите первую временную величину(12:12:12): ";
	cin >> first_enter.seconds >> h >> first_enter.minutes >> h >> first_enter.hours;

	cout << "Введите вторую временную величину(12:12:12): ";
	cin >> second_enter.seconds >> h >> second_enter.minutes >> h >> second_enter.hours;

	totalsec2 = time_to_secs(first_enter) + time_to_secs(second_enter);
	
	//cout << secs_to_time(totalsec2).hours << h << secs_to_time(totalsec2).minutes << h << secs_to_time(totalsec2).seconds << endl;
	time_disp(secs_to_time(totalsec2));
	cout << endl;
}

int power(int num, int step = 3)
{
	int result_power = num;

	for (int i = 1; i < step; i++)
		result_power *= num;

	return result_power;
}

float power(float num, int step = 4)
{
	float result_power = num;

	for (int i = 1; i < step; i++)
		result_power *= num;

	return result_power;
}

long power(long num, int step = 5)
{
	long result_power = num;

	for (int i = 1; i < step; i++)
		result_power *= num;	

	return result_power;
}

char power(char num, int step = 6)
{
	char result_power = num;

	for (int i = 1; i < step; i++)
		result_power *= num;

	return result_power;
}

void task7()
{
	double val_doub;
	int val_int;
	long val_long;
	char val_char;
	float val_float;

	cout << "Введите числа в необходимом формате(use only one parameter):";
	cout << "\nINT: ";
	cin >> val_int;

	cout << "\nDOUBLE: ";
	cin >> val_doub;

	cout << "\nFLOAT: ";
	cin >> val_float;

	cout << "\nLONG: ";
	cin >> val_long;

	cout << "\nCHAR: ";
	cin >> val_char;

	cout << "\n\nINT: " << power(val_int) << "\nDOUBLE: " << power(val_doub) << "\nFLOAT: " << 
		power(val_float) << "\nLONG: " << power(val_long) << "\nCHAR: " << power(val_char) << endl;

}

void swap(int& fir, int& sec)
{
	int temp;
	temp = fir;
	fir = sec;
	sec = temp;
}

void task8()
{
	int fir, sec;
	cout << "Введите числа, которые хотите поменять местами(use space): ";
	cin >> fir >> sec;

	swap(fir, sec);

	cout << "После обмена: " << fir << " " << sec << endl;
}

void swap(times& first_time, times& second_time)
{
	times temperate;
	temperate = first_time;
	first_time = second_time;
	second_time = temperate;
}

void task9()
{
	times first_time, second_time;

	cout << "Запущеена программа обмена значений времени...\n" << endl;
	cout << "Введите первое значение времени(00:00:00): ";
	cin >> first_time.hours >> letter >> first_time.minutes >> letter >> first_time.seconds;

	cout << "Введите второе значение времени(00:00:00): ";
	cin >> second_time.hours >> letter >> second_time.minutes >> letter >> second_time.seconds;

	swap(first_time, second_time);

	cout << "Время после обмена:\n";
	cout << "Первое значение времени: " << first_time.hours << letter << first_time.minutes << letter << first_time.seconds << endl;
	cout << "Второе значение времени: " << second_time.hours << letter << second_time.minutes << letter << second_time.seconds;



}

int counter = 0;

void counter_function_global()
{
	counter++;

	cout << "Функция была выведена на экран " << counter << " раз.\n\n";
}

void counter_function_static()
{
	static int counter_2 = 0;
	counter_2++;

	cout << "Функция была выведена на экран " << counter_2 << " раз.\n\n";
}

void task10()
{
	int amount_call = 0;

	cout << "Введите количество вызовов функции: ";
	cin >> amount_call;

	cout << "Использование ГЛОБАЛЬНОЙ переменной:\n\n";

	for (int i = 0; i < amount_call; i++)
	{
		counter_function_global();
	}

	cout << "Использование СТАТИЧЕСКОЙ переменной:\n\n";

	for (int i = 0; i < amount_call; i++)
	{
		counter_function_static();
	}
}

struct sterling
{
	int pounds;
	int shilling;
	int pence;
};

sterling get_sterling(sterling currency_unit)
{
	cout << "Введите денежную сумму($X.Y.Z): $";

	cin >> currency_unit.pounds >> letter >> currency_unit.shilling >> letter >> currency_unit.pence;

	return currency_unit;
}

//first_sum.pounds = (int)funtic;
//first_sum.shillings = (funtic ­ first_sum.pounds) * 20;
//first_sum.pence = (funtic ­ first_sum.pounds) * 20 * 12;

sterling sterling_addition(sterling first_unit, sterling second_unit)
{
	sterling folded_sterling;
	long int sum_pence;

	sum_pence = first_unit.pounds * 20 * 12 + first_unit.shilling * 12 + first_unit.pence + second_unit.pounds * 20 * 12 + second_unit.shilling * 12 + second_unit.pence;

	folded_sterling.pence = sum_pence % 12;
	folded_sterling.shilling = sum_pence / 12;
	folded_sterling.pounds = folded_sterling.shilling / 20;
	folded_sterling.shilling = folded_sterling.shilling % 20;

	return folded_sterling;
}

void print_sterling(sterling currency_unit, char letter)
{
	cout << "Полученная сумма: $";

	cout << currency_unit.pounds << letter << currency_unit.shilling << letter << currency_unit.pence << endl << endl;

}

void task11()
{
	sterling first_sum = {0,0,0}, second_sum = { 0,0,0 };


	//cout << "Первая сумма:\n";
	//get_sterling(first_sum);

	//cout << "\nВторая сумма:\n";
	//get_sterling(second_sum);

	print_sterling(sterling_addition(get_sterling(first_sum), get_sterling(second_sum)), letter);

}

struct fraction
{
	int chislit;
	int znamenat;
};

void get_fraction(fraction& first_fraction, fraction& second_fraction, char& operand)
{
	cout << "Введите первую дробь(XX/XX): ";
	cin >> first_fraction.chislit >> letter >> first_fraction.znamenat;

	cout << "Введите знак предполагаемой операции('+', '-', '*', '/'): ";
	cin >> operand;

	cout << "\nВведие вторую дробь(XX/XX): ";
	cin >> second_fraction.chislit >> letter >> second_fraction.znamenat;
}

fraction fraction_substraction(fraction first_fraction, fraction second_fraction)
{
	fraction result;

	result.chislit = (first_fraction.chislit * second_fraction.znamenat - first_fraction.znamenat * second_fraction.chislit);
	result.znamenat = first_fraction.znamenat * second_fraction.znamenat;

	return result;
}

fraction fraction_sum(fraction first_fraction, fraction second_fraction)
{
	fraction result;

	result.chislit = (first_fraction.chislit * second_fraction.znamenat + first_fraction.znamenat * second_fraction.chislit);
	result.znamenat = first_fraction.znamenat * second_fraction.znamenat;

	return result;
}

fraction fraction_multiplication(fraction first_fraction, fraction second_fraction)
{
	fraction result;

	result.chislit = first_fraction.chislit * second_fraction.chislit;
	result.znamenat = first_fraction.znamenat * second_fraction.znamenat;

	return result;
}

fraction fraction_division(fraction first_fraction, fraction second_fraction)
{
	fraction result;

	result.chislit = first_fraction.chislit * second_fraction.znamenat;
	result.znamenat = first_fraction.znamenat * second_fraction.chislit;

	return result;
}

void print_fraction(fraction result, char letter = '/')
{
	cout << "Результат вычислений: " << result.chislit << letter << result.znamenat;
}

char operand;

void task12()
{
	fraction first_fraction, second_fraction;
	//char operand;
	char request = 'y';
	letter = '/';

	get_fraction(first_fraction, second_fraction, operand);

	while (request == 'y')
	{
		switch (operand)
		{
		case '+':
		{
			print_fraction(fraction_sum(first_fraction, second_fraction));
			break;
		}
		case '-':
		{
			print_fraction(fraction_substraction(first_fraction, second_fraction));
			break;
		}
		case '*':
		{
			print_fraction(fraction_multiplication(first_fraction, second_fraction));
			break;
		}
		case '/':
		{
			print_fraction(fraction_division(first_fraction, second_fraction));
			break;
		}
		default:
			break;
		}
		cout << "Хотите повторить операцию?(y/n) \n Введите (y/n): ";
		cin >> request;

		if (request == 'y')
		{
			get_fraction(first_fraction, second_fraction, operand);
		}

	}




}




int main()
{
	setlocale(LC_ALL, "Russian");

	int task;
	bool flag_start;
	//float area = 0;

	cout << "FAQ: для выхода из программы введите 0." << endl;
	cout << "Введите номер задачи: ";
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
		cout << "Введите номер задачи: ";
		cin >> task;

	}

	system("pause");

	return 0;
}
