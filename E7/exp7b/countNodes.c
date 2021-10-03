#include "queueNode.h"

struct Tree {
	struct Node* root;
};

struct Tree* implement() {

	// queue<Node*> q;
	struct QueueNode* q = (struct QueueNode*)(malloc(sizeof(struct QueueNode)));
	struct Tree* tree = (struct Tree*)(malloc(sizeof(struct Tree)));

	int x;

	struct Node* ptr;
	struct Node* t;
	tree->root = (struct Node*)(malloc(sizeof(struct Node)));

	printf("Enter Root Data : ");
	scanf(" %d", &tree->root->val);

	tree->root->left = NULL;
	tree->root->right = NULL;
	printf("Heyy");
	enqueue(q, tree->root);


	while (!isEmpty(q)) {
		ptr = dequeue(q);
		printf("\nEnter Left Data of Node %d ", ptr->val);
		scanf("%d", &x);
		if (x != -1) {
			t = (struct Node*)(malloc(sizeof(struct Node)));
			t->val = x;
			t->left = NULL;
			t->right = NULL;
			ptr->left = t;
			enqueue(q, t);
		}
		printf("\nEnter Right Data of Node %d : ", ptr->val);
		scanf("%d", &x);
		if (x != -1) {
			t = (struct Node*)(malloc(sizeof(struct Node)));
			t->val = x;
			t->left = NULL;
			t->right = NULL;
			ptr->right = t;
			enqueue(q, t);
		}
	}
	return tree;
}

void Preorder(struct Node* ptr) {
	if (ptr) {
		printf("%d -> ", ptr->val);
		Preorder(ptr->left);
		Preorder(ptr->right);
	}
}

int main(int argc, char const* argv[])
{
	struct Tree* tree = implement();
	Preorder(tree->root);
	return 0;
}
