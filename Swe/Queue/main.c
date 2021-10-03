#include <stdio.h>
#include <stdlib.h>

int a = 0, b = 0;

struct que {
	int q[10];
	int front;
	int rear;
};

int N = 10;

struct que d = { {},-1,-1 };

void printqueue() {
	int i;
	for (i = d.front;i <= d.rear;i++) {
		printf("%d   ", d.q[i]);
	}
}

int enqueue(int x) {
	if (d.rear < N - 1) {
		d.rear += 1;
		d.q[d.rear] = x;
	}
	if (d.front == -1) {
		d.front = 0;
		return 0;
	}
	else {
		return -1;
	}
}

int delqueue() {
	int x;
	if (d.front != -1 && d.front <= d.rear) {
		x = d.q[d.front];
		d.front = d.front + 1;
		return x;
	}
	else {
		return -1;
	}
}

int isEmptyQueue() {
	if (d.front == -1 || d.front > d.rear) {
		printf("\nQueue is empty");
	}
	else {
		printf("\nThe queue is not empty\n");
	}
}

void dis_split(int* ex_arr, int len) {
	int i = 0;
	int length = len;
	if (length == 0)
		printf("Queue is empty \n");
	else {
		for (i = 0; i < length; i++)
			printf("%d  ", ex_arr[i]);
		printf("\n");
	}
}

void split()
{
	int neg[N], pos[N], i;
	if (d.front == -1)
		printf("Queue is empty \n");
	else {
		for (i = d.front;i <= d.rear;i++) {
			if (d.q[i] >= 0) {
				pos[a] = d.q[i];
				a++;
			}
			else {
				neg[b] = d.q[i];
				b++;
			}
		}
		printf("\nPositive Numbers: ");
		dis_split(pos, a);
		printf("\nNegative Numbers: ");
		dis_split(neg, b);
	}
}

int isFullQueue() {
	if ((d.rear + 1) == N) {
		printf("\nThe queue is full\n");
	}
	else {
		printf("The queue is not full");
	}
}

int main() {
	enqueue(5);
	enqueue(-5);
	enqueue(10);
	enqueue(-10);
	enqueue(15);
	enqueue(-15);
	enqueue(20);
	enqueue(-20);
	enqueue(30);
	enqueue(-30);
	printf("\nPrinting the values..........\n");
	printqueue();
	printf("\nChecking if the queue is empty..........\n");
	isEmptyQueue();
	delqueue();
	printf("\nAfter del function\n");
	printqueue();
	printf("\nChecking if the queue is full..........\n");
	isFullQueue();
	printf("\nSplit based on positive or negative\n");
	split();
}
