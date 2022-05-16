#include <iostream>
#include "employ.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    manager man1;
    scientist sci1;
    laborer lab1;

    man1.getdata();
    sci1.getdata();
    lab1.getdata();

    cout << endl << endl;

    man1.putdata();
    sci1.putdata();
    lab1.putdata();

    return 0;
}
