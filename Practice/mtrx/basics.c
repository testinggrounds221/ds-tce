#include <stdio.h>
#include <stdlib.h>

struct Matrix {
	int r;
	int c;
	int* arr;
};

struct Matrix* newMtrx(int r, int c) {
	struct Matrix* m = (struct Matrix*)(malloc(sizeof(struct Matrix)));
	m->arr = (int*)(malloc(sizeof(int) * r * c));
	m->r = r;
	m->c = c;

	int count = 0;


	for (int i = 0;i < m->r;i++) {
		for (int j = 0;j < m->c;j++) {
			*(m->arr + (i * m->c) + j) = count++;
		}
	}
	// for (int i = 0;i < m->r;i++) {
	// 	for (int j = 0;j < m->c;j++) {
	// 		*(m->arr + (j * m->c) + i) = count++;
	// 	}
	// }

	// printf("%d", sizeof(int));
	return m;
}

void printM(struct Matrix* m) {
	for (int i = 0;i < m->r;i++) {
		for (int j = 0;j < m->c;j++)
			printf("%d\t", *(m->arr + i * m->c + j));
		printf("\n");
	}
}

void printT(struct Matrix* m) {
	for (int i = 0;i < m->r;i++) {
		for (int j = 0;j < m->c;j++)
			printf("%d\t", *(m->arr + j * m->c + i));
		printf("\n");
	}
}

struct Matrix* transpose(struct Matrix* mtrx) {
	struct Matrix* trn = (struct Matrix*)(malloc(sizeof(struct Matrix)));
	trn->r = mtrx->c;
	trn->c = mtrx->r;
	trn->arr = (int*)(malloc(trn->r * trn->c * sizeof(int)));

	for (int i = 0; i < trn->r; i++) {
		for (int j = 0; j < trn->c; j++) {
			*(trn->arr + i * trn->c + j) = *(mtrx->arr + j * mtrx->c + i);
		}
	}
	return trn;
}

void transposeNew(struct Matrix* trn, struct Matrix* mtrx) {
	trn->r = mtrx->c;
	trn->c = mtrx->r;

	for (int i = 0;i < trn->r;i++) {
		for (int j = 0;j < trn->c;j++) {
			*(trn->arr + i * trn->c + j) = *(mtrx->arr + j * mtrx->c + i);
		}
	}
}

int main(int argc, char const* argv[])
{
	struct Matrix* m = newMtrx(5, 4);
	struct Matrix* t = newMtrx(4, 5);

	printM(m);
	transposeNew(t, m);
	printf("\n");
	printM(t);
	return 0;
}
