int main(int argc, char const* argv[])
{
	int** D1 = (int**)(malloc(5 * sizeof(int)));
	for (int i = 0;i < 5;i++) {
		D1[i] = (int*)(malloc(5 * sizeof(int)));
	}
	D1[0][0] = 3;

	return 0;

}
