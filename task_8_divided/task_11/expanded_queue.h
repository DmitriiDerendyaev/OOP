#include <iostream>

using namespace std;

const int LIMIT = 100;

class coordinates
{
public:
	int x;
	int y;
	coordinates(){ }
	coordinates(int x, int y) : x(x), y(y)
	{ }
};

class Stack {
private:
	int array[LIMIT];
	int next;
public:
	Stack() : next() {}
	void push(int value) {
		if (next == LIMIT) {
			cout << "\nStack overflow\n";
		}
		array[next++] = value;
	}
	int pop() {
		if (next == 0) {
			cout << "\nStack is empty\n";
		}
		return array[--next];
	}
};
class pairStack : public Stack {
public:
	pairStack() : Stack() {}
	void push(coordinates current_pair) {
		Stack::push(current_pair.x);
		Stack::push(current_pair.y);
	}
	coordinates pop() {
		int y = Stack::pop();
		int x = Stack::pop();
		return coordinates(x, y);
	}

}; 
