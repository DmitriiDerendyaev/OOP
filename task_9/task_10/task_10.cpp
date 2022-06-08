//#include "stdafx.h"
#include <iostream>


using namespace std;

const int SZ = 5;
const int NUMARRAYS = 100;

int main()
{
    int fill_point = 10;
    int* ap[NUMARRAYS];

    for (int j = 0; j < NUMARRAYS; j++)
        *(ap + j) = new int[SZ];

    for (int i = 0; i < NUMARRAYS; i++)
        for (int j = 0; j < SZ; j++)
            *(*(ap + i) + j) = fill_point++;

    for (int i = 0; i < NUMARRAYS; i++)
    {
        for (int j = 0; j < SZ; j++)
            cout << *(*(ap + i) + j) << endl;
        cout << endl;
    }
        

    return 0;
}