#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	char ch;
};

struct Stck {
	struct Node* top;
};

struct Stck* createStck() {
	struct Stck* stk = (struct Stck*)(calloc(1, sizeof(struct Stck)));
	stk->top = NULL;
	return stk;
}

char stkTop(struct Stck stk) {
	if (!stk.top) return '\0';
	return stk.top->ch;
}


int isStkEmpty(struct Stck stk) {
	return stkTop(stk) == '\0';
}

void stkPush(struct Stck* stk, char ch) {
	struct Node* newNode = (struct Node*)(calloc(1, sizeof(struct Node)));
	newNode->ch = ch;
	newNode->next = stk->top;
	stk->top = newNode;
}

char stkPop(struct Stck* stk) {
	if (!stk->top) return '\0';
	struct Node* nd = stk->top;
	char c = stk->top->ch;
	stk->top = stk->top->next;
	free(nd);
	return c;
}

void traverse(struct Stck stk) {
	struct Node* nd = stk.top;
	while (nd) {
		printf("%c | ", nd->ch);
		nd = nd->next;
	}
}