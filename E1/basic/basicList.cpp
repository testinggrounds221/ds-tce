#define I 32767  // Infinity
#include <stdio.h>
#include<stdlib.h>

struct List
{
	int* A;
	int size;
	int length;
};

int isFull(struct List* arr) { //str-check
	return arr->length == arr->size;
}

int isEmpty(struct List arr) { //str-check
	return (arr.A[0]) ? 0 : 1;
}

void createList(struct List* arr, int size) { //str-check
	arr->size = size;
	arr->A = (int*)malloc(arr->size * sizeof(int)); //Change to char**
	arr->length = 0;

	for (int i = 0;i < arr->length;i++)
		arr->A[i] = 0; //Change to Empty str
}

void Insert(struct List* arr, int index, int x) //Change parametre//str-check
{
	if (isFull(arr)) return;
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length;i > index;i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}

void InsertLast(struct List* arr, int x) {//Change parametre//str-check
	Insert(arr, arr->length, x);
}

void InsertFirst(struct List* arr, int x) { //Change parametre//str-check
	Insert(arr, 0, x);
}

int GetElement(struct List arr, int index) { //str-check
	if (!isEmpty(arr) && (0 <= index < arr.length)) return arr.A[index];
	return -1;
}

int Search(struct List arr, int x) { //Change parametre
	for (int i = 0;i < arr.length;i++)
		if (arr.A[i] == x) return i;
	return -1;
}

void Display(struct List arr) // Change print statement
{
	int i;
	printf("\nElements are\n");
	for (i = 0;i < arr.length;i++)
		printf("%d ", arr.A[i]);
}

int DeleteIndex(struct List* arr, int index) //Return typ
{
	if (isEmpty(*arr)) return -1;
	int x = 0;
	int i;

	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index;i < arr->length - 1;i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return x;
	}

	return -1;
}

int DeleteLast(struct List* arr) { //Return typ
	return DeleteIndex(arr, arr->length - 1);
}

int DeleteFirst(struct List* arr) { //Return typ
	return DeleteIndex(arr, 0);
}

int DeleteElement(struct List* arr, int x) { //Return typ
	int ind = Search(*arr, x);
	if (ind != -1) { DeleteIndex(arr, ind); return ind; }
	return -1;
}


int main()
{
	struct List arr1, arr2;
	int ch;
	int x, index, size;

	// printf("Enter Size of Array : ");
	// scanf("%d", &size);
	createList(&arr1, 10);
	InsertLast(&arr1, 20);
	DeleteLast(&arr1);
	DeleteFirst(&arr1);
	Display(arr1);
	printf("%d", GetElement(arr1, 1));
	scanf("%d", &size);




	// do
	// {
	// 	printf("\n\nMenu\n");
	// 	printf("1. Append\t");
	// 	printf("2. Delete\t");
	// 	printf("3. Search\t");
	// 	printf("4. Display\t");
	// 	printf("5. Insert Anywhere \t");
	// 	printf("6.Exit\t");
	// 	printf("\nEnter you choice : ");
	// 	scanf("%d", &ch);

	// 	switch (ch)
	// 	{
	// 	case 1: printf("Enter an element to Append ");
	// 		scanf("%d", &x);
	// 		Append(&arr1, x);
	// 		break;
	// 	case 2: printf("Enter index ");
	// 		scanf("%d", &index);
	// 		x = DeleteIndex(&arr1, index);
	// 		printf("Deleted Element is %d\n", x);
	// 		break;
	// 	case 3:printf("Enter element to search ");
	// 		scanf("%d", &x);
	// 		index = Search(arr1, x);
	// 		printf("Element index %d", index);
	// 		break;
	// 	case 4:Display(arr1);
	// 		break;
	// 	case 5:
	// 		printf("Enter an element and index : ");
	// 		scanf("%d %d", &x, &index);
	// 		Insert(&arr1, index, x);
	// 		break;
	// 	}
	// } while (ch < 6);
	return 0;
}
