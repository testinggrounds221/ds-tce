#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// void printArr(int*) {

// }


int main(int argc, char const* argv[])
{
	int m = 0;
	int n = 0;

	scanf("%d", &m);
	scanf("%d", &n);

	int* ptr, count = 0, i;
	int* arr = (int*)(malloc(m * n * sizeof(int)));

	char row[2 * n];
	for (int i = 0;i < m;i++) {
		fgets(row, 20, stdin);
		printf(row);
		for (int j = 0;j < m;j++) {
			printf("%c", row[j]);
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			printf("Enter Element [%d %d] : ", i, j);
			scanf("%d", (arr + i * n + j));
		}
	}

	return 0;
}
