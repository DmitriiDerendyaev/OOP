#include <iostream>
#include <conio.h>

using namespace std;

struct phone
{
	int code; //3 digit
	int station;  //3 digit
	int abon; //4 digit
};

void task1()
{
	phone ph1 = { 922, 507, 1232 };
	phone ph2;

	cout << "Введите код оператора, основную часть и уникальную часть вашего номера: ";
	cin >> ph2.code >> ph2.station >> ph2.abon;

	cout << "Мой номер телефона: " << '(' << ph1.code << ") " << ph1.station << " - " << ph1.abon;
	cout << "\n Ваш номер телефона: " << '(' << ph2.code << ") " << ph2.station << " - " << ph2.abon << endl;

}

struct point
{
	int x;
	int y;
};

void task2()
{
	point p1;
	point p2;
	cout << "Введите координаты точки p1: ";
	cin >> p1.x >> p1.y;

	cout << "Введите координаты точки p2: ";
	cin >> p2.x >> p2.y;

	cout << "Сумма координат равна(p1 + p2): " << p1.x + p2.x << '.' << p1.y + p2.y << endl;
	}

struct Distance
{
	int feet;
	int inches;
};

struct Volume
{
	Distance lenght;
	Distance width;
	Distance height;
};

void task3()
{
	Volume room = { {5, 15.1}, {6, 12.7}, {7, 14.8} };

	float w = (float)room.width.feet + (float)room.width.inches / 12;
	float l = (float)room.lenght.feet + (float)room.lenght.inches / 12;
	float h = (float)room.height.feet + (float)room.height.inches / 12;

	float room_volume = w * l * h;

	cout << "Volume of my room is: " << room_volume << endl;
}

struct employee
{
	int number;
	float salary;
};

void task4()
{
	employee emp1, emp2, emp3;

	cout << "Введите номер 1-го сотрудника и его зарплату(use space): ";
	cin >> emp1.number >> emp1.salary;

	cout << "Введите номер 2-го сотрудника и его зарплату(use space): ";
	cin >> emp2.number >> emp2.salary;

	cout << "Введите номер 3-го сотрудника и его зарплату(use space): ";
	cin >> emp3.number >> emp3.salary;

	cout << '№' << emp1.number << " salary: " << emp1.salary << '$' << endl;
	cout << '№' << emp2.number << " salary: " << emp2.salary << '$' <<  endl;
	cout << '№' << emp3.number << " salary: " << emp3.salary << '$' << endl;
}

struct date
{
	int day;
	int month;
	int year;
};

void task5()
{
	date current_day;
	char c;

	cout << "Введите текущий день в формате(31/12/2022): ";
	cin >> current_day.day >> c >> current_day.month >> c >> current_day.year;

	cout << "Сегодня: " << current_day.day << c << current_day.month << c << current_day.year << endl;
}

enum etype { laborer, secretary, manager, accountant, executive, researcher};

void task6()
{
	etype chosen_word;
	char choose;
	cout << "List of profession:\nlaborer\nsecretary\nmanager\naccountant\nexecutive\nresearcher";
	cout << "Введите первую букву профессии: ";
	//choose = _getche();
	cin >> choose;


	switch (choose)
	{
	case 'l':
	{
		chosen_word = laborer;
		break;
	}
	case 's':
	{
		chosen_word = secretary;
		break;
	}
	case 'm':
	{
		chosen_word = manager;
		break;
	}
	case 'a':
	{
		chosen_word = accountant;
		break;
	}
	case 'e':
	{
		chosen_word = executive;
		break;
	}
	case 'r':
	{
		chosen_word = researcher;
		break;
	}
	default:
		break;
	}

	switch (chosen_word)
	{
	case 0:
	{
		cout << "laborer" << endl;
		break;
	}
	case 1:
	{
		cout << "secretary" << endl;
		break;
	}
	case 2:
	{
		cout << "manager" << endl;
		break;
	}
	case 3:
	{
		cout << "accountant" << endl;
		break;
	}
	case 4:
	{
		cout << "executive" << endl;
		break;
	}
	case 5:
	{
		cout << "researcher" << endl;
		break;
	}
	default:
		break;
	}
}

struct employee_2
{
	int number_2;
	float salary_2;
	etype prof;
	date start_work;
};

