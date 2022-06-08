#include <iostream>

using namespace std;

const int SZ = 10;

int main()
{
    setlocale(LC_ALL, "Russian");

    int compstr(const char*, const char*);

    char arr1[SZ];
    char arr2[SZ];

    cout << "¬ведите первую строку: ";
    cin >> arr1;

    cout << "¬ведите вторую строку: ";
    cin >> arr2;

    cout << compstr(arr1, arr2);
}

int compstr(const char* a, const char* b)
{
    while (*a && *b && (*a == *b))
    {
        a++; b++;
    }
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;
}
