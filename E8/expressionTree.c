#include <string.h>
#include "stck.h"

int isOperator(char c) {
	if (c == '+' || c == '-' ||
		c == '*' || c == '/' ||
		c == '^')
		return 1;
	return 0;
}

void inorder(struct expTree* t) {
	if (t) {
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

struct expTree* newNode(char v) {
	struct expTree* temp = (struct expTree*)(malloc(sizeof(struct expTree)));
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}

struct expTree* constructTree(char postfix[]) {
	struct Stck* stk = createStck();
	struct expTree* t, * t1, * t2;
	for (int i = 0; i < strlen(postfix); i++) {
		if (!isOperator(postfix[i])) {
			t = newNode(postfix[i]);
			stkPush(stk, t);
		}
		else {
			t = newNode(postfix[i]);
			t1 = stkTop(*stk);
			stkPop(stk);
			t2 = stkTop(*stk);
			stkPop(stk);
			t->right = t1;
			t->left = t2;
			stkPush(stk, t);
		}
	}
	t = stkTop(*stk);
	stkPop(stk);
	return t;
}

int main() {
	char postfix[] = "ab+ef*g*-";
	struct expTree* r = constructTree(postfix);
	printf("infix expression is \n");
	inorder(r);
	return 0;
}