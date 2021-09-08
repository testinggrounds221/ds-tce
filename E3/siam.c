#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* l;



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

void delete_element()
{
	printf("Element deleted is %d", l->data);
	l = l->next;
}
void create(int elt)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = elt;
	temp->next = NULL;
	l = temp;
}
void insert(int elt)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* l1 = l;
	while (l1->next != NULL)
	{
		l1 = l1->next;
	}
	temp->data = elt;
	temp->next = l1->next;
	l1->next = temp;

}

int main()
{
	int choice, elt, search;
	while (1)
	{
		printf("Enter  1 - insert 2-find 3-delete  4-display 5-create");
		scanf("%d", &choice);
		switch (choice)
		{

		case 1:
			printf("\nEnter the element to insert ");
			int x = 0;
			scanf("%d", &x);
			insert(x);
			break;
		case 2:
			printf("Enter the node to search ");

			scanf("%d", &search);

			break;
		case 3:
			printf("Enter the node to delete");
			scanf("%d", &search);
			delete_element(search);
			break;

		case 4:
			display();
			break;
		case 5:
			printf("\n enter the elements of the node to be created");
			scanf("%d", &elt);
			break;
		}
	}
	return 0;
}