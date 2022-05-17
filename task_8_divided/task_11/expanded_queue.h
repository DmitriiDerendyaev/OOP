#include <iostream>

using namespace std;

const int LIMIT = 100;

class pair
{
public:
	int x;
	int y;
	pair(){ }
	pair(int x, int y) : x(x), y(y)
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
			std::cout << "\nStack overflow\n";
		}
		array[next++] = value;
	}
	int pop() {
		if (next == 0) {
			std::cout << "\nStack is empty\n";
		}
		return array[--next];
	}
};
class pairStack : public Stack {
public:
	pairStack() : Stack() {}
	void push(pair current_pair) {
		Stack::push(current_pair.x);
		Stack::push(current_pair.y);
	}
	pair pop() {
		int y = Stack::pop();
		int x = Stack::pop();
		return pair(x, y);
	}
}; class Stack {
private:
	int array[LIMIT];
	int next;
public:
	Stack() : next() {}
	void push(int value) {
		if (next == LIMIT) {
			std::cout << "\nStack overflow\n";
		}
		array[next++] = value;
	}
	int pop() {
		if (next == 0) {
			std::cout << "\nStack is empty\n";
		}
		return array[--next];
	}
};
class pairStack : public Stack {
public:
	pairStack() : Stack() {}
	void push(pair pair) {
		Stack::push(pair.x);
		Stack::push(pair.y);
	}
	pair pop() {
		int y = Stack::pop();
		int x = Stack::pop();
		return Pair(x, y);
	}
};