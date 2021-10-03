#include <stdio.h>
#include <stdlib.h>
// 
struct Node {
	struct Node* lchild;
	int val;
	struct Node* rchild;
};

struct BST {
	struct Node* root;
};

void insert(struct BST* tree, int key) {
	struct Node* temp = tree->root;
	struct Node* r, * p;
	if (!tree->root) {
		struct Node* node = (struct Node*)(malloc(sizeof(struct Node)));
		node->val = key;
		node->lchild = NULL;
		node->rchild = NULL;
		tree->root = node;
		return;
	}
	while (temp) {
		r = temp;
		if (key < temp->val) temp = temp->lchild;
		else if (key > temp->val) temp = temp->rchild;
		else return;
	}
	p = (struct Node*)(malloc(sizeof(struct Node)));
	p->val = key;
	p->lchild = NULL;
	p->rchild = NULL;
	if (key < r->val) r->lchild = p;
	if (key > r->val) r->rchild = p;
}

void Inorder(struct Node* p) {
	if (p) {
		Inorder(p->lchild);
		printf("%d, ", p->val);
		Inorder(p->rchild);
	}
}

int main(int argc, char const* argv[]) {
	struct BST* tr = (struct BST*)(malloc(sizeof(struct BST)));
	insert(tr, 10);
	insert(tr, 20);
	insert(tr, 30);
	insert(tr, 40);
	insert(tr, 50);
	insert(tr, 60);
	insert(tr, 70);
	insert(tr, 80);
	insert(tr, 90);
	Inorder(tr->root);
	return 0;
}
