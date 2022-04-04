#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double TOLL1 = 0.5;

class Int
{
private:
    int i;
public:
    Int()
    {
        i = 0;
    }
    Int(int new_i)
    {
        i = new_i;
    }
    void add(Int i2, Int i3)
    {
        i = i2.i + i3.i;
    }
    void display()
    {
        cout << "\nInt3 = " << i << endl;
    }

};

class tollBooth
{
private:
    unsigned int totalCar;
    double totalCash;
public:
    tollBooth() : totalCar(0), totalCash(0.0)
    { }
    void payingCar()
    {
        totalCar++;
        totalCash += TOLL1;
    }
    void nopayCar()
    {
        totalCar++;
    }
    void display()const
    {
        cout << endl << "Машины: " << totalCar << ",\nДеньги: " << totalCash << endl;
    }
};

class times
{
private:
    int hours;
    int minutes;
    int seconds;
    long int total_seconds;
public:
    times(): hours(), minutes(), seconds()
    { }
    times(int h, int m, int s): hours(h), minutes(m), seconds(s)
    { }
    void set_times(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void add_times(times first, times second)
    {
        total_seconds = first.hours * 3600 + first.minutes * 60 + first.seconds + second.hours * 3600 + second.minutes * 60 + second.seconds;
        
        hours = total_seconds / 3600;
        minutes = (total_seconds - (hours * 3600)) / 60;
        seconds = (total_seconds - (hours * 3600) - (minutes * 60));
    }
    void display_times()
    {
        cout << hours << ":" << minutes << ":" << seconds;
    }
};

class employee
{
private:
    int number;
    float salary;
public:
    employee(): number(0), salary(0.0)
    { }
    employee(int n, float s) : number(n), salary(s)
    { }
    void set_employee()
    {
        cout << "Введите номер сотрудника: ";
        cin >> number;

        cout << "Введите величину оклада сотрудника: ";
        cin >> salary;
    }
    void get_employee()
    {
        cout << "№" << number << "\nSalary: " << salary << endl;
    }
};

class date
{
private:
    int month;
    int day;
    int year;

    char ch;
public:
    void set_date()
    {
        cout << "Введите дату(12/12/12): ";
        cin >> day >> ch >> month >> ch >> year;
    }

    void get_date()
    {
        cout << "Entered date: " << day << ch << month << ch << year << endl;
    }
};

enum etype {laborer, secretary, manager, accountant, executive, researcher };


class extended_employee
{
private:
    date dateEmp;
    etype prof;
    int number;
    float salary;
    char choose;
public:
    void putEmployee()
    {
        cout << "Введите номер сотрудника: ";
        cin >> number;
        cout << "Введите величину оклада сотрудника: ";
        cin >> salary;
        cout << "Введите дату устройства сотрудника на работу: ";
        dateEmp.set_date();

        cout << "Введите первую букву профессии сотрудника: ";
        cin >> choose;
        switch (choose)
        {
        case 'l':
        {
            prof = laborer;
            break;
        }
        case 's':
        {
            prof = secretary;
            break;
        }
        case 'm':
        {
            prof = manager;
            break;
        }
        case 'a':
        {
            prof = accountant;
            break;
        }
        case 'e':
        {
            prof = executive;
            break;
        }
        case 'r':
        {
            prof = researcher;
            break;
        }
        default:
            break;
        }
    }

