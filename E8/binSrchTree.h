#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAXKEYLENGTH 10
#define MAXVALLENGTH 50

struct Node {
	struct Node* left, * right;

	char key[MAXKEYLENGTH];
	char value[MAXVALLENGTH];
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

struct Node* createNodeKeyValue(char* key, char* value) {
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->left = newNode->right = NULL;
	strcpy(newNode->key, key);
	strcpy(newNode->value, value);
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

struct Node* insertPair(struct BST* bt, char* key, char* value) {

	struct Node* t = bt->root;
	struct Node* r, * p;
	if (bt->root == NULL) {
		p = createNodeKeyValue(key, value);
		bt->root = p;
		return bt->root;
	}

	while (t) {
		r = t;
		if (strcmp(r->key, key) > 0) t = t->left;
		else if (strcmp(r->key, key) < 0) t = t->right;
		else return NULL;
	}
	p = createNodeKeyValue(key, value);
	if (strcmp(r->key, key) > 0) r->left = p;
	if (strcmp(r->key, key) < 0) r->right = p;
	return p;
}

struct BST* createTree() {
	struct BST* bst = (struct BST*)(malloc(sizeof(struct BST)));
	bst->root = NULL;
	return bst;
}

void inorder(struct Node* ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("Key : %s | ", ptr->key);
		printf("Value : %s\n", ptr->value);
		inorder(ptr->right);
	}
}

void preorder(struct Node* ptr) {
	if (ptr) {
		printf("Key : %s", ptr->key);
		printf("Value : %s\n", ptr->value);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

struct Node* delete(struct BST* bst, struct Node* ptr, char* key) {
	struct Node* q;
	if (!ptr) return NULL;
	if (!ptr->left && !ptr->right) {
		if (ptr == bst->root) { bst->root = NULL; }
		free(ptr);
		return NULL;
	}
	if (strcmp(ptr->key, key) > 0) ptr->left = delete(bst, ptr->left, key);
	else if (strcmp(ptr->key, key) < 0) ptr->right = delete(bst, ptr->right, key);
	else {
		if (height(ptr->left) > height(ptr->right)) {
			q = inorderPrdecessor(ptr->left);
			strcpy(ptr->key, q->key);
			strcpy(ptr->value, q->value);
			ptr->left = delete(bst, ptr->left, q->key);
		}
		else {
			q = inorderSuccessor(ptr->right);
			strcpy(ptr->key, q->key);
			strcpy(ptr->value, q->value);
			ptr->right = delete(bst, ptr->right, q->key);
		}
	}
	return ptr;
}

char* getValue(struct Node* node, char* key) {

	if (node) {
		if (strcmp(node->key, key) > 0)	return getValue(node->left, key);
		else if (strcmp(node->key, key) < 0) return getValue(node->right, key);
		return node->value;
	}
	return "\0";
}