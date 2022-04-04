#include <iostream>
#include <iomanip>
#include <vector>
#include <ctype.h>
#include <string>

#define fut 7.451
#define funt 1.487
#define frank 0.172
#define marka 0.584
#define yena 0.00955
#define shekel 0.31



using namespace std;

void task1()
{
	float gal;
	cout << "Введите количество галлонов: ";
	cin >> gal;

	cout << "Объем: " << gal * fut << " куб.фут" << endl;
}

void task2()
{
	int indent = 15;
	cout << 1990 << setw(indent) << 135 << endl << 1991 << setw(indent) << 7290 << endl
		<< 1992 << setw(indent) << 11300 << endl
		<< 1993 << setw(indent) << 16200 << endl;
}

void task3()
{
	int variable = 10;
	cout << variable << endl;
	variable *= 2;
	cout << variable-- << endl;
	cout << variable << endl;

}

void task4()
{
	cout << endl << "Сергей Есенин" << endl << endl;
	cout << "Мне осталась одна забава:" << endl << "Пальцы в рот - и веселый свист." << endl << "Прокатилась дурная слава," << endl << "Что похабник я и скандалист." << endl << endl <<
		"Ах! какая смешная потеря!" << endl << "Много в жизни смешных потерь." << endl << "Стыдно мне, что я в бога верил." << endl << "Горько мне, что не верю теперь." << endl << endl << 
		"Золотые, далекие дали!" << endl << "Все сжигает житейская мреть." << endl << "И похабничал я и скандалил" << endl << "Для того, чтобы ярче гореть." << endl << endl << 
		"Дар поэта - ласкать и карябать," << endl << "Роковая на нем печать." << endl << "Розу белую с черною жабой" << endl << "Я хотел на земле повенчать." << endl << endl << 
		"Пусть не сладились, пусть не сбылись" << endl << "Эти помыслы розовых дней." << endl << "Но коль черти в душе гнездились -" << "Значит, ангелы жили в ней." << endl << endl << 
		"Вот за это веселие мути," << endl << "Отправляясь с ней в край иной," << endl << "Я хочу при последней минуте" << endl << "Попросить тех, кто будет со мной,-" << endl << endl << 
		"Чтоб за все за грехи мои тяжкие," << endl << "За неверие в благодать" << endl << "Положили меня в русской рубашке" << endl << "Под иконами умирать." << endl << endl;
	return;
}

void task5()
{
	char letter;
	cout << "Введите символ: ";
	cin >> letter;
	int status = islower(letter);
	cout << status << endl;
}

void task6()
{
	int currency = 0;
	int indent = 15;
	string type_currency;
	cout << "Введите количество конвертируемой валюты: ";
	cin >> currency;
	cout << "\n Введите наименование конвертируемой валюты. \n Фунты - 'funt' \n Франки - 'frank' \n Марки - 'mark' \n Йены - 'yena' \n Шекели - 'shek' \n\n Валюта: ";
	cin >> type_currency;
	/*getline(cin, type_currency);*/
	/*if (type_currency != "funt" or type_currency != "mark" or type_currency != "frank" or type_currency != "yena" or type_currency != "shek")
	{
		cout << "Wrong input!" << endl;
		return;
	}*/
	cout << endl << currency << " " << type_currency << " равно: \n";
	if (type_currency == "funt")
	{
		cout << currency * funt << setw(indent) << "долларов\n";
	}
	else if (type_currency == "frank")
	{
		cout << currency * frank << setw(indent) << "долларов\n";
	}
	else if (type_currency == "mark")
	{
		cout << currency * marka << setw(indent) << "долларов\n";
	}
	else if (type_currency == "yena")
	{
		cout << currency * yena << setw(indent) << "долларов\n";
	}
	else if (type_currency == "shek")
	{
		cout << currency * shekel << setw(indent) << "долларов\n";
	}
	else
	{
		cout << "Wrong input!" << endl;
	}
}

void task7()
{
	int deg;
	cout << "Введите температуру в Цельсиях: ";
	cin >> deg;
	cout << "Температура по Фаренгейту: " << deg * 9 / 5 + 32 << endl;
}

void task8()
{
	int indent = 15;
	cout << 1990 << setfill('.') << setw(indent) << 135 << endl << 1991 << setw(indent) << 7290 << endl
		<< 1992 << setw(indent) << 11300 << endl
		<< 1993 << setw(indent) << 16200 << endl;
}

void task9()
{
	int ch1, ch2, zn1, zn2;
	char c = 0;
	cout << "Введите первую дробь: ";
	cin >> ch1 >> c >> zn1;
	cout << "Введите вторую дробь: ";
	cin >> ch2 >> c >> zn2;

	cout << "Сумма равна: " << (ch1 * zn2 + ch2 * zn1) << c << zn1 * zn2 << endl;
}

void task10()
{
	//1 фунт == 20 шиллингов
	//1 шиллинг == 12 пенсов
	float fu, shi, pen;
	int letter = 156;

	cout << "Введите количество фунтов:";
	cin >> fu;
	cout << "Введите количество Шиллингов:";
	cin >> shi;
	cout << "Введите количество Пенсов:";
	cin >> pen;

	float old_pen = pen + shi * 12;
	float new_pen = old_pen / 2.4;
	cout << (char)letter << fu << '.' << (int)round(new_pen) << endl;
}

void task11()
{
	cout << setiosflags(ios::left) << setw(12) << "Фамилия" << setw(12) << "Имя" << setw(20) << "Адрес" << setw(12) << "Город" << endl;
	
	cout << endl;

	cout << setfill(' ') << setw(12) << "Петров" << setw(12) << "Василий" << setw(20) << "Кленовая 16" << setw(12) << "Санкт-Петербург" << endl
		<< setw(12) << "Иванов" << setw(12) << "Сергей" << setw(20) << "Осиновая 3" << setw(12) << "Находка" << endl
		<< setw(12) << "Сидоров" << setw(12) << "Иван" << setw(20) << "Березовая 21" << setw(12) << "Калининград" << endl;
}

void task12()
{
	float new_fu, fu, shi, pen;
	int letter = 156;

	cout << "Введите число десятичных фунтов:";
	cin >> new_fu;

	fu = (int)new_fu;
	shi = (new_fu - fu) * 20;
	pen = (new_fu - fu) * 20 * 12;

	cout << (char)letter << fu << '.' << shi << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int task;
	bool flag_start;
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
