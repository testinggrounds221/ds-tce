#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct List
{
	char A[30][20];
	int size;
	int length;
};

void createList(struct List* arr) { //str-check
	arr->size = 30;
	// char arrstr[size][20];
	// arr->A = (char**)malloc(arr->size * sizeof(char)); //Change to char**
	arr->length = 0;

	for (int i = 0;i < arr->size;i++)
		strcpy(arr->A[i], "averylongstr");
	// arr->A[i] = "averylongstringforcopying"; //Change to Empty str
}

int isFull(struct List* arr) { //str-check
	return arr->length == arr->size;
}

int isEmpty(struct List arr) { //str-check
	return (arr.A[0]) ? 0 : 1;
}

void Display(struct List arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0;i < arr.length;i++)
		printf("%s ", arr.A[i]);
}

void Insert(struct List* arr, int index, char* x)
{
	if (isFull(arr)) return;
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length;i > index;i--)
			strcpy(arr->A[i], arr->A[i - 1]);
		strcpy(arr->A[index], x);
		arr->length++;
	}
}

void InsertLast(struct List* arr, char* x) {
	Insert(arr, arr->length, x);
}


char* GetElement(struct List arr, int index) { //str-check  
	if (!isEmpty(arr) && (0 <= index) && (index < arr.length)) {
		// Display(arr1);
		char* result = (char*)malloc(sizeof(char) * 20);
		strcpy(result, arr.A[index]);
		return result;

	}
	return "-1";
}

char* GetFirst(struct List arr) { //str-check  
	return GetElement(arr, 0);
}

char* GetLast(struct List arr) {
	return GetElement(arr, arr.length - 1);
}

int Search(struct List arr, char* x) {
	for (int i = 0;i < arr.length;i++)
		if (strcmp(arr.A[i], x) == 0) return i;
	return -1;
}

char* DeleteIndex(struct List* arr, int index)
{
	if (isEmpty(*arr)) return "-1";
	int i;

	if (index >= 0 && index < arr->length)
	{
		char* result = (char*)malloc(sizeof(char) * 20);
		strcpy(result, arr->A[index]);
		for (i = index;i < arr->length - 1;i++)
			strcpy(arr->A[i], arr->A[i + 1]);
		arr->length--;
		return result;
	}

	return "-1";
}
int DeleteElement(struct List* arr, char* x) {
	int ind = Search(*arr, x);
	if (ind != -1) { DeleteIndex(arr, ind); return ind; }
	return -1;
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


int main()
{
	struct List arr1, arr2;
	int ch;
	int index, size;
	char x[20];
	createList(&arr1);

	do
	{
		printf("\nMenu\n");
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
		case 2: printf("Enter word to Delete :");
			scanf("%s", &x);
			printf("Deleted position is %d\n", DeleteElement(&arr1, x) + 1);
			break;
		case 3:printf("Enter word to search ");
			scanf("%s", &x);
			index = Search(arr1, x);
			printf("Element position %d", index + 1);
			break;
		case 4:Display(arr1);
			break;
		case 5:
			printf("Enter a word and position (> 0) : ");
			scanf("%s %d", &x, &index);
			Insert(&arr1, index - 1, x);
			break;
		}
	} while (ch < 6);
	return 0;
}
