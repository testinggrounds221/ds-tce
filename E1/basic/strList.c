#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct List
{
	char** A;
	int size;
	int length;
};

void createList(struct List* arr, int size) { //str-check
	arr->size = size;
	arr->A = (char**)malloc(arr->size * sizeof(char)); //Change to char**
	arr->length = 0;

	for (int i = 0;i < arr->size;i++)
		arr->A[i] = "averylongstringforcopying"; //Change to Empty str
}

int isFull(struct List* arr) { //str-check
	return arr->length == arr->size;
}

int isEmpty(struct List arr) { //str-check
	return (arr.A[0]) ? 0 : 1;
}

void Display(struct List arr) // Change print statement
{
	int i;
	printf("\nElements are\n");
	for (i = 0;i < arr.length;i++)
		printf("%s ", arr.A[i]);
}

void Insert(struct List* arr, int index, char* x) //Change parametre//str-check
{
	if (isFull(arr)) return;
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length;i > index;i--)
			strcpy(arr->A[i], arr->A[i - 1]);
		// arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		// strcpy(arr->A[index], x);
		arr->length++;
	}
}

char* GetElement(struct List arr, int index) { //str-check
	if (!isEmpty(arr) && (0 <= index < arr.length)) return arr.A[index];
	return "-1";
}

int Search(struct List arr, char* x) { //Change parametre
	for (int i = 0;i < arr.length;i++)
		if (arr.A[i] == x) return i;
	return -1;
}

char* DeleteIndex(struct List* arr, int index) //Return typ
{
	if (isEmpty(*arr)) return "-1";
	int i;
	char* x = " ";

	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index;i < arr->length - 1;i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}

	return "-1";
}

void InsertLast(struct List* arr, char* x) {//Change parametre//str-check
	Insert(arr, arr->length, x);
}

void InsertFirst(struct List* arr, char* x) { //Change parametre//str-check
	Insert(arr, 0, x);
}

char* DeleteLast(struct List* arr) { //Return typ
	return DeleteIndex(arr, arr->length - 1);
}

char* DeleteFirst(struct List* arr) { //Return typ
	return DeleteIndex(arr, 0);
}

char* DeleteElement(struct List* arr, char* x) { //Return typ
	int ind = Search(*arr, x);
	if (ind != -1) { return DeleteIndex(arr, ind); }
	return "-1";
}

int main()
{
	struct List arr1, arr2;
	int ch;
	int index, size;
	char x[20];
	printf("Enter Size of the array : ");
	scanf("%d", &size);
	createList(&arr1, size);
	InsertLast(&arr1, "FsrthElem");
	InsertLast(&arr1, "SecElem");

	// Display(arr1);
	// printf("Here");
	// Insert(&arr1, 0, "Shree");
	// Display(arr1);
	// Insert(&arr1, 1, "Rams");
	// Display(arr1);
	// Insert(&arr1, 2, "String");
	// Display(arr1);

	// InsertLast(&arr1, "Shree");
	// Display(arr1);
	// scanf("%s", &x);
	// InsertLast(&arr1, x);
	// Display(arr1);
	// scanf("%s", &x);
	// GetElement(arr1, 21);
	// Search(arr1, "Ram");
	// DeleteIndex(&arr1, 1);

	// printf("Enter Size of Array : ");
	// scanf("%d", &size);
	// createList(&arr1, 10);
	// InsertLast(&arr1, 20);
	// DeleteLast(&arr1);
	// DeleteFirst(&arr1);
	// Display(arr1);
	// printf("%d", GetElement(arr1, 1));
	// scanf("%d", &size);




	do
	{
		printf("\n\nMenu\n");
		printf("1. Append\t");
		printf("2. Delete\t");
		printf("3. Search\t");
		printf("4. Display\t");
		printf("5. Insert Anywhere \t");
		printf("6.Exit\t");
		printf("\nEnter you choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1: printf("Enter an word to Append ");
			scanf("%s", &x);
			InsertLast(&arr1, x);
			break;
		case 2: printf("Enter index ");
			scanf("%d", &index);
			char* ret = DeleteIndex(&arr1, index);
			printf("Deleted word is %d\n", ret);
			break;
		case 3:printf("Enter word to search ");
			scanf("%s", &x);
			index = Search(arr1, x);
			printf("Element index %d", index);
			break;
		case 4:Display(arr1);
			break;
		case 5:
			printf("Enter a word and index : ");
			scanf("%s %d", &x, &index);
			Insert(&arr1, index, x);
			break;
		}
	} while (ch < 6);
	return 0;
}

