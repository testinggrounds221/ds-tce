#include <stdio.h>
#include <stdlib.h>

struct expTree {
	char value;
	struct expTree* left, * right;
};

struct Node {
	struct Node* next;
	struct expTree* et;
};

struct Stck {
	struct Node* top;
};

struct Stck* createStck() {
	struct Stck* stk = (struct Stck*)(calloc(1, sizeof(struct Stck)));
	stk->top = NULL;
	return stk;
}

struct expTree* stkTop(struct Stck stk) {
	if (!stk.top) return NULL;
	return stk.top->et;
}


int isStkEmpty(struct Stck stk) {
	return stkTop(stk) == NULL;
}

void stkPush(struct Stck* stk, struct expTree* et) {
	struct Node* newNode = (struct Node*)(calloc(1, sizeof(struct Node)));
	newNode->et = et;
	newNode->next = stk->top;
	stk->top = newNode;
}

struct expTree* stkPop(struct Stck* stk) {
	if (!stk->top) return NULL;
	struct Node* nd = stk->top;
	struct expTree* et = stk->top->et;
	stk->top = stk->top->next;
	free(nd);
	return et;
}