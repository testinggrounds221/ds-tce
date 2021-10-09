#include "binSrchTree.h"


int main(int argc, char const* argv[]) {
	struct BST* bt = (struct BST*)(calloc(1, sizeof(struct BST)));
	bt->root = NULL;
	char ch;
	char* key = malloc(sizeof(char) * MAXKEYLENGTH);
	char* val = malloc(sizeof(char) * MAXVALLENGTH);

	struct Node* i = insertPair(bt, "baseKey", "baseVal");
	delete(bt, bt->root, "baseKey");
	// insertPair(bt, "Apple", "A Fruit");
	// struct Node* i = insertPair(bt, "DS", "a way to store and organize data");
	// insertPair(bt, "C", "procedural programming language");
	// insertPair(bt, "Elephant", "An animal");
	// insertPair(bt, "CPP", "a OOP programming language");
	// printf("Inorder Successor of DS : %s ", inorderSuccessor(i->right)->key);
	// printf("Inorder Predecessor of DS : %s \n", inorderPrdecessor(i->left)->key);
	// printf("Deleting Key \"Apple\"\n");
	// delete(bt, bt->root, "DS");
	// printf("Inorder Traversal : \n");
	// inorder(bt->root);
	// printf("\n");
	// printf(getMeaning(bt->root, "Elephant"));
	do
	{
		printf("\nMenu\n");
		printf("1. Add Pair to Dictionary\t");
		printf("2. Remove Pair from Dictionary\t");
		printf("3. Search Key in Dictionary\t");
		printf("4. Display All Pairs Alphabetically\t");
		printf("5.Exit\t");

		printf("\nEnter you choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter Key to Add : \n");
			scanf("%10s", key);
			printf("Enter Val to Add : \n");
			scanf("%50s", val);
			insertPair(bt, key, val);
			printf("Inserted Pair\n");
			break;
		case 2: printf("Enter key to Delete :");
			scanf("%s", key);
			delete(bt, bt->root, key);
			printf("Deleted Pair\n");

			break;
		case 3:printf("Enter Key to search : ");
			scanf("%10s", key);
			val = getValue(bt->root, key);
			printf("Value of %s is %s\n", key, val);
			break;
		case 4:inorder(bt->root);
			break;

		}
	} while (ch < 5);
	return 0;
}