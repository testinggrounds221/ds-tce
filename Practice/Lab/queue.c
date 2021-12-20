#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int size;
	int front;
	int rear;
	int* Q;
};

void createQueue(struct Queue* q, int size) {
	q->Q = (int*)(malloc(size * sizeof(int)));
	q->size = size;
	q->front = q->rear = -1;
}

int isFull(struct  Queue* q) {
	if (q->rear == q->size - 1) return 1;
	return 0;
}

int isEmpty(struct  Queue* q) {
	if (q->front == q->rear) return 1;
	return 0;
}

void enqueue(struct  Queue* q, int num) {
	if (!isFull) return;
	q->rear++;
	q->Q[q->rear] = num;
}

int dequeue(struct Queue* q) {
	if (isEmpty(q))return -1;
	q->front++;
	int x = q->Q[q->front];
	return x;
}

void display(struct Queue* q) {
	for (int i = q->front + 1;i <= q->rear;i++) {
		printf("%d ", q->Q[i]);

	}
}

int main(int argc, char const* argv[])
{
	struct Queue* q = (struct Queue*)(malloc(sizeof(struct Queue)));
	createQueue(q, 10);
	enqueue(q, 9);
	enqueue(q, 8);
	enqueue(q, 7);
	enqueue(q, 6);
	enqueue(q, 5);
	enqueue(q, 4);
	enqueue(q, 3);
	enqueue(q, 2);
	enqueue(q, 1);
	display(q);

	return 0;
}
