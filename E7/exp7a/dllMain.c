#include<stdio.h>
#include<stdlib.h>

struct Data {
	int val;
};

struct Node {
	struct Node* next;
	struct Data* data;
	struct Node* prev;
};

struct DLL {
	struct Node* head;
	struct Node* tail;
};

struct DLL* createDLL() {
	struct DLL* dll = (struct DLL*)(calloc(1, sizeof(struct DLL)));
	dll->head = createEmptyNode(NULL);

}

struct Node* createEmptyNode(struct Data* data) {
	struct Node* node = (struct Node*)(calloc(1, sizeof(struct Node)));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
}
