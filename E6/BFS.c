#include"cQueue.h"

int BFS(int A[][8], int start) {
	int visited[8] = { 0 };
	struct CircQueue* q = createQueue(10);
	enqueue(q, start);
	visited[start] = 1;
	printf("%d ", start);

	while (!isEmpty(*q)) {
		int u = dequeue(q);
		for (int v = 1;v < 8;v++) {
			if (A[u][v] && !visited[v]) { 	//u->row/queue element
				visited[v] = 1;				//  v->COl				
				printf("%d ", v);
				enqueue(q, v);
			}
		}
	}
}

int main(int argc, char const* argv[])
{
	int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
			   {0, 0, 1, 1, 1, 0, 0, 0},
			   {0, 1, 0, 1, 0, 0, 0, 0},
			   {0, 1, 1, 0, 1, 1, 0, 0},
			   {0, 1, 0, 1, 0, 1, 0, 0},
			   {0, 0, 0, 1, 1, 0, 1, 1},
			   {0, 0, 0, 0, 0, 1, 0, 0},
			   {0, 0, 0, 0, 0, 1, 0, 0} };
	for (int i = 0;i < 8;i++) {
		printf("BFS traversal with %d as Initial Node : ", i);
		BFS(A, i);
		printf("\n");
	}
	return 0;
}
