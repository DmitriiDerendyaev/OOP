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
	cout << "��� ���������� ������� ���������� ������� ������: ";
	cin >> r;

	cout << "������� ���������� ��� ������� R = " << r << " �����: S = " << circarea(r) << endl;
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

	cout << "�� ������ �������� ����� � ������� �������� �� ����� 2?\n(y/n): ";
	cin >> yesorno;

	if (yesorno == 'y')
	{
		cout << "������� ����� � ���������� �������(use space): ";
		cin >> num >> step;
		cout << "����� " << num << " � ������� " << step << " ���������: " << power(num, step) << endl;
	}
	else if (yesorno == 'n')
	{
		cout << "������� �����, ������� �� ������ �������� �� ������ �������: ";
		cin >> num;
		cout << "����� " << num << " � ������� 2 ���������: " << power(num) << endl;
	}
	else
	{
		cout << "������ ������������ �����!";
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
	cout << "������� 2 �����(use space): ";
	cin >> first >> second;

	zeroSmaller(first, second);

	cout << "����� ������������ ����������� �������� 0, ��������� ����� �������� ���:\n ������ �����: " << first << "\n������ �����: " << second << endl;

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
	cout << "������� ������ �������� (feet inches||use space): ";
	cin >> d1.feet >> d1.inches;

	cout << "������� ������ �������� (feet inches||use space): ";
	cin >> d2.feet >> d2.inches;

	d3 = max_distance(d1, d2);

	cout << "\n������ �������� �����: "; dist_disp(d1);
	cout << "\n������ �������� �����: "; dist_disp(d2);
	cout << "\n������������ �������� �����: "; dist_disp(d3);
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
		cout << "������� ������� ����� � �������(hh:mm:ss): ";
		cin >> hours >> letter >> minutes >> letter >> seconds;
		
		hms.hours = hours;
		hms.minutes = minutes;
		hms.seconds = seconds;

		time_disp(hms, letter);

		cout << " = " << hms_to_sec(hms) << "������\n\n";

		cout << "������ ������ ��� ���� ��������?(y/n): ";
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

	cout << "������� ������ ��������� ��������(12:12:12): ";
	cin >> first_enter.seconds >> h >> first_enter.minutes >> h >> first_enter.hours;

	cout << "������� ������ ��������� ��������(12:12:12): ";
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

	cout << "������� ����� � ����������� �������(use only one parameter):";
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
	cout << "������� �����, ������� ������ �������� �������(use space): ";
	cin >> fir >> sec;

	swap(fir, sec);

	cout << "����� ������: " << fir << " " << sec << endl;
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

	cout << "��������� ��������� ������ �������� �������...\n" << endl;
	cout << "������� ������ �������� �������(00:00:00): ";
	cin >> first_time.hours >> letter >> first_time.minutes >> letter >> first_time.seconds;

	cout << "������� ������ �������� �������(00:00:00): ";
	cin >> second_time.hours >> letter >> second_time.minutes >> letter >> second_time.seconds;

	swap(first_time, second_time);

	cout << "����� ����� ������:\n";
	cout << "������ �������� �������: " << first_time.hours << letter << first_time.minutes << letter << first_time.seconds << endl;
	cout << "������ �������� �������: " << second_time.hours << letter << second_time.minutes << letter << second_time.seconds;



}

int counter = 0;

void counter_function_global()
{
	counter++;

	cout << "������� ���� �������� �� ����� " << counter << " ���.\n\n";
}

void counter_function_static()
{
	static int counter_2 = 0;
	counter_2++;

	cout << "������� ���� �������� �� ����� " << counter_2 << " ���.\n\n";
}

void task10()
{
	int amount_call = 0;

	cout << "������� ���������� ������� �������: ";
	cin >> amount_call;

	cout << "������������� ���������� ����������:\n\n";

	for (int i = 0; i < amount_call; i++)
	{
		counter_function_global();
	}

	cout << "������������� ����������� ����������:\n\n";

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
	cout << "������� �������� �����($X.Y.Z): $";

	cin >> currency_unit.pounds >> letter >> currency_unit.shilling >> letter >> currency_unit.pence;

	return currency_unit;
}

//first_sum.pounds = (int)funtic;
//first_sum.shillings = (funtic � first_sum.pounds) * 20;
//first_sum.pence = (funtic � first_sum.pounds) * 20 * 12;

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
	cout << "���������� �����: $";

	cout << currency_unit.pounds << letter << currency_unit.shilling << letter << currency_unit.pence << endl << endl;

}

void task11()
{
	sterling first_sum = {0,0,0}, second_sum = { 0,0,0 };


	//cout << "������ �����:\n";
	//get_sterling(first_sum);

	//cout << "\n������ �����:\n";
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
	cout << "������� ������ �����(XX/XX): ";
	cin >> first_fraction.chislit >> letter >> first_fraction.znamenat;

	cout << "������� ���� �������������� ��������('+', '-', '*', '/'): ";
	cin >> operand;

	cout << "\n������ ������ �����(XX/XX): ";
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
	cout << "��������� ����������: " << result.chislit << letter << result.znamenat;
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
		cout << "������ ��������� ��������?(y/n) \n ������� (y/n): ";
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

	cout << "FAQ: ��� ������ �� ��������� ������� 0." << endl;
	cout << "������� ����� ������: ";
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
		cout << "������� ����� ������: ";
		cin >> task;

	}

	system("pause");

	return 0;
}
