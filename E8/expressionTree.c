#include <string.h>
#include "stck.h"

int isOperator(char ch) {
	if (ch == '+' || ch == '-' ||
		ch == '*' || ch == '/' ||
		ch == '^')
		return 1;
	return 0;
}

void traverseInorder(struct expTree* tree) {
	if (tree) {
		traverseInorder(tree->left);
		printf("%c ", tree->value);
		traverseInorder(tree->right);
	}
}

struct expTree* emptyNode(char v) {
	struct expTree* temp = (struct expTree*)(malloc(sizeof(struct expTree)));
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}

struct expTree* generateExpTree(char postfix[]) {
	struct Stck* stk = createStck();
	struct expTree* subTree, * rightSubTree, * leftSubTree;
	for (int i = 0; i < strlen(postfix); i++) {
		if (!isOperator(postfix[i])) {
			subTree = emptyNode(postfix[i]);
			stkPush(stk, subTree);
		}
		else {
			subTree = emptyNode(postfix[i]);
			rightSubTree = stkTop(*stk);
			stkPop(stk);
			leftSubTree = stkTop(*stk);
			stkPop(stk);
			subTree->right = rightSubTree;
			subTree->left = leftSubTree;
			stkPush(stk, subTree);
		}
	}
	subTree = stkTop(*stk);
	stkPop(stk);
	return subTree;
}

int main() {
	char postfix[] = "xy^5z*/1+";
	struct expTree* exTree = generateExpTree(postfix);
	printf("Infix Expression for %s is \n", postfix);
	traverseInorder(exTree);
	return 0;
}