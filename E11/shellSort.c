#define LEN 10

#include<stdio.h>
#include<stdlib.h>

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

void printArray(int* arr, int len) {
	for (int i = 0;i < len;i++)	printf("%d, ", arr[i]);
}

int main(int argc, char const* argv[])
{
	int len = LEN;
	int keys[] = { 21,23,67,23,12,21,20,30,40,50 };
	shellSort(keys, len);
	printArray(keys, len);
	return 0;
}