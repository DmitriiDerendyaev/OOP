#include <iostream>
#include "class_file.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    book book1; // определить публикации
    tape tape1;
    book1.getdata(); // получить сведения о публикациях
    tape1.getdata();
    book1.putdata(); // вывести сведения о публикациях
    tape1.putdata();
    cout << endl;
    return 0;
}
