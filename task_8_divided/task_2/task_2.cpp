#include <iostream>
#include "pstring.h"

int main()
{
    Pstring s1{ "��� �����-����� ������� ������, �������, ��������, ��, ���, �����, -- �������� ������, ������������ SZ." };
    cout << "\ns1 ="; s1.display(); // ������� String
    Pstring s2{"� ��� ����������� ������."};// ���������� String
    cout << "\ns2 ="; s2.display(); // ������� String
    cout << endl;

    return 0;
}
