#include <iostream>
using namespace std;
class Array {
private:
	int* ptr;
	int size;
public:
	Array() {
		size = 0; ptr = new int[size];
	}
	Array(int s) {
		size = s;
		ptr = new int[s];
	}
	Array(const Array& source_arr) {
		size = source_arr.size;
		//delete[] ptr;
		ptr = new int[source_arr.size];
		ptr = source_arr.ptr;
	}

	/*Array(const Array& sourse_arr)
	{

	}*/

	~Array() {
		delete[] ptr;
	}
	int& operator [] (int j) {
		return *(ptr + j);
	}
};
int main() {
	const int ASIZE = 10;
	Array arr(ASIZE);
	for (int j = 0; j < ASIZE; j++)
		arr[j] = j * j;
	for (int j = 0; j < ASIZE; j++)
		cout << arr[j] << ' ';
	cout << endl;
	Array arr2(arr), arr3;
	arr3 = arr;
	for (int j = 0; j < ASIZE; j++)
		cout << arr2[j] << ' ';
	cout << endl;
	for (int j = 0; j < ASIZE; j++)
		cout << arr3[j] << ' ';
	return 0;
}