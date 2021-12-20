#include<stdlib.h>
#include<stdio.h>

struct CQ
{
	int f;
	int r;
	int size;
	int* arr;
};

int isFull(struct CQ* c) {
	return (c->r + 1) % c->size == c->f;
}

int isEmpty(struct CQ* c) {
	return c->f == c->r;
}

void enqueue(struct CQ* c, int e) {
	if (isFull(c)) {
		printf("Retur");
		return;
	}
	c->r = (c->r + 1) % c->size;
	c->arr[c->r] = e;
}

int dequeue(struct CQ* c) {
	if (isEmpty(c)) return -1;
	c->f = (c->f + 1) % c->size;
	return c->arr[c->f];
}

int top(struct CQ* c) {
	if (isEmpty(c)) return -1;
	return c->arr[(c->f + 1) % c->size];
}

struct CQ* newQ(int s) {
	struct CQ* CQ = (struct CQ*)(malloc(sizeof(struct CQ)));
	CQ->r = CQ->f = -1;
	CQ->size = s;
	CQ->arr = (int*)(malloc(sizeof(int) * CQ->size));
	return CQ;
}

void traverse(struct CQ* q) {
	for (int i = (q->f + 1) % q->size;i <= (q->r) % q->size;i = (i + 1) % q->size) {
		printf("%d ", q->arr[i]);
	}
}

int main(int argc, char const* argv[])
{
	struct CQ* q = newQ(10);
	// for (int i = 0;i < 5;i++)
	// 	enqueue(q, i);
	// traverse(q);
	// printf("\n");
	// for (int i = 0;i < 5;i++)
	// 	printf("%d", dequeue(q));

	for (int i = 10;i < 21;i++)
		enqueue(q, i);
	traverse(q);
	printf("\nEND");
	return 0;
}