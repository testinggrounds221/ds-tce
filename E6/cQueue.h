#include<stdlib.h>
#include<stdio.h>

struct CircQueue {
	int* A;
	int front;
	int rear;
	int size;
};

struct CircQueue* createQueue(int s) {
	struct CircQueue* q = (struct CircQueue*)(calloc(1, sizeof(struct CircQueue)));
	q->front = 0;
	q->rear = 0;
	q->size = s;
	q->A = (int*)(1, calloc(q->size, sizeof(int)));
}

int isEmpty(struct CircQueue q) {
	return q.rear == q.front;
}

int isFull(struct CircQueue q) {
	return (q.rear + 1) % q.size == q.front;
}

void enqueue(struct CircQueue* q, int val) {
	if (isFull(*q)) {
		printf("Overfloe");
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->A[q->rear] = val;
}

int dequeue(struct CircQueue* q) {
	if (isEmpty(*q)) {
		printf("Queue Empty");
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	return q->A[q->front];
}

int top(struct CircQueue q) {
	if (isEmpty(q)) return -1;
	return q.A[(q.front + 1) % q.size];
}

void traverse(struct CircQueue q) {
	printf("Elements Are : ");
	if (isEmpty(q)) return;
	int i = q.front + 1;
	do {
		printf("%d->", q.A[i]);
		i = (i + 1) % q.size;
	} while (i != (q.rear + 1) % q.size);

}
