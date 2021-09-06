#include<stdlib.h>

struct Node {
	char ch;
	struct Node* next;
};

struct LL {
	struct Node* head;
	struct Node* tail;
	int len;
};

void traverse(struct LL ll) {
	struct Node* ptr = &ll.head;
	while (ptr) {
		printf("%c", ptr->ch);
		ptr = ptr->next;
	}
}

void insertPos(struct LL* ll, int pos, char c) {

	if (pos == 0) {
		if (ll->head) {
			if (ll->head == ll->tail) {
				struct Node* nwNd = (struct Node*)(calloc(1, sizeof(struct Node)));
				nwNd->ch = c;
				ll->tail = nwNd;
				ll->len++;
			}
			else {
				// Replace Head
			}
		}
		else {
			ll->head = (struct Node*)(calloc(1, sizeof(struct Node)));
			ll->tail = (struct Node*)(calloc(1, sizeof(struct Node)));
			ll->head = ll->tail;
			ll->head->ch = c;
			ll->len++;
		}
	}
	else {
		struct Node* ptr = ll->head;
		int i = 0;
		while (ptr->next && i < pos) ptr = ptr->next;
		//INSERT HERE

	}

}

int main(int argc, char const* argv[])
{

	return 0;
}
