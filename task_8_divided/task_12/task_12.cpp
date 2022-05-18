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

    cout << "\n\n������ �������� � ���������� ��: " << double(first_value) << endl;
    cout << "������ �������� � ���������� ��: " << double(second_value) << endl;

    cout << "�������� :";
    (first_value + second_value).putSterling();

    cout << "\n\n���������: ";
    (first_value - second_value).putSterling();

    cout << "\n\n��������� �� 3:";
    (first_value * 3.0).putSterling();

    cout << "\n\n������� �� 2: ";
    (first_value / 2.0).putSterling();

    return 0;
}
