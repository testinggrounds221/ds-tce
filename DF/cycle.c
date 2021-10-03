#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printCycle(int numElemtents, int index, int* arr) {
	for (int i = 0; i < numElemtents; i++)
	{
		printf("%index ", (i + index) % numElemtents);
		printf("%index\n", arr[(i + index) % numElemtents]);

	}
	puts("");
}

int main() {

	int numElemtents;
	int index;
	scanf("%index %index", &numElemtents, &index);
	int arr[numElemtents];
	for (int i = 0; i < numElemtents; i++)
	{
		scanf("%index", &arr[i]);
	}
	printCycle(numElemtents, index, arr);

	return 0;
}