void task7()
{
	employee_2 worker, worker2, worker3;

	cout << "Введите номер сотрудника. №";
	cin >> worker.number_2;

	cout << "Введите величину зарплаты сотрудника. $";
	cin >> worker.salary_2;

	char choose, sim;
	cout << "List of profession:\nlaborer\nsecretary\nmanager\naccountant\nexecutive\nresearcher";
	cout << "Введите первую букву профессии: ";
	//choose = _getche();
	cin >> choose;
	switch (choose)
	{
	case 'l':
	{
		worker.prof = laborer;
		break;
	}
	case 's':
	{
		worker.prof = secretary;
		break;
	}
	case 'm':
	{
		worker.prof = manager;
		break;
	}
	case 'a':
	{
		worker.prof = accountant;
		break;
	}
	case 'e':
	{
		worker.prof = executive;
		break;
	}
	case 'r':
	{
		worker.prof = researcher;
		break;
	}
	default:
		break;
	}

	cout << "Введите дату приема сотрудника на работу в формате(31/12/2022): ";
	cin >> worker.start_work.day >> sim >> worker.start_work.month >> sim >> worker.start_work.year;

	//////////////////////второй сотрудник
	cout << "Введите номер сотрудника. №";
	cin >> worker2.number_2;

	cout << "Введите величину зарплаты сотрудника. $";
	cin >> worker2.salary_2;

	cout << "List of profession:\nlaborer\nsecretary\nmanager\naccountant\nexecutive\nresearcher";
	cout << "Введите первую букву профессии: ";
	//choose = _getche();
	cin >> choose;
	switch (choose)
	{
	case 'l':
	{
		worker2.prof = laborer;
		break;
	}
	case 's':
	{
		worker2.prof = secretary;
		break;
	}
	case 'm':
	{
		worker2.prof = manager;
		break;
	}
	case 'a':
	{
		worker2.prof = accountant;
		break;
	}
	case 'e':
	{
		worker2.prof = executive;
		break;
	}
	case 'r':
	{
		worker2.prof = researcher;
		break;
	}
	default:
		break;
	}

	cout << "Введите дату приема сотрудника на работу в формате(31/12/2022): ";
	cin >> worker.start_work.day >> sim >> worker.start_work.month >> sim >> worker.start_work.year;

	///////////третий сотрудник
	cout << "Введите номер сотрудника. №";
	cin >> worker3.number_2;

	cout << "Введите величину зарплаты сотрудника. $";
	cin >> worker3.salary_2;

	cout << "List of profession:\nlaborer\nsecretary\nmanager\naccountant\nexecutive\nresearcher";
	cout << "Введите первую букву профессии: ";
	//choose = _getche();
	cin >> choose;
	switch (choose)
	{
	case 'l':
	{
		worker3.prof = laborer;
		break;
	}
	case 's':
	{
		worker3.prof = secretary;
		break;
	}
	case 'm':
	{
		worker3.prof = manager;
		break;
	}
	case 'a':
	{
		worker3.prof = accountant;
		break;
	}
	case 'e':
	{
		worker3.prof = executive;
		break;
	}
	case 'r':
	{
		worker3.prof = researcher;
		break;
	}
	default:
		break;
	}

	cout << "Введите дату приема сотрудника на работу в формате(31/12/2022): ";
	cin >> worker3.start_work.day >> sim >> worker3.start_work.month >> sim >> worker3.start_work.year;
	
	////////вывод значений на экран
	//первый сотрудник

	cout << "Номер сотрудника. №" << worker.number_2 << endl;
	cout << "Зарплата сотрудника: $" << worker.salary_2 << endl;
	
	switch (worker.prof)
	{
	case 0:
	{
		cout << "laborer" << endl;
		break;
	}
	case 1:
	{
		cout << "secretary" << endl;
		break;
	}
	case 2:
	{
		cout << "manager" << endl;
		break;
	}
	case 3:
	{
		cout << "accountant" << endl;
		break;
	}
	case 4:
	{
		cout << "executive" << endl;
		break;
	}
	case 5:
	{
		cout << "researcher" << endl;
		break;
	}
	default:
		break;
	}

	cout << "Начало работы сотрудника: " << worker.start_work.day << '/' << worker.start_work.month << '/' << worker.start_work.year << endl << endl;

	//второй сотрудник

	cout << "Номер сотрудника. №" << worker2.number_2 << endl;
	cout << "Зарплата сотрудника: $" << worker2.salary_2 << endl;

	switch (worker2.prof)
	{
	case 0:
	{
		cout << "laborer" << endl;
		break;
	}
	case 1:
	{
		cout << "secretary" << endl;
		break;
	}
	case 2:
	{
		cout << "manager" << endl;
		break;
	}
	case 3:
	{
		cout << "accountant" << endl;
		break;
	}
	case 4:
	{
		cout << "executive" << endl;
		break;
	}
	case 5:
	{
		cout << "researcher" << endl;
		break;
	}
	default:
		break;
	}

	cout << "Начало работы сотрудника: " << worker2.start_work.day << '/' << worker2.start_work.month << '/' << worker2.start_work.year << endl << endl;
	
	//третий сотрудник

	cout << "Номер сотрудника. №" << worker3.number_2 << endl;
	cout << "Зарплата сотрудника: $" << worker3.salary_2 << endl;

	switch (worker3.prof)
	{
	case 0:
	{
		cout << "laborer" << endl;
		break;
	}
	case 1:
	{
		cout << "secretary" << endl;
		break;
	}
	case 2:
	{
		cout << "manager" << endl;
		break;
	}
	case 3:
	{
		cout << "accountant" << endl;
		break;
	}
	case 4:
	{
		cout << "executive" << endl;
		break;
	}
	case 5:
	{
		cout << "researcher" << endl;
		break;
	}
	default:
		break;
	}

	cout << "Начало работы сотрудника: " << worker3.start_work.day << '/' << worker3.start_work.month << '/' << worker3.start_work.year << endl << endl;

}

