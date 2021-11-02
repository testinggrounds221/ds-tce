#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node
{
	int data;
	struct node* next;
};

struct node* chain[size];

void init()
{
	int i;
	for (i = 0; i < size; i++)
		chain[i] = NULL;
}

void insert(int value)
{
	//create a newnode with value
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = value;
	newNode->next = NULL;

	//calculate hash key
	int key = value % size;

	//check if chain[key] is empty
	if (chain[key] == NULL)
		chain[key] = newNode;
	//collision
	else
	{
		//add the node at the end of chain[key].
		struct node* temp = chain[key];
		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

void delete(int value) {
	int key = value % size;

	if (chain[key] == NULL)
		return;
	struct node* temp = chain[key];
	while (temp->next && temp->next->data != key)
	{
		temp = temp->next;
	}
	if (!temp->next) {
		struct node* toDel = temp->next;
		temp->next = NULL;
		free(toDel);
		return;
	}
	struct node* toDel = temp->next;
	temp->next = temp->next->next;
	free(toDel);
	return;
}

void print()
{
	int i;

	for (i = 0; i < size; i++)
	{
		struct node* temp = chain[i];
		printf("chain[%d]-->", i);
		while (temp)
		{
			printf("%d -->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	//init array of list to NULL
	for (int i = 0;i < 10;i++) {
		insert(i);
	}
	delete(1);
	print();
	return 0;
}