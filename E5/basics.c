#include<stdlib.h>
#include<stdio.h>

struct Node {
	char ch;
	struct Node* next;
};

struct LL {
	struct Node* head;
};

void traverse(struct LL* ll) {
	struct Node* ptr = ll->head;
	while (ptr) {
		printf("%c", ptr->ch);
		ptr = ptr->next;
	}
}

void insertPos(struct LL* ll, int pos, char c) { // Inserts After
	struct Node* nwNd = (struct Node*)(calloc(1, sizeof(struct Node)));
	nwNd->ch = c;
	if (pos == 0 || !ll->head) {
		if (ll->head) {
			ll->head = ll->head->next;
			ll->head = nwNd;
		}
		else {
			ll->head = nwNd;
			ll->head->ch = c;
		}
	}
	else {
		struct Node* ptr = ll->head;
		int i = 0;

		while (ptr->next && i < pos) { ptr = ptr->next;i++; }
		if (ptr->next) {
			nwNd->next = ptr->next;
			ptr->next = nwNd;
		}
		else {
			nwNd->next = NULL;
			ptr->next = nwNd;
		}
	}
}

struct Node* getNode(struct LL* ll, int pos) {
	if (pos == 0) return ll->head;
	int i = 0;
	struct Node* ptr = ll->head;
	while (ptr->next && i < pos - 1) { ptr = ptr->next;i++; }
	return ptr->next;
}

char dltHead(struct LL* ll) {
	if (!ll->head) return '\0';
	struct Node* ptr = ll->head;
	char x = ptr->ch;
	ll->head = ll->head->next;
	free(ptr);
	return x;
}

char dltNext(struct LL* ll, struct Node* dltNxt) { // Deletes Next Node
	if (!dltNxt || !dltNxt->next) return '\0';
	struct Node* ptr = dltNxt->next;
	char x = ptr->ch;
	dltNxt->next = dltNxt->next->next;
	free(ptr);
	return x;
}

char dltPos(struct LL* ll, int pos) { // Deletes Node
	if (pos == 0) return dltHead(ll);
	if (!ll->head) return '\0';
	return dltNext(ll, getNode(ll, pos - 1));

}

struct Node* srch(struct LL* ll, char c) {
	struct Node* ptr = ll->head;
	while (ptr && ptr->ch != c) { ptr = ptr->next; }
	return ptr;
}

void append(struct LL* ll, char c) {
	insertPos(ll, 9999, c);
}

int main(int argc, char const* argv[])
{
	struct LL* ll = (struct LL*)(calloc(1, sizeof(struct LL)));
	struct LL* ll1 = (struct LL*)(calloc(1, sizeof(struct LL)));

	append(ll, 'A');
	append(ll, 'B');
	append(ll, 'C');
	append(ll, 'D');
	append(ll, 'E');

	traverse(ll);

	// dltPos(ll, 0);
	// if (!getNode(ll, 22)) { printf("Nothing to delte"); }
	// printf("\nDeleted Char -> %c\n", dltPos(ll, 0));
	// traverse(ll);
	// printf("\nDeleted Char -> %c\n", dltPos(ll, 2));
	// traverse(ll);
	printf("Search pointer : %c", srch(ll, 'A')->ch);
	printf("\nProgram end\n");
	return 0;
}
