#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node {
	int num;
	struct Node* next;
}*head;

void append(int key) {
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->next = NULL;
	newNode->num = key;
	if (!head) {
		head = newNode;
		return;
	}
	struct Node* ptr = head;
	while (ptr->next) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
}

void traverse() {
	struct Node* ptr = head;
	while (ptr) {
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
}

int main() {
	int numEle = 0;
	int tempNum = 0;

	scanf("%d", &numEle);
	int* hsh = (int*)(malloc(1000 * sizeof(int)));
	for (int i = 0;i < 1000;i++) hsh[i] = 0;

	for (int j = 0;j < numEle;j++) {
		scanf("%d", &tempNum);
		if (hsh[tempNum] == 0) {
			hsh[tempNum] = 1;
			append(tempNum);
		}
	}
	traverse();
	return 0;
}
