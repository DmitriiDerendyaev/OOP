#include <iostream>
#include <string>                 //for string class
using namespace std;
////////////////////////////////////////////////////////////////
class person                      //class of persons
{
protected:
    string name;                //person's name
    float salary; 
public:
    void setData()              //set the name
    {
        cout << "Enter name: "; 
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void printData()            //display the name
    {
        cout << endl << "Name: " << name << endl;
        cout << endl << "Salary: " << salary << endl;
    }
    string getName()            //return the name
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    void salsort(person**, int);     //prototype
    person* persPtr[100];          //array of pointers to persons
    int n = 0;                     //number of persons in array
    char choice;                   //input char

    do {                           //put persons in array
        persPtr[n] = new person;    //make new object
        persPtr[n]->setData();      //set person's name
        n++;                        //count new person
        cout << "Enter another (y/n)? "; //enter another
        cin >> choice;              //   person?
    } while (choice == 'y');          //quit on 'n'

    cout << "\nUnsorted list:";
    for (int j = 0; j < n; j++)         //print unsorted list
    {
        persPtr[j]->printData();
    }

    //bsort(persPtr, n);             //sort pointers
    salsort(persPtr, n);

    cout << "\nSorted list:";
    for (int j = 0; j < n; j++)             //print sorted list
    {
        persPtr[j]->printData();
    }
    cout << endl;
    return 0;
}  //end main()
//--------------------------------------------------------------
// 
//--------------------------------------------------------------
void salsort(person** pp, int n)    //sort pointers to persons
{
    int j, k;                      //indexes to array

    for (j = 0; j < n - 1; j++)           //outer loop
        for (k = j + 1; k < n; k++)        //inner loop starts at outer
        {
            if ((*(pp + j))->getSalary() < (*(pp + k))->getSalary())
            {
                person* tempptr = *(pp+j);     //swap the pointers
                *(pp + j) = *(pp + k);
                *(pp + k) = tempptr;
            }
        }
            
            //order(pp + j, pp + k);       //order the pointer contents
}
//--------------------------------------------------------------
//void order(person** pp1, person** pp2)  //orders two pointers
//{                              //if 1st larger than 2nd,
//    if ((*pp1)->getName() > (*pp2)->getName())
//    {
//        person* tempptr = *pp1;     //swap the pointers
//        *pp1 = *pp2;
//        *pp2 = tempptr;
//    }
//}
