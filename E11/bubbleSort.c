#include<stdio.h>
#include<stdlib.h>

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

void printArray(int* arr, int len) {
	for (int i = 0;i < len;i++)	printf("%d, ", arr[i]);
}

int main(int argc, char const* argv[])
{
	int len = 10;
	int keys[] = { 21,23,67,23,12,21,20,30,40,50 };
	bubbleSort(keys, len);
	printArray(keys, len);
	return 0;
}