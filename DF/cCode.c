#include<stdio.h>
#include<string.h>

int main()
{
	char strArr[1000][20], inpStr[20];
	int n, i, nq, ans;
	scanf("%d", &n);
	for (i = 0;i < n;i++)
		scanf("%s", strArr[i]);
	scanf("%d", &nq);
	while (nq > 0)
	{
		ans = 0;
		scanf("%s", inpStr);
		for (i = 0;i < n;i++)
		{
			if (strcmp(inpStr, strArr[i]) == 0)
				ans++;
		}
		printf("%d\n", ans);
		nq--;
	}
	return 0;
}