    void getEmployee()
    {
        cout << "№" << number << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date: ";
        dateEmp.get_date();

        cout << "Profession: ";
        switch (prof)
        {
        case laborer:
        {
            cout << "laborer" << endl;
            break;
        }
        case secretary:
        {
            cout << "secretary" << endl;
            break;
        }
        case manager:
        {
            cout << "manager" << endl;
            break;
        }
        case accountant:
        {
            cout << "accountant" << endl;
            break;
        }
        case executive:
        {
            cout << "executive" << endl;
            break;
        }
        case researcher:
        {
            cout << "researcher" << endl;
            break;
        }
        default:
            break;
        }
    }
};

class angle
{
private:
    int degrees;
    float minutes;
    char direction;
public:
    angle(int d, float m, char dir): degrees(d), minutes(m), direction(dir)
    { }
    void set_angle()
    {
        cout << "Введите координату(149°34.8' W): ";
        cout << "\nГрадусы: ";
        cin >> degrees;
        cout << "\nМинуты: ";
        cin >> minutes;
        cout << "Направление: ";
        cin >> direction;
    }
    void get_angle()
    {
        cout << degrees << '°' << minutes << "' " << direction << endl;
    }

};

class amountCall
{
private:
    int number;
    static int count_all;
public:
    amountCall()
    {
        count_all++;
        number = count_all;
    }
    int get_number()
    {
        return number;
    }
    void display_number()
    {
        cout << "Мой порядковый номер: " << number << endl;
    }
};

int amountCall::count_all = 0;

//struct fraction
//{
//    int chislit;
//    char slash;
//    int znam;  
//};

class fraction_action
{
private:
    int chislit;
    int znamenat;

    char slash;
    char operand;
public:
    /*fraction_action() : frac(0, '/', 0)
    { }*/
    void set_fraction()
    {
        cout << "Введите значение дроби(X / Y): ";
        cin >> chislit >> slash >> znamenat;
    }
    void add_fraction(fraction_action first, fraction_action second)
    {
        chislit = first.chislit * second.znamenat + first.znamenat * second.chislit;
        znamenat = first.znamenat * second.znamenat;
    }
    void get_fraction()
    {
        lowterms();
        cout << "Результат вычислений равен: " << chislit << '/' << znamenat << endl;
    }
    void lowterms();
    void fraction_substraction(fraction_action first_fraction, fraction_action second_fraction)
    {
        chislit = (first_fraction.chislit * second_fraction.znamenat - first_fraction.znamenat * second_fraction.chislit);
        znamenat = first_fraction.znamenat * second_fraction.znamenat;
    }
    void fraction_multiplication(fraction_action first_fraction, fraction_action second_fraction)
    {
        chislit = first_fraction.chislit * second_fraction.chislit;
        znamenat = first_fraction.znamenat * second_fraction.znamenat;
    }
    void fraction_division(fraction_action first_fraction, fraction_action second_fraction)
    {
        chislit = first_fraction.chislit * second_fraction.znamenat;
        znamenat = first_fraction.znamenat * second_fraction.chislit;
    }
    void increase_fraction(fraction_action& current_fraction)
    {
        current_fraction.chislit++;
    }
    void set_chislit(int number)
    {
        chislit = number;
    }
    void set_znamenat(int number)
    {
        znamenat = number;
    }
    int get_fraction_zhamenat()
    {
        return znamenat;
    }
    void disp_lowterms_fraction()
    {
        lowterms();
        cout << setw(5) << chislit << "/" << znamenat;
    }
};

void fraction_action::lowterms() //Сокращение дроби
{
    long tnum, tden, temp, gcd;
    tnum = labs(chislit); // Используем неотрицательные значения
    tden = labs(znamenat); // Нужен cmath 
    if (tden == 0)
    { // Проверка знаменателя
        cout << "Недопустимый знаменатель";
        exit(1);
    }
    else if (tnum == 0)
    {
        chislit = 0;
        znamenat = 1;
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
    chislit = chislit / gcd;
    znamenat = znamenat / gcd;
}

class ship
{
private:
    amountCall ship_number;
    angle EW_angle{ 0, 0.0, 'W' };
    angle NS_angle{ 0, 0.0, 'N' };
public:
    /*ship(amountCall num, angle EW, angle NS): ship_number(num), EW_angle(EW), NS_angle(NS)
    { }*/

    void set_ship()
    {
        cout << "Корабль №" << ship_number.get_number() << endl;
        EW_angle.set_angle();
        NS_angle.set_angle();
    }
    void get_ship()
    {
        cout << "Корабль №" << ship_number.get_number() << " расположен в точке с координатами:\n";
        EW_angle.get_angle();
        NS_angle.get_angle();
    }
};




