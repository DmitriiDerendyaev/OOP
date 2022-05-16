#include <iostream>
#include "safe_array.h"

int main()
{
    new_safearay arr(10, 800);

    for (int i = 10; i < 800; i++)
        arr[i] = i * 10;
    for (int i = 10; i <= 800; i++)
        std::cout << "Element " << i << " is " << arr[i] << "\n";
    return 0;
}
