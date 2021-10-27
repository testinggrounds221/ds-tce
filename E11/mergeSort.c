#define LEN 10

#include<stdio.h>
#include<stdlib.h>

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

void printArray(int* arr, int len) {
	for (int i = 0;i < len;i++)	printf("%d, ", arr[i]);
}

int main(int argc, char const* argv[])
{
	int len = LEN;
	int keys[LEN] = { 21,23,67,23,12,21,20,30,40,50 };
	mergeSort(keys, 0, LEN - 1);
	printArray(keys, len);
	return 0;
}