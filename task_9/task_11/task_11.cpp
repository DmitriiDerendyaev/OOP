#include <iostream>

using namespace std;


class MyClass
{
private:
    int** ap;
public:
    MyClass()
    {
        ap = new int* [10];
        for (int k = 0; k < 10; k++)
        {
            *(ap + k) = new int[10];
        }
    }
    ~MyClass()
    {
        for (int k = 0; k < 10; k++)
        {
            delete[] * (ap + k);
        }
        delete[] ap;
        cout << "Destructor has worked";
    }
    int& operator[] (int index)
    {
        int i = static_cast <int> (index / 10);
        int j = index % 10;
        return ap[i][j];
    }
};


void main()
{
    MyClass myobj;
    for (int i = 0; i < 100; i++) myobj[i] = i;
    for (int i = 0; i < 100; i++) cout << myobj[i] << ' ';
    system("pause");
}