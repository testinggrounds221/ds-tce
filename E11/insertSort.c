#define LEN 10

#include<stdio.h>
#include<stdlib.h>

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

void printArray(int* arr, int len) {
	for (int i = 0;i < len;i++)	printf("%d, ", arr[i]);
}

int main(int argc, char const* argv[])
{
	int len = LEN;
	int keys[] = { 21,23,67,23,12,21,20,30,40,50 };
	insertionSort(keys, len);
	printArray(keys, len);
	return 0;
}