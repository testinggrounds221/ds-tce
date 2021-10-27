#include <stdio.h>
#include <time.h>
#include "Sort.h"
#include "FileOperations.h"
#define NUMKEYS 100000

double calculateTimeTaken(int arr[]) {

	printf("Calculating Time Taken for Selection Sort\n");
	clock_t timeSelection;
	timeSelection = clock();
	selectionSort(arr, NUMKEYS);
	timeSelection = clock() - timeSelection;
	double selectionValue = ((double)timeSelection) / CLOCKS_PER_SEC;
	printf("Time Taken For selection Sort : %lf \n\n", selectionValue);

	printf("Calculating Time Taken for Bubble Sort\n");
	clock_t timeBubble;
	timeBubble = clock();
	bubbleSort(arr, NUMKEYS);
	timeBubble = clock() - timeBubble;
	double BubbleValue = ((double)timeBubble) / CLOCKS_PER_SEC;
	printf("Time Taken For Bubble Sort : %lf \n\n", BubbleValue);

	printf("Calculating Time Taken for Insertion Sort\n");
	clock_t timeInsertion;
	timeInsertion = clock();
	insertionSort(arr, NUMKEYS);
	timeInsertion = clock() - timeInsertion;
	double InsertionValue = ((double)timeInsertion) / CLOCKS_PER_SEC;
	printf("Time Taken For Insertion Sort : %lf \n\n", InsertionValue);

	printf("Calculating Time Taken for Shell Sort\n");
	clock_t timeShell;
	timeShell = clock();
	shellSort(arr, NUMKEYS);
	timeShell = clock() - timeShell;
	double ShellValue = ((double)timeShell) / CLOCKS_PER_SEC;
	printf("Time Taken For Shell Sort : %lf \n\n", ShellValue);

	printf("Calculating Time Taken for Merge Sort\n");
	clock_t timeMerge;
	timeMerge = clock();
	mergeSort(arr, 0, NUMKEYS);
	timeMerge = clock() - timeMerge;
	double mergeValue = ((double)timeMerge) / CLOCKS_PER_SEC;
	printf("Time Taken For Merge Sort : %lf \n\n", mergeValue);

	printf("Calculating Time Taken for Heap Sort\n");
	clock_t timeHeap;
	timeHeap = clock();
	heapSort(arr, NUMKEYS);
	timeHeap = clock() - timeHeap;
	double HeapValue = ((double)timeHeap) / CLOCKS_PER_SEC;
	printf("Time Taken For Heap Sort : %lf \n\n", HeapValue);

	printf("Calculating Time Taken for Quick Sort\n");
	clock_t timeQuick;
	timeQuick = clock();
	quicksort(arr, 0, NUMKEYS - 1);
	timeQuick = clock() - timeQuick;
	double QuickValue = ((double)timeQuick) / CLOCKS_PER_SEC;
	printf("Time Taken For Quick Sort : %lf \n\n", QuickValue);
}


int main()
{
	int arr[NUMKEYS];
	generateRandomFile(NUMKEYS);
	fillArray(arr, NUMKEYS);
	calculateTimeTaken(arr);
	return 0;
}