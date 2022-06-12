#include <iostream>
using namespace std;
struct link {
	int data;
	link* next;
};
class linklist {
private:
	link* first;
public:
	linklist() {
		first = NULL;
	}
	~linklist() {
		delete [] first;
	}
	void additem(int d);
	void display();
	linklist operator = (linklist q) {
		first = q.first;
	}
};
void linklist::additem(int d) {
	link* newlink = new link;
	newlink->data = d;
	if (first) {
		link* p = first;
		while (p->next)
			p = p->next;
		p->next = newlink;
	}
	else
		first = newlink;
	newlink->next = NULL;
}
void linklist::display() {
	link* current = first;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
int main() {
	linklist li;
	li.additem(25);
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display();
	linklist l = li;
	l.display();
	return 0;
}