//Author Feyis kenenisa
// Implimentation of stack using linked list
#include "../linked list/LinkedList.h"
#include <iostream>
using namespace std;
class Stack : LinkedList<double> {
public:
	Stack() {}	// constructor
	~Stack() {}	// destructor
	double Top() { 
		if (head == NULL) {
			cout << "Error: the stack is empty." << endl;
			return -1;
		}
		else
			return head->value;
	}
	void Push(const double x) 
	{
		addNodeFront(x);
	}

	double Pop() { 
		if (head == NULL) {
			cout << "Error: the stack is empty." << endl;
			return -1;
		}
		else {
			double val = head->value;
			deleteNode(val);
			return val;
		}
	}
	void DisplayStack() 
	{ 
		displayList(); 	
	}
};

int main(void){
    Stack stack;
    stack.Push(2.5);
    stack.Push(7.9);
    stack.Push(12.6);
    cout << "Here are the initial values of stack:\n";
    stack.DisplayStack();
    stack.Pop();

}