#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct myStr {
	char str[30];
	int len;
};

struct myStr* createMyString() {
	struct myStr* str = (struct myStr*)(malloc(sizeof(struct myStr)));
	int l = 0;
	printf("Enter Your String : ");
	scanf("%s", str->str);
	while (str->str[l] != '\0') l++;
	str->len = l;
	// printf("\n");
	return str;
}

struct myStr* substr(struct myStr* str, int start, int end) {
	struct myStr* sub = (struct myStr*)(calloc(1, sizeof(struct myStr)));
	if (!(start <= str->len <= end)) return sub;

	if (start > end)
		for (int i = start, j = 0;i > end;i--, j++)
			sub->str[j] = str->str[i];
	else
		for (int i = start, j = 0;i < end;i++, j++)
			sub->str[j] = str->str[i];
	sub->len = abs(start - end);
	return sub;
}

struct myStr* reverse(struct myStr* str) {
	struct myStr* rev = (struct myStr*)(calloc(1, sizeof(struct myStr)));
	rev->len = str->len;
	for (int i = str->len - 1, j = 0;i >= 0;i--, j++) rev->str[j] = str->str[i];
	return rev;
}

int palindrome(struct myStr* str) {
	return strcmpi(str->str, reverse(str)->str) == 0;
}

int main(int argc, char const* argv[]) {
	struct myStr* str = createMyString();

	printf("Reversed String : %s\n", reverse(str)->str);

	if (palindrome(str)) printf("Given String is palindrome\n");
	else printf("Given String is not a palindrome\n");

	printf("Substring from 5 to 1 : %s\n", substr(str, 5, 1)->str);
	printf("Substring from 1 to 5 : %s\n", substr(str, 1, 5)->str);
	printf("Substring from 3 to 3 : %s\n", substr(str, 3, 3)->str);
	printf("Program Terminated");

	return 0;
}