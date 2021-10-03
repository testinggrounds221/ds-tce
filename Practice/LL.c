#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
}*head;



void createList(int start, int end) {
	head = (struct Node*)(malloc(sizeof(struct Node)));
	struct Node* temp = head;
	head->data = 0;
	for (int i = start + 1;i < end;i++) {
		struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
		newNode->data = i;
		newNode->next = NULL;
		temp->next = newNode;
		temp = newNode;
	}

}

void reverseLL() {
	struct Node* ptr = head;
	struct Node* q = NULL;
	struct Node* r = NULL;

	while (ptr) {
		r = q;
		q = ptr;
		ptr = ptr->next;

		q->next = r;
	}


}

void insertNode(int val, int pos) {
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->data = val;
	newNode->next = NULL;

	if (pos == 0 && head) { //Change Head
		newNode->next = head;
		head = newNode;
	}
	if (pos == 0 && !head) { //Change Head
		head = newNode;
	}

}

void traverse() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf(" %d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");

}

int main(int argc, const char* argv[]) {
	// createList(0, 10);
	insertNode(12, 0);
	traverse(head);
}