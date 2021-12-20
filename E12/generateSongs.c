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