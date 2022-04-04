#include <iostream>
#include <conio.h>

#include "class_to_task_5.h"

using namespace std;

const char ESC = 27;
const double TOLL = 0.5;

void task1()
{
    Int Int1(1);
    Int Int2(2);

    Int Int3;

    Int3.add(Int1, Int2);

    Int3.display();
}

//class tollBooth
//{
//private:
//    unsigned int totalCar;
//    double totalCash;
//public:
//    tollBooth : totalCar(0), totalCash(0.0)
//    { }
//    void payingCar()
//    {
//        totalCar++;
//        totalCash += TOLL;
//    }
//    void nopayCar()
//    {
//        totalCar++;
//    }
//    void display()
//    {
//        cout << "\nМашины: " << totalCar << ",\nДеньги: " << totalCash << endl;
//    }
//};

void task2()
{
    tollBooth booth1;
    char ch;

    cout << "\nНажмите 0 для машины без оплаты, "
        << "\n 1 для каждой оплачивающей машины, "
        << "\n Esc для выхода.\n ";

    do
    {
        ch = _getche();
        if (ch == '0')
        {
            booth1.payingCar();
        }
        if (ch == '1')
        {
            booth1.nopayCar();
        }
    } while (ch != ESC);
    booth1.display();
}

void task3()
{
    const times time1(1, 2, 3);
    const times time2(4, 5, 6);
    times time3;

    time3.add_times(time1, time2);
    cout << "Time3: ";
    time3.display_times();
    cout << endl;
}

void task4()
{
    employee emp_1(5, 0.0);
    employee emp_2;
    employee emp_3;

    emp_1.set_employee();
    emp_2.set_employee();
    emp_3.set_employee();

    emp_1.get_employee();
    emp_2.get_employee();
    emp_3.get_employee();
}

void task5()
{
    date first_date;

    first_date.set_date();
    first_date.get_date();
    
}

void task6()
{
    extended_employee emp_1, emp_2, emp_3;

    emp_1.putEmployee();
    emp_2.putEmployee();
    emp_3.putEmployee();

    emp_1.getEmployee();
    emp_2.getEmployee();
    emp_3.getEmployee();
}

void task7()
{
    char ch = 'y';
    angle EW_angle(149, 34.8, 'W'), NS_angle(17, 31.5, 'S');
    cout << "Координаты системной точки:\n";
    EW_angle.get_angle();
    NS_angle.get_angle();
    
    do
    {
        cout << "FAQ: Введите пару координат определенной точки.\nНажмите n для выхода их программы.\n";
        
        cout << "Введите координату точки восточного или западного направлений(E/W): ";
        EW_angle.set_angle();

        cout << "Введите координату точки северного или южного направлений(N/S): ";
        NS_angle.set_angle();

        EW_angle.get_angle();
        NS_angle.get_angle();

        cout << "Продолжаем?\n(y/n):";
        std::cin >> ch;

    } while (ch != 'n');
    
}

void task8()
{
    amountCall call_1, call_2, call_3;

    cout << call_1.get_number() << endl;
    cout << call_2.get_number() << endl;
    cout << call_3.get_number() << endl << endl;
    
    call_1.display_number();
    call_2.display_number();
    call_3.display_number();
}

void task9()
{
    char ch = 'y';
    fraction_action first_fraction, second_fraction, total_fraction;

    do
    {
        cout << "FAQ: Введите пару дробей.\nНажмите 'n' для выхода их программы.\n";

        cout << "Первая дробь:\n";
        first_fraction.set_fraction();

        cout << "Вторая дробь:\n";
        second_fraction.set_fraction();

        total_fraction.add_fraction(first_fraction, second_fraction);

        total_fraction.get_fraction();

        cout << "Продолжаем?\n(y/n):";
        std::cin >> ch;

    } while (ch != 'n');
}

void task10()
{
    ship ship_1, ship_2, ship_3;

    ship_1.set_ship();
    ship_2.set_ship();
    ship_3.set_ship();

    ship_1.get_ship();
    ship_2.get_ship();
    ship_3.get_ship();
    
}

void task11()
{
    fraction_action first_fraction, second_fraction, total_fraction;
    char operand = '+';
    char request = 'y';
    char letter = '/';

    first_fraction.set_fraction();
    second_fraction.set_fraction();
    cout << "Определите тип вычислений: ";
    std:: cin >> operand;

    while (request == 'y')
    {
        switch (operand)
        {
        case '+':
        {
            total_fraction.add_fraction(first_fraction, second_fraction);
            total_fraction.get_fraction();
            break;
        }
        case '-­':
        {
            total_fraction.fraction_substraction(first_fraction, second_fraction);
            total_fraction.get_fraction();
            break;
        }
        case '*':
        {
            total_fraction.fraction_multiplication(first_fraction, second_fraction);
            total_fraction.get_fraction();
            break;
        }
        case '/':
        {
            total_fraction.fraction_division(first_fraction, second_fraction);
            total_fraction.get_fraction();
            break;
        }
        default:
            break;
        }
        cout << "Хотите повторить операцию?(y/n) \n Введите (y/n): ";
        std::cin >> request;
        if (request == 'y')
        {
            first_fraction.set_fraction();
            second_fraction.set_fraction();
            cout << "Определите тип вычислений: ";
            std::cin >> operand;
        }
    }
}

void task12()
{
    fraction_action main_fraction, fraction_1, fraction_2, fraction_3;

    cout << "Таблица умножения:\n\n";

    fraction_1.set_fraction();
    main_fraction = fraction_1;
    for (int j = 1; j < main_fraction.get_fraction_zhamenat(); j++)
    {
        fraction_1.set_chislit(j);
        fraction_1.set_znamenat(main_fraction.get_fraction_zhamenat());
        fraction_1.disp_lowterms_fraction();
    }
    cout << endl << "----------------------------------" << endl;

    for (int i = 1; i < main_fraction.get_fraction_zhamenat(); i++)
    {
        fraction_2.set_chislit(i);
        fraction_2.set_znamenat(main_fraction.get_fraction_zhamenat());
        fraction_2.disp_lowterms_fraction();

        for (int j = 1; j < main_fraction.get_fraction_zhamenat(); j++)
        {
            fraction_1.set_chislit(j);
            fraction_1.set_znamenat(main_fraction.get_fraction_zhamenat());
            fraction_3.fraction_multiplication(fraction_1, fraction_2);
            fraction_3.disp_lowterms_fraction();
        }
        cout << endl;
    }
    
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int task;

    cout << "FAQ: для выхода из программы введите 0." << endl;
    cout << "Введите номер задачи: ";
    std::cin >> task;
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
            break; }
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
