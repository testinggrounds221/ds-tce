#include<stdio.h>
#include<stdlib.h>

int getIndex(int* arr, int n, int key) {
	for (int i = 0;i < n;i++) {
		if (arr[i] == key) return i;
	}
	return 0;
}

int getNextBigger(int* arr, int n, int key)
{
	int nxtBiggest = -1;
	for (int i = getIndex(arr, n, key) + 1; i < n; i++)
	{
		if (key < arr[i])
		{
			return arr[i];
		}
	}
	return nxtBiggest;
}

int main()
{
	int numEle = 0;
	int tempNum = 0;
	int key = 0;
	scanf("%d", &numEle);
	int* arr = (int*)(malloc(numEle * sizeof(int)));
	for (int i = 0;i < numEle;i++) {
		scanf("%d ", &tempNum);
		arr[i] = tempNum;
	}
	scanf("%d", &key);
	printf("%d", getNextBigger(arr, numEle, key));
	return 0;
}