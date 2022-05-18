#include <iostream>
#include "expand_fraction.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    sterfrac first_value;
    sterfrac second_value;

    first_value.getSterling();
    second_value.getSterling();

    cout << "\n\nПервая величина в десятичной СС: " << double(first_value) << endl;
    cout << "Вторая величина в десятичной СС: " << double(second_value) << endl;

    cout << "Сложение :";
    (first_value + second_value).putSterling();

    cout << "\n\nВычитание: ";
    (first_value - second_value).putSterling();

    cout << "\n\nУмножение на 3:";
    (first_value * 3.0).putSterling();

    cout << "\n\nДеление на 2: ";
    (first_value / 2.0).putSterling();

    return 0;
}
