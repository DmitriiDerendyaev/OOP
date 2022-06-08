//#include "stdafx.h"
#include <iostream>


using namespace std;

const int SZ = 10;

int main()
{
    int arr0[SZ], arr1[SZ], arr2[SZ], arr3[SZ], arr4[SZ],
        arr5[SZ], arr6[SZ], arr7[SZ], arr8[SZ], arr9[SZ];

    int* ap[SZ];

    for (int a = 0; a < SZ; a++)
        arr0[a] = a + 10;

    for (int b = 0; b < SZ; b++)
        arr1[b] = b + 20;

    for (int c = 0; c < SZ; c++)
        arr2[c] = c + 30;

    for (int d = 0; d < SZ; d++)
        arr3[d] = d + 40;

    for (int e = 0; e < SZ; e++)
        arr4[e] = e + 50;

    for (int f = 0; f < SZ; f++)
        arr5[f] = f + 60;

    for (int g = 0; g < SZ; g++)
        arr6[g] = g + 70;

    for (int h = 0; h < SZ; h++)
        arr7[h] = h + 80;

    for (int j = 0; j < SZ; j++)
        arr8[j] = j + 90;

    for (int i = 0; i < SZ; i++)
        arr9[i] = i + 100;

    ap[0] = arr0;
    ap[1] = arr1;
    ap[2] = arr2;
    ap[3] = arr3;
    ap[4] = arr4;
    ap[5] = arr5;
    ap[6] = arr6;
    ap[7] = arr7;
    ap[8] = arr8;
    ap[9] = arr9;


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < SZ; j++)
            cout << ap[i][j] << endl;
        cout << endl;
    }
        


    return 0;
}