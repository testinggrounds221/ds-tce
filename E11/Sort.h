#include<stdio.h>
#include<stdlib.h>
#define LEN 10

struct MaxHeap
{
	int size;
	int* array;
};

void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }

void printArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

void bubbleSort(int arr[], int len) {
	int temp = 0;
	for (int i = 0;i < len - 1;i++) {
		for (int j = 0;j < len - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
	int largest = idx;
	int left = (idx << 1) + 1;
	int right = (idx + 1) << 1;



	if (left < maxHeap->size &&
		maxHeap->array[left] > maxHeap->array[largest])
		largest = left;



	if (right < maxHeap->size &&
		maxHeap->array[right] > maxHeap->array[largest])
		largest = right;


	if (largest != idx)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}


struct MaxHeap* createAndBuildHeap(int* array, int size)
{
	int i;
	struct MaxHeap* maxHeap =
		(struct MaxHeap*)malloc(sizeof(struct MaxHeap));
	maxHeap->size = size;
	maxHeap->array = array;



	for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
		maxHeapify(maxHeap, i);
	return maxHeap;
}


void heapSort(int* array, int size)
{

	struct MaxHeap* maxHeap = createAndBuildHeap(array, size);



	while (maxHeap->size > 1)
	{



		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;


		maxHeapify(maxHeap, 0);
	}
}

void insertionSort(int arr[], int len) {
	int pos = 0, item = 0;
	for (int i = 1;i < len;i++) {
		item = arr[i];
		pos = i - 1;

		while (pos >= 0 && arr[pos] > item) {
			arr[pos + 1] = arr[pos];
			pos = pos - 1;
		}
		arr[pos + 1] = item;
	}
}

void merge(int arr[], int l, int m, int r) {
	int lPtr = 0, rPtr = 0, fPtr = l;
	int lLen = m - l + 1, rLen = r - m;

	int Left[lLen], Right[rLen];

	for (int i = 0;i < lLen;i++) {
		Left[i] = arr[l + i];
	}
	for (int j = 0;j < rLen;j++) {
		Right[j] = arr[m + 1 + j];
	}

	while (lPtr < lLen && rPtr < rLen) {
		if (Left[lPtr] <= Right[rPtr]) {
			arr[fPtr] = Left[lPtr];
			lPtr++;
		}
		else {
			arr[fPtr] = Right[rPtr];
			rPtr++;
		}
		fPtr++;
	}
	while (lPtr < lLen) {
		arr[fPtr] = Left[lPtr];
		lPtr++;
		fPtr++;
	}
	while (rPtr < rLen) {
		arr[fPtr] = Right[rPtr];
		rPtr++;
		fPtr++;
	}

}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void quicksort(int number[], int first, int last) {
	int i, j, pivot, temp;

	if (first < last) {
		pivot = first;
		i = first;
		j = last;

		while (i < j) {
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}

		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);

	}
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;


	for (i = 0; i < n - 1; i++)
	{

		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;


		swap(&arr[min_idx], &arr[i]);
	}
}

void shellSort(int arr[], int len) {
	int temp = 0, pos = 0, item = 0;
	for (int gap = len / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < len; i += 1) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}