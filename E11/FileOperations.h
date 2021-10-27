// C program to Open a File,
// Write in it, And Close the File

# include <stdio.h>
# include <string.h>
#include <stdlib.h>

void generateRandomFile(int numOfKeys) {
	FILE* filePointer;
	filePointer = fopen("randomNumbers.txt", "w");
	for (int i = 0; i < numOfKeys; ++i)
	{
		fprintf(filePointer, "%d ", rand() % numOfKeys);
	}
	fprintf(filePointer, "\n");
	fclose(filePointer);
}

void fillArray(int arr[], int numOfKeys) {
	FILE* fileReader;
	fileReader = fopen("randomNumbers.txt", "r");
	int num;
	for (int i = 0; i < numOfKeys; ++i) {
		fscanf(fileReader, "%d ", &num);
		arr[i] = num;
	}
}

void writeSortedArray(int arr[], int numOfKeys) {
	FILE* filePointer;
	filePointer = fopen("sortedNumbers.txt", "w");
	for (int i = 0; i < numOfKeys; ++i)
	{
		fprintf(filePointer, "%d ", arr[i]);
	}
	fprintf(filePointer, "\n");
	fclose(filePointer);
}
