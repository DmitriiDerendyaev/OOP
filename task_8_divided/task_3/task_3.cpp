#include <iostream>
#include "class_file.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    book book1; // ���������� ����������
    tape tape1;
    book1.getdata(); // �������� �������� � �����������
    tape1.getdata();
    book1.putdata(); // ������� �������� � �����������
    tape1.putdata();
    cout << endl;
    return 0;
}
