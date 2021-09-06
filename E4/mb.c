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
	if (isBalanced(exp)) printf("%s is Balanced\n", exp);
	else printf("%s is not balanced\n", exp);
}
int main(int argc, char const* argv[]) {
	ptBlnced("([a+b]*c)/e");
	ptBlnced("{([a+b]}*[c-d])/e}");
	ptBlnced("{([{a+b]*[c-d])/e}");
	printf("\nProgram Terminated\n");
	return 0;
}
