#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct myStr {
	char name[30];
	int len;
};


struct myStr* newStr() {
	struct myStr* s = (struct myStr*)(malloc(sizeof(struct myStr)));
	s->len = 0;
	strcpy(s->name, " ");
	return s;
}

void printString(struct myStr* s) {
	printf("%s", s->name);
}

void assignString(struct myStr* s, char str[]) {
	strcpy(s->name, str);
}


int main(int argc, char const* argv[])
{
	char c[] = "New string"; // init

	char c2[50] = "Heyy";
	printf("%s", c);

	printf("%s", c2);

	char name[30];
	printf("Enter name: ");
	fgets(name, sizeof(name), stdin);
	struct myStr* s = newStr();

	assignString(s, name);
	printString(s);
	// puts(name);

	// scanf("%d");
	return 0;
}
