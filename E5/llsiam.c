
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* l;
void create(int elt)
{
	struct node* temp;  // it is a pointer object to a structure node 
	temp = (struct node*)malloc(sizeof(struct node));   // int *p =(int *)malloc(sizeof(int))
	temp->data = elt;
	temp->next = NULL;
	l = temp;
}
void insert_beg(int elt)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = elt;
	temp->next = l;
	l = temp;
}
void display()
{
	struct node* l1 = l;
	while (l1->next != NULL)
	{
		printf("%d->", l1->data);
		l1 = l1->next;
	}
	printf("%d->NULL\n", l1->data);
}

void insertPos(int pos, int c) { // Inserts After
	struct node* nwNd = (struct node*)(calloc(1, sizeof(struct node)));
	nwNd->data = c;
	if (pos == 0 || !l) {
		if (l) {
			l = l->next;
			l = nwNd;
		}
		else {
			l = nwNd;
			l->data = c;
		}
	}
	else {
		struct node* ptr = l;
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

void append(int elt)
{
	struct node* temp;
	struct node* l1 = l;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = elt;
	temp->next = NULL;
	while (l1->next != NULL)
	{
		l1 = l1->next;
	}
	l1->next = temp;
}
void delete_beg()
{
	printf("Element deleted is %d", l->data);
	l = l->next;
}
void delete_last()
{
	struct node* l1 = l;
	while (l1->next->next != NULL)
	{
		l1 = l1->next;
	}
	printf("\nElement deleted is %d", l1->next->data);
	l1->next = NULL;
}
void insert_middle(int search, int elt)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* l1 = l;
	while (l1->next != NULL && l1->data != search)
	{
		l1 = l1->next;
	}
	temp->data = elt;
	temp->next = l1->next;
	l1->next = temp;

}
void delete_middle(int search)
{
	struct node* l1 = l;
	while (l1->next != NULL && l1->next->data != search)
	{
		l1 = l1->next;
	}
	l1->next = l1->next->next;
}
int main()
{
	int choice, elt, search;
	while (1)
	{
		printf("Enter 1-create 2 - insert_beg 3-append 4-delete_beg 5-delete_last 6-insert_middle 7-delete_middle 9-display");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the element to create");
			scanf("%d", &elt);
			create(elt);
			break;
		case 2:
			printf("\nEnter the element to insert at the beginning");
			scanf("%d", &elt);
			insert_beg(elt);
			break;
		case 3:
			printf("\nEnter the element to insert at the last");
			scanf("%d", &elt);
			append(elt);
			break;
		case 4:
			delete_beg();
			break;
		case 5:
			delete_last();
			break;
		case 6:
			printf("Enter the search node");
			scanf("%d", &search);
			printf("Enter the element to insert in the middle");
			scanf("%d", &elt);
			insert_middle(search, elt);
			break;
		case 7:
			printf("Enter the node to delete");
			scanf("%d", &search);
			delete_middle(search);
			break;

		case 9:
			display();
			break;
		}
	}
	return 0;
}