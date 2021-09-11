#include<stdio.h>
#include<stdlib.h>

struct Data {
	char str[20];
};

struct Node {
	struct Node* next;
	struct Data* data;
	struct Node* prev;
};

struct DLL {
	struct Node* head;
};

struct Node* createEmptyNode(struct Data* data, char str[]) {
	struct Node* node = (struct Node*)(calloc(1, sizeof(struct Node)));
	struct Data* data = (struct Data*)(calloc(1, sizeof(struct Data)));
	node->next = NULL;
	node->prev = NULL;
}

void insertNode(struct DLL* dll, struct Data* data, int pos) {
	if (!dll->head) {

	}

}

struct DLL* createHea() {
	struct DLL* dll = (struct DLL*)(calloc(1, sizeof(struct DLL)));
	dll->head = NULL;
	return dll;
}