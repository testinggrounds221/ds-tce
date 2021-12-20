#include "string.h"
#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int val;
};

class StckLL {
public:
	int size;
	Node* top;

	StckLL();
	~StckLL();

	bool isEmpty();
	bool isFull();
	void traverse();
	void push(int ele);
	int peek(int pos);
	int stackTop();
	int pop();

};

int StckLL::stackTop() {
	if (!isEmpty()) return top->val;
	return -1;
}

StckLL::~StckLL() {
	Node* p = top;
	while (top) {
		top = top->next;
		delete p;
		p = top;
	}
}

StckLL::StckLL() {
	top = nullptr;
}

bool StckLL::isEmpty() {
	return !top;
}

void StckLL::push(int ele) {
	Node* temp = new Node;
	temp->val = ele;
	temp->next = top;
	top = temp;
}

int StckLL::pop() {
	if (isEmpty()) return -1;
	Node* p = top;
	int popVal = top->val;
	top = top->next;
	delete p;
	return popVal;
}


int isBalanced(char* exp) {
	StckLL st;
	for (int i = 0; i < strlen(exp); i++) {
		char ch = exp[i];
		if (ch == '{' || ch == '(' || ch == '[')
			st.push(ch);
		else if (ch == '}' || ch == ')' || ch == ']') {
			if (st.isEmpty()) return 0;
			if ((ch == '}' && st.stackTop() == '{') ||
				(ch == ')' && st.stackTop() == '(') ||
				(ch == ']' && st.stackTop() == '['))
				st.pop();
			else return 0;
		}
	}
	return st.isEmpty();
}

int main(int argc, char const* argv[])
{
	char* exp;
	gets(exp);
	cout << isBalanced(exp) << endl;
	// char A[] = "{([a+b]*[c-d])/e}";
	// cout << isBalanced(A) << endl;

	// char B[] = "([a+b]}*[c-d])/e";
	// cout << isBalanced(B) << endl;

	// char C[] = "{([{a+b]*[c-d])/e}";
	// cout << isBalanced(C) << endl;

	return 0;
}
// if ((ch == '}' && st.stackTop() == '{') ||
// 	(ch == ')' && st.stackTop() == '(') ||
// 	(ch == ']' && st.stackTop() == '[')) {	
// 	st.pop();
// }