struct fraction
{
	int chislit;
	int znamenat;
};

void task8()
{
	fraction drob1, drob2;
	char c = 0;

	cout << "Введите первую дробь: ";
	cin >> drob1.chislit >> c >> drob1.znamenat;
	cout << "Введите вторую дробь: ";
	cin >> drob2.chislit >> c >> drob2.znamenat;

	cout << "Сумма равна: " << (drob1.chislit * drob2.znamenat + drob2.chislit * drob1.znamenat) << c << drob1.znamenat * drob2.znamenat << endl;
}

struct times
{
	int hours;
	int minutes;
	int seconds;
};

void task9()
{
	times cur_time;
	char e;

	long totalsec;

	cout << "Введите текущее время в формате(12:21:15): ";
	cin >> cur_time.seconds >> e >> cur_time.minutes >> e >> cur_time.hours;

	totalsec = cur_time.hours * 3600 + cur_time.minutes * 60 + cur_time.seconds;

	cout << "Итоговое количество секунд: " << totalsec << endl << endl;
	
}

struct sterling
{
	int pounds;
	int shillings;
	int pence;
};

void task10()
{
	sterling first_sum;
	double funtic;

	cout << "Введите сумму в фунтах(десятичная форма): ";
	cin >> funtic;

	first_sum.pounds = (int)funtic;
	first_sum.shillings = (funtic - first_sum.pounds) * 20;
	first_sum.pence = (funtic - first_sum.pounds) * 20 * 12;

	cout << '$' << first_sum.pounds << '.' << first_sum.shillings << '.' << first_sum.pence << endl;


}

void task11()
{
	times first_enter, second_enter, total;
	char h;
	long totalsec2;

	cout << "Введите первую временную величину(12:12:12): ";
	cin >> first_enter.seconds >> h >> first_enter.minutes >> h >> first_enter.hours;

	cout << "Введите вторую временную величину(12:12:12): ";
	cin >> second_enter.seconds >> h >> second_enter.minutes >> h >> second_enter.hours;

	totalsec2 = (first_enter.hours * 3600 + first_enter.minutes * 60 + first_enter.seconds) + second_enter.hours * 3600 + second_enter.minutes * 60 + second_enter.seconds;;

	total.hours = (int)(totalsec2 / 3600);
	total.minutes = (totalsec2 - total.hours * 3600) / 60;
	total.seconds = totalsec2 - total.hours * 3600 - total.minutes * 60;

	cout << total.seconds << h << total.minutes << h << total.hours << endl;
}



void task12()
{
	fraction first_drob, second_drob;
	char slash, operand, request_3 = 'y';

	cout << "Введите арифметическое выражение(символы через пробел): ";
	cin >> first_drob.chislit >> slash >> first_drob.znamenat >> operand >> second_drob.chislit >> slash >> second_drob.znamenat;

	while (request_3 != 'n')
	{
		switch (operand)
		{
		case '+':
		{
			cout << (first_drob.chislit * second_drob.znamenat + first_drob.znamenat * second_drob.chislit) << slash << first_drob.znamenat * second_drob.znamenat;
			break;
		}
		case '-':
		{
			cout << (first_drob.chislit * second_drob.znamenat - first_drob.znamenat * second_drob.chislit) << slash << first_drob.znamenat * second_drob.znamenat;
			break;
		}
		case '*':
		{
			cout << (first_drob.chislit * second_drob.chislit) << slash << first_drob.znamenat * second_drob.znamenat;
			break;
		}
		case '/':
		{
			cout << (first_drob.chislit * second_drob.znamenat) << slash << first_drob.znamenat * second_drob.chislit;
			break;
		}
		default:
			break;
		}
		cout << "Хотите повторить операцию?(y/n) \n Введите(y/n): ";
		cin >> request_3;
		if (request_3 == 'y')
		{
			cout << "Введите арифметическое выражение(символы через пробел): ";
			cin >> first_drob.chislit >> slash >> first_drob.znamenat >> operand >> second_drob.chislit >> slash >> second_drob.znamenat;
		}
	}

}



int main()
{
	setlocale(LC_ALL, "Russian");

	int task;

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
