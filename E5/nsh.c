#include <stdio.h>
#include <stdlib.h> // prototype of malloc() is given here
int main()
{

	int r, c;
	printf("Enter Row : ");
	scanf("%d", &r);

	printf("Enter Col : ");
	scanf("%d", &c);


	int* arr = (int*)malloc(r * c * sizeof(int)); // total 12*4 = 48 bytes are allocated
	// malloc() returns void pointer. It needs to be typecast to required data type.
	int i, j, count = 0;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", arr + i * c + j);
	// when i=0, j=0, it gets expanded to *(arr + 0 + 0) => *(arr). It is assigned the value 1
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			printf("%d ", *(arr + i * c + j));
		printf("\n");
	}
	/* Code for further processing and free dynamically allocated memory */
	if (arr) free(arr);
	return 0;
}