#include <stdio.h>
#include <stdlib.h>

struct Matrix {
	int r;
	int c;
	int* arr;
};

void createMatrixUser(int r, int c, struct Matrix* mtrx) {
	int count = 0;
	mtrx->r = r;
	mtrx->c = c;
	mtrx->arr = (int*)(malloc(r * c * sizeof(int)));
	printf("Elements will be in the following order : \n");
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) { printf("[%d %d]\t", i, j); }
		printf("\n");
	}
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			printf("Enter Element [%d %d] : ", i, j);
			scanf("%d", (mtrx->arr + i * c + j));
		}
	}
}

void createMatrixSeq(int r, int c, struct Matrix* mtrx) {
	int count = 0;
	// struct Matrix* mtrx;
	mtrx->r = r;
	mtrx->c = c;
	mtrx->arr = (int*)(malloc(mtrx->r * mtrx->c * sizeof(int)));
	for (int i = 0;i < mtrx->r;i++) {
		for (int j = 0;j < mtrx->c;j++) {
			*(mtrx->arr + (i * mtrx->c) + j) = ++count;
		}
	}
	// return mtrx;
}


void displayMatrix(struct Matrix mtrx) {

	for (int i = 0;i < mtrx.r;i++) {
		for (int j = 0;j < mtrx.c;j++)
			printf("%d\t", *(mtrx.arr + i * mtrx.c + j));
		printf("\n");
	}
}

void displayTMatrix(struct Matrix mtrx) {

	for (int i = 0;i < mtrx.r;i++) {
		for (int j = 0;j < mtrx.c;j++) printf("%d\t", *(mtrx.arr + j * mtrx.c + i));
		printf("\n");
	}

}

void transpose(struct Matrix* trn, struct Matrix mtrx) {
	trn->r = mtrx.c;
	trn->c = mtrx.r;
	trn->arr = (int*)(malloc(trn->r * trn->c * sizeof(int)));

	for (int i = 0; i < trn->r; i++)
	{
		for (int j = 0; j < trn->c; j++) {	
			*(trn->arr + i * trn->c + j) = *(mtrx.arr + j * mtrx.c + i);
		}
	}
}

void multiply(struct Matrix* mul, struct Matrix mat1, struct Matrix mat2) {
	int sum = 0;
	mul->r = mat1.r;
	mul->c = mat2.c;
	mul->arr = (int*)(malloc(mul->r * mul->c * sizeof(int)));
	for (int i = 0; i < mat1.r; i++)
	{
		for (int j = 0; j < mat2.c; j++)
		{
			for (int k = 0; k < mat2.r; k++)
			{
				sum = sum + *(mat1.arr + i * mat1.c + k) *
					*(mat2.arr + k * mat2.c + j);
				// sum = sum + first[c][k] * second[k][d];
			}
			*(mul->arr + i * mul->c + j) = sum;
			sum = 0;
		}
	}
}

int trace(struct Matrix mtrx) {
	int trace = 0;
	for (int i = 0; i < mtrx.r;i++) {
		trace += *(mtrx.arr + i * mtrx.r + i);
	}
	return trace;
}

int checkIdentity(struct Matrix mat) {
	for (int i = 0;i < mat.r;i++) {
		if (*(mat.arr + i * mat.r + i) != 1) return 0;
	}
	return 1;
}

int main(int argc, char const* argv[])
{
	int r = 4, c = 3, count = 0;
	printf("Enter Rows and Columns : ");
	scanf("%d %d", &r, &c);
	struct Matrix* mat = (struct Matrix*)(malloc(sizeof(struct Matrix)));
	struct Matrix* trn = (struct Matrix*)(malloc(sizeof(struct Matrix)));
	struct Matrix* mat2 = (struct Matrix*)(malloc(sizeof(struct Matrix)));
	struct Matrix* mul = (struct Matrix*)(malloc(sizeof(struct Matrix)));

	createMatrixUser(r, c, mat);
	printf("First Input Matrix is \n");
	displayMatrix(*mat);
	if (mat->r == mat->c)
		printf("\nTrace of the Matrix is : %d\n", trace(*mat));
	if (checkIdentity(*mat))printf("Matrix is an Identity Matrix\n");
	else printf("Matrix is an not an Identity Matrix\n");
	printf("Transpose of the Matrix is : \n");
	transpose(trn, *mat);
	displayMatrix(*trn);

	printf("Enter Rows and Columns of M2: ");
	scanf("%d %d", &r, &c);
	createMatrixUser(r, c, mat2);
	printf("\nSecond Input Matrix is \n");
	displayMatrix(*mat2);
	printf("Muliplication of Given Matrix 1 and 2 : \n");
	multiply(mul, *mat, *mat2);
	displayMatrix(*mul);
	return 0;
}