#include"cQueue.h"

int main(int argc, char const* argv[])
{
	struct CircQueue* q = createQueue(5);

	int c = 0, val = 0;
	while (1) {
		printf("\n1.Enqueue 2.Dequeue 3.Traverse 4.Top\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("Value :	");
			scanf("%d", &val);
			enqueue(q, val);
			break;
		case 2:
			printf("%d", dequeue(q));
			break;
		case 3:
			traverse(*q);
			break;
		case 4:
			printf("%d", top(*q));
			break;
		}
	}
	printf("1.Enqueue 2.Dequeue 3.Traverse\n");
	enqueue(q, 10);
	enqueue(q, 11);
	enqueue(q, 12);
	enqueue(q, 13);
	enqueue(q, 14);
	enqueue(q, 15);
	traverse(*q);
	return 0;
}
