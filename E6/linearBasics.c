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

void traverse(struct Queue q) {
	if (isEmpty(q)) return;
	for (int i = q.front + 1;i <= q.rear;i++) {
		printf("%d ", q.A[i]);
	}
}

int top(struct Queue q) {
	if (isEmpty(q)) return -1;
	return q.A[q.front + 1];
}

int main(int argc, char const* argv[])
{
	struct Queue* q = createQueue(3);
	int c = 0, val = 0;
	while (1) {
		printf("\n1.Enqueue 2.Dequeue 3.Traverse 4.Top\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("Value :	");
			scanf("%d", &val);
			enqueue(q, val);
			break;
		case 2:
			printf("%d", dequeue(q));
			break;
		case 3:
			traverse(*q);
			break;
		case 4:
			printf("%d", top(*q));
			break;
		}
	}
	printf("1.Enqueue 2.Dequeue 3.Traverse\n");
	enqueue(q, 10);
	enqueue(q, 11);
	enqueue(q, 12);
	enqueue(q, 13);
	enqueue(q, 14);
	enqueue(q, 15);
	traverse(*q);
	return 0;
}
