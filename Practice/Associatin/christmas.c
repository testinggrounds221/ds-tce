#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int getMax(int* arr, int len) {
	int lastChrist = 0;
	int maxDist = 0;
	for (int i = 0;i < len;i++) {
		if (arr[i] == 1) {
			if (maxDist < (i - lastChrist - 1)) {
				maxDist = i - lastChrist - 1;
			}
			lastChrist = i;
		}
	}

	return maxDist;
}

int main(int argc, char const* argv[])
{
	int numHouses = 0;
	int christHouses = 0;
	int tempNum = 0;
	int key = 0;
	scanf("%d", &numHouses);
	scanf("%d", &christHouses);

	int* arr = (int*)(malloc(numHouses * sizeof(int)));
	for (int i = 0;i < christHouses;i++) {
		scanf("%d", &tempNum);
		arr[tempNum] = 1;
	}
	printf("%d", getMax(arr, numHouses));
	return 0;
}
