#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node* left, * right;
	int val;
};

struct BST {
	struct Node* root;
};

struct Node* inorderPrdecessor(struct Node* ptr) {
	while (ptr && ptr->right) ptr = ptr->right;
	return ptr;
}

struct Node* inorderSuccessor(struct Node* ptr) {
	while (ptr && ptr->left) ptr = ptr->left;
	return ptr;
}

struct Node* createNode(int val) {
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->left = newNode->right = NULL;
	newNode->val = val;
	return newNode;
}

int height(struct Node* ptr) {
	if (ptr) {
		int l = height(ptr->left);
		int r = height(ptr->right);
		return l > r ? l + 1 : r + 1;
	}
	return 0;
}

struct Node* insert(struct BST* bt, int val) {
	struct Node* newNode = createNode(val);
	struct Node* t = bt->root;
	struct Node* r, * p;
	if (!bt->root) {
		p = createNode(val);
		bt->root = p;
	}

	while (t) {
		r = t;
		if (t->val > val) t = t->left;
		else if (t->val < val) t = t->right;
		else return NULL;
	}
	p = createNode(val);

	if (val < r->val) r->left = p;
	if (val > r->val) r->right = p;
	return p;
}

struct BST* createTree() {
	struct BST* bst = (struct BST*)(malloc(sizeof(struct BST)));
	bst->root = NULL;
}

void inorder(struct Node* ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->val);
		inorder(ptr->right);
	}
}

void preorder(struct Node* ptr) {
	if (ptr) {
		printf("%d ", ptr->val);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

struct Node* delete(struct BST* bst, struct Node* ptr, int key) {
	struct Node* q;
	if (!ptr) return NULL;
	if (!ptr->left && !ptr->right) {
		if (ptr == bst->root) { bst->root = NULL; }
		free(ptr);
		return NULL;
	}
	if (ptr->val > key) ptr->left = delete(bst, ptr->left, key);
	else if (ptr->val < key) ptr->right = delete(bst, ptr->right, key);
	else {
		if (height(ptr->left) > height(ptr->right)) {
			q = inorderPrdecessor(ptr->left);
			ptr->val = q->val;
			ptr->left = delete(bst, ptr->left, q->val);
		}
		else {
			q = inorderSuccessor(ptr->right);
			ptr->val = q->val;
			ptr->right = delete(bst, ptr->right, q->val);
		}
	}
	return ptr;
}

int main(int argc, char const* argv[]) {
	struct BST* bt = createTree();
	insert(bt, 10);
	insert(bt, 70);
	struct Node* i = insert(bt, 30);
	insert(bt, 20);
	insert(bt, 40);
	insert(bt, 50);
	insert(bt, 60);
	printf("Inorder Successor of 30 : %d ", inorderSuccessor(i->right)->val);
	printf("Inorder Predecessor of 30 : %d \n", inorderPrdecessor(i->left)->val);
	delete(bt, bt->root, 30);
	inorder(bt->root);
	printf("\n");

	delete(bt, bt->root, 40);
	inorder(bt->root);
	printf("\n");

	delete(bt, bt->root, 50);
	inorder(bt->root);
	printf("\n");

	delete(bt, bt->root, 60);
	inorder(bt->root);
	printf("\n");

	return 0;
}
