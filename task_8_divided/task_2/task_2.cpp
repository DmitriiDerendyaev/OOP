#include <iostream>
#include "pstring.h"

int main()
{
    Pstring s1{ "Это очень-очень длинная строка, которая, возможно, да, нет, точно, -- превысит размер, ограниченный SZ." };
    cout << "\ns1 ="; s1.display(); // вывести String
    Pstring s2{"А это коротенькая строка."};// определить String
    cout << "\ns2 ="; s2.display(); // вывести String
    cout << endl;

    return 0;
}
