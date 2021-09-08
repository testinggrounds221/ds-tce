#include<stdlib.h>
#include<stdio.h>

struct Queue {
	int* A;
	int front;
	int rear;
	int size;
};

struct Queue* createQueue(int s) {
	struct Queue* q = (struct Queue*)(calloc(1, sizeof(struct Queue)));
	q->front = -1;
	q->rear = -1;
	q->size = s;
	q->A = (int*)(1, calloc(q->size, sizeof(int)));
}

int isEmpty(struct Queue q) {
	return q.front == q.rear;
}

int isFull(struct Queue q) {
	return q.rear == q.size - 1;
}

void enqueue(struct Queue* q, int val) {
	if (isFull(*q)) return;
	q->A[++q->rear] = val;
}

int dequeue(struct Queue* q) {
	if (isEmpty(*q)) return -1;
	return q->A[++q->front];
}

int top(struct Queue q) {
	if (isEmpty(q)) return -1;
	return q.A[q.front + 1];
}


void traverse(struct Queue q) {
	if (isEmpty(q)) return;
	for (int i = q.front + 1;i <= q.rear;i++) {
		printf("%d ", q.A[i]);
	}
}
