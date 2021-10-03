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
	printf("Not full");
	q->A[++q->rear] = nd;
	printf("Enq overs");

}

struct Node* dequeue(struct QueueNode* q) {
	if (isEmpty(q)) return NULL;
	return q->A[++q->front];
}

void traverse(struct QueueNode* q) {
	if (isEmpty(q)) return;
	for (int i = q->front + 1;i <= q->rear;i++) {
		printf("%d ", q->A[i]->val);
	}
}

struct Node* top(struct QueueNode* q) {
	if (isEmpty(q)) return NULL;
	return q->A[q->front + 1];
}

int main(int argc, char const* argv[])
{
	struct QueueNode* q = (struct QueueNode*)(malloc(sizeof(struct QueueNode)));
	int x;

	struct Node* ptr;
	struct Node* t;

	struct Node* root = (struct Node*)(malloc(sizeof(struct Node)));

	printf("Enter Root Data : ");
	scanf(" %d", root->val);

	root->left = NULL;
	root->right = NULL;
	printf("Heyy");
	enqueue(q, root);
	traverse(q);
	return 0;
}
