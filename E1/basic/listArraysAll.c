#define I 32767  // Infinity
#include <stdio.h>
#include<stdlib.h>

struct List
{
	int* A;
	int size;
	int length;
};

int isFull(struct List* arr) {
	return arr->length == arr->size;
}

int isEmpty(struct List arr) {
	return (arr.A[0]) ? 0 : 1;
}

void createList(struct List* arr, int size) {
	arr->size = size;
	arr->A = (int*)malloc(arr->size * sizeof(int));
	arr->length = 0;

	for (int i = 0;i < arr->length;i++)
		arr->A[i] = 0;
}

void Insert(struct List* arr, int index, int x)
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

void InsertLast(struct List* arr, int x) {
	Insert(arr, arr->length, x);
}

void InsertFirst(struct List* arr, int x) {
	Insert(arr, 0, x);
}

int GetElement(struct List arr, int index) {
	if (!isEmpty(arr) && (0 <= index < arr.length)) return arr.A[index];
	return -1;
}

int Search(struct List arr, int x) {
	for (int i = 0;i < arr.length;i++)
		if (arr.A[i] == x) return i;
	return -1;
}

void Display(struct List arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0;i < arr.length;i++)
		printf("%d ", arr.A[i]);
}

int DeleteIndex(struct List* arr, int index)
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

int DeleteLast(struct List* arr) {
	return DeleteIndex(arr, arr->length - 1);
}

int DeleteFirst(struct List* arr) {
	return DeleteIndex(arr, 0);
}

int DeleteElement(struct List* arr, int x) {
	int ind = Search(*arr, x);
	if (ind != -1) { DeleteIndex(arr, ind); return ind; }
	return -1;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Reverse(struct List* arr)
{
	int* B;
	int i, j;

	B = (int*)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0;i >= 0;i--, j++)
		B[j] = arr->A[i];
	for (i = 0;i < arr->length;i++)
		arr->A[i] = B[i];

}

void Reverse2(struct List* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1;i < j;i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
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
