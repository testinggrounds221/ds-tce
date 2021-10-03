#include "stck.h"
  
int isBalanced(char* exp) {
	struct Stck* stk = createStck();
	int i = 0;
	while (exp[i]) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			stkPush(stk, exp[i]);
		if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if ((stkTop(*stk) == '(' && exp[i] == ')') ||
				(stkTop(*stk) == '{' && exp[i] == '}') ||
				(stkTop(*stk) == '[') && exp[i] == ']')
				stkPop(stk);
			else return 0;
		}
		i++;
	}
	if (!isStkEmpty(*stk)) return 0;
	return 1;
}

int ptBlnced(char* exp) {
	if (isBalanced(exp)) printf("File is Balanced\n");
	else printf("File is not balanced\n", exp);
}

int main()
{

	FILE* fPtr;

	char ch;
	char* fileContents = (char*)(calloc(1000, sizeof(char)));
	int k = 0;

	fPtr = fopen("D:\\Shreeram\\A_SEM3\\DS\\E4\\simpleC.c", "r");



	printf("File opened successfully. Reading file contents character by character. \n\n");

	do
	{

		ch = fgetc(fPtr);
		fileContents[k++] = ch;


		putchar(ch);

	} while (ch != EOF);

	ptBlnced(fileContents);

	fclose(fPtr);


	return 0;
}