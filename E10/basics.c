#include <stdio.h>
#include <stdlib.h>

const int SIZE = 17;

struct item
{
	int key;
	int val;
};

struct hashAbleItem {
	struct item* data;
	int flag;
	// 0 - Not filled once
	// 1 - Contains Element
	// 2 - Element was there atleast once
};

int hashCode(int key) {
	return key % SIZE;
}

void insertRecord(struct hashAbleItem* ht, int key, int val) {
	int collision = 0;
	int hashVal = hashCode(key);
	int i = hashVal;
	int h = 0;// Q

	while (ht[i].flag == 1) {
		if (ht[i].data->key == key) {
			printf("Key Present. Replacing %d's Value\n", key);
			ht[i].data->val;
			return;
		}
		// i = (i + 1) % SIZE;
		i = (i + (h * h)) % SIZE; // Q

		if (i == hashVal) {
			printf("Table Full\n");
			return;
		}
		h++; // Q
	}
	ht[i].data = (struct item*)(malloc(sizeof(struct item)));
	ht[i].data->key = key;
	ht[i].data->val = val;
	ht[i].flag = 1;
	printf("K->%d, V->%d has been inserted \n", key, ht[i].data->val);
}

void deleteRecord(struct hashAbleItem* ht, int key) {
	int hashVal = hashCode(key);
	int i = hashVal;
	int h = 1;// Q
	while (ht[i].flag != 0) {

		if (ht[i].flag == 1 && ht[i].data->key == key) {
			ht[i].flag = 2;
			printf("K->%d, V->%d has been removed \n", key, ht[i].data->val);
			ht[i].data = NULL;
			return;
		}
		// i = (i + 1) % SIZE;	
		i = (i + (h * h)) % SIZE;
		h++;
		if (i == hashVal) // Q
			break;
	}
	printf("This key does not exist \n");
}

struct hashAbleItem* initHashTable() {
	struct hashAbleItem* hashTable = (struct hashAbleItem*)(calloc(SIZE, sizeof(struct hashAbleItem)));
	for (int i = 0;i < SIZE;i++) {
		hashTable[i].flag = 0;
		hashTable[i].data = NULL;
	}
	return hashTable;
}

void printTable(struct hashAbleItem* ht) {
	for (int i = 0;i < SIZE;i++) {
		if (ht[i].flag == 1)
			printf("ht[%d]\t=> K:%d\tV:%d\tF:%d", i, ht[i].data->key, ht[i].data->val, ht[i].flag);
		else
			printf("ht[%d]\t=> K:N\tV:N\tF:%d\t", i, ht[i].flag);
		printf("\n");
	}
}

int main(int argc, char const* argv[])
{
	int choice, key, value, n, c;
	struct hashAbleItem* ht = initHashTable();
	printf("\nInsertion : \n");
	insertRecord(ht, 13, 130);
	insertRecord(ht, 23, 230);
	insertRecord(ht, 33, 330);
	insertRecord(ht, 43, 430);
	printTable(ht);
	printf("\nDeletion : \n");
	deleteRecord(ht, 23);
	deleteRecord(ht, 43);
	printTable(ht);
	do {
		printf("\nMENU-: \n1.Insert an item"
			"\n2.Delete an item"
			"\n3.Display Hashtable"
			"\nAny other number for exit\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter key and value for insertion :-\t");
			scanf("%d %d", &key, &value);
			insertRecord(ht, key, value);
			break;
		case 2:
			printf("Enter the key to delete :-");
			scanf("%d", &key);
			deleteRecord(ht, key);
			break;
		case 3:
			printTable(ht);
			break;
		default:
			printf("Wrong Input\n");
		}
	} while (choice < 4);
	return 0;
}
