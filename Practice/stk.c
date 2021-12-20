#define SIZE 10
#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	char c;
};

struct Stk {
	int top;
	char arr[SIZE];
};

int isFull(struct Stk* s) {
	return s->top == (SIZE - 1) ? 1 : 0;
}

int isEmpty(struct Stk* s) {
	return s->top == -1;
}

struct Stk* createStk() {
	struct Stk* s = (struct Stk*)(malloc(sizeof(struct Stk)));
	s->top = -1;
	for (int i = 0; i < SIZE; i++)
	{
		s->arr[i] = ' ';
	}
	return s;
}

void push(struct Stk* s, char c) {
	if (isFull(s)) return;
	s->arr[++s->top] = c;
}

char pop(struct Stk* s) {
	if (isEmpty(s)) return '\0';
	return s->arr[s->top--];
}

char top(struct Stk* s) {
	if (isEmpty(s)) return '\0';
	return s->arr[s->top];
}

int checkBrackets(char* exp) {
	struct Stk* s = createStk();
	int i = 0;
	while (exp[i]) {
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(s, exp[i]);
		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
			if ((exp[i] == '}' && top(s) == '{')
				|| (exp[i] == ')' && top(s) == '(')
				|| (exp[i] == ']' && top(s) == '['))
				pop(s);
			else return 0;
		}
		i++;
	}
	if (!isEmpty(s)) return 0;
	return 1;
}

int ptBlnced(char* exp) {
	if (checkBrackets(exp)) printf("%s is Balanced\n", exp);
	else printf("%s is not balanced\n", exp);
}

int main(int argc, char const* argv[]) {
	// char wrd[20];
	// fgets(wrd, 20, stdin);

	struct Stk* s = createStk();
	printf("%d", isEmpty(s));
	push(s, 's');
	printf("%d", isEmpty(s));
	pop(s);
	printf("%d", isEmpty(s));
	// ptBlnced("([a+b]*c)/e");
	// ptBlnced("{([a+b]}*[c-d])/e}");
	// ptBlnced("{([{a+b]*[c-d])/e}");
	// printf("\nProgram Terminated\n");


	return 0;
}
