#include<stdlib.h>
#include<stdio.h>

struct Node {
	struct Node* left;
	int val;
	struct Node* right;
};

struct Queue {
	int* A;
	int front;
	int rear;
	int size;
};

struct QueueNode {
	struct Node** A;
	int front;
	int rear;
	int size;
};

struct QueueNode* createQueue(int s) {
	struct QueueNode* q = (struct QueueNode*)(calloc(1, sizeof(struct QueueNode)));
	q->front = -1;
	q->rear = -1;
	q->size = s;
	q->A = (struct Node**)(malloc(sizeof(struct Node*)));
	return q;
}

int isEmpty(struct QueueNode* q) {
	return q->front == q->rear;
}

int isFull(struct QueueNode* q) {
	return q->rear == q->size - 1;
}

void enqueue(struct QueueNode* q, struct Node* nd) {
	if (isFull(q)) return;
	q->A[++q->rear] = nd;
}

struct Node* dequeue(struct QueueNode* q) {
	if (isEmpty(q)) return NULL;
	return q->A[++q->front];
}


struct Node* top(struct QueueNode* q) {
	if (isEmpty(q)) return NULL;
	return q->A[q->front + 1];
}