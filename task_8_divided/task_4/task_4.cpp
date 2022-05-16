#include <iostream>
#include "class_file.h"

int main()
{

    setlocale(LC_ALL, "Russian");
    book kniga;
    tape audio;
    disk diska;

    kniga.getdata();
    audio.getdata();
    diska.getdata();

    cout << endl << endl;

    kniga.putdata();
    audio.putdata();
    diska.putdata();
}
