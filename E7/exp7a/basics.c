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

struct Node* createEmptyNode(struct Data* data) {
	struct Node* node = (struct Node*)(calloc(1, sizeof(struct Node)));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
}

void insertNode(struct DLL* dll, struct Data* data, int pos) {
	struct Node* nwNd = createEmptyNode(data);
	if (pos == 0 || !dll->head) {
		if (dll->head) {
			dll->head = dll->head->next;
			dll->head = nwNd;
		}
		else {
			dll->head = dll->tail = createEmptyNode(data);

		}
	}

}

void traverse(struct DLL dll) {
	struct Node* temp = dll.head;
	while (temp) {
		printf("%d \n", temp->data->val);
		temp = temp->next;
	}
}

int main(int argc, char const* argv[])
{
	struct DLL* dll = (struct DLL*)(calloc(1, sizeof(struct DLL)));
	struct Data* data = (struct Data*)(calloc(1, sizeof(struct Data)));
	data->val = 0;
	insertNode(dll, data, 0);
	data->val = 1;
	insertNode(dll, data, 1);
	data->val = 2;
	insertNode(dll, data, 2);
	data->val = 3;
	insertNode(dll, data, 3);
	data->val = 4;
	insertNode(dll, data, 4);

	traverse(*dll);
	return 0;
}