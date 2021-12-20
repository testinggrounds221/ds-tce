#include<stdlib.h>
#include<stdio.h>

struct Q {
	int f;
	int r;
	int size;
	int* arr;
};

struct Q* newQ(int s) {
	struct Q* q = (struct Q*)(malloc(sizeof(struct Q)));
	q->r = q->f = -1;
	q->size = s;
	q->arr = (int*)(malloc(sizeof(int) * q->size));
}

int isEmpty(struct Q* q) {
	return q->f == q->r;
}

int isFull(struct Q* q) {
	return q->r == q->size - 1;
}


void enqueue(struct Q* q, int e) {
	if (isFull(q))return;
	q->arr[++q->r] = e;
}

int dequeue(struct Q* q) {
	if (isEmpty(q))return -1;
	return q->arr[++q->f];
}

int top(struct Q* q) {
	if (isEmpty(q)) return -1;
	return q->arr[q->f + 1];
}

void traverse(struct Q* q) {
	for (int i = q->f + 1;i <= q->r;i++) {
		printf("%d ", q->arr[i]);
	}
}

int main(int argc, char const* argv[])
{
	struct Q* q = newQ(10);
	for (int i = 0;i < 5;i++)
		enqueue(q, i);

	for (int i = 0;i < 5;i++)
		printf("%d", dequeue(q));

	for (int i = 0;i < 10;i++)
		enqueue(q, i + 20);
	traverse(q);
	printf("\nEND");
	return 0;
}
