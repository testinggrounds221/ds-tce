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
	q->front = -1;
	q->rear = -1;
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
	if (isFull(*q)) return;
	q->rear = (q->rear + 1) % q->size;
	q->A[q->rear] = val;
}

int dequeue(struct CircQueue* q) {
	if (isEmpty(*q)) {
		printf("Queue Empty");
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	return q->A[++q->front];
}

void traverse(struct CircQueue q) {
	printf("Elements Are : ");
	if (isEmpty(q)) return;
	for (int i = q.front + 1;i <= q.rear;i++) {
		printf("%d->", q.A[i]);
	}
	printf("\n");
}

int main(int argc, char const* argv[])
{
	struct CircQueue* q = createQueue(3);
	int c = 0, val = 0;
	while (1) {
		printf("1.Enqueue 2.Dequeue 3.Traverse\n");
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
		}
	}
	printf("\n1.Enqueue 2.Dequeue 3.Traverse\n");
	enqueue(q, 10);
	enqueue(q, 11);
	enqueue(q, 12);
	enqueue(q, 13);
	enqueue(q, 14);
	enqueue(q, 15);
	traverse(*q);
	return 0;
}
