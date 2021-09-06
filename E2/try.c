// Donor name, Donor ID, Blood group, Gender, Phone number, Place of living.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct donor
{
	char name[20];
	char bgroup[4];
	char gender[5];
	char number[20];
	char place[20];
};
struct donor d[100];
void printarr(int no);
int insert(int pos, int no);
int action(int no);
int delete(int pos, int no);
int search(int no);

int main() {
	int no, i, pos, b, a, res;

	printf("Enter number of donors");
	scanf("%d", &b);
	no = b - 1;

	printf("ENTER DONOR'S DETAILS");
	printf("In Name,Bloodgroup(O,A,AB,B)(+/-),Gender(F/M),Number(without 91),Place");
	printf("\n");
	for (i = 0;i <= no;i++) {
		printf("Enter %d Donor detail\n", i + 1);
		scanf("%s", d[i].name);
		scanf("%s", d[i].bgroup);
		scanf("%s", d[i].gender);
		scanf("%s", d[i].number);
		scanf("%s", d[i].place);
	}
	action(no);


}

void printarr(int no) {
	int i;
	printf("entrynumber  Name\tbloodgroup gender  number\t place\t\t ");
	printf("\n");
	for (i = 0;i <= no;i++) {
		printf("%s\t,%s\t,%s\t,%s\t,%s\t,%d\t", i + 1, d[i].name, d[i].bgroup, d[i].gender, d[i].number, d[i].place);
		printf("\n");
	}
	action(no);
}
int insert(int pos, int no) {
	int i;
	for (i = no + 1;i > pos;i--) {
		d[i] = d[i - 1];
	}
	printf("Enter details for the donor\n");
	scanf("%s", d[pos].name);
	scanf("%s", d[pos].bgroup);
	scanf("%s", d[pos].gender);
	scanf("%s", d[pos].number);
	scanf("%s", d[pos].place);
	no = no + 1;
	action(no);
	return 0;
}
int action(int no) {
	int act, pos, b, a, res, nam, i, m;
	printf("MENU\n 1=print the details\n 2=insert new donor\n 3=delete a donor\n 4=search a donor\n 5=exit\n");
	scanf("%d", &act);
	switch (act)
	{
	case 1:
		printarr(no);
		break;
	case 2:
		printf("Where do you want to add the new entry \n 1= E(End), 2=F(first),3=P(Positon)\n");
		scanf("%d", &res);
		if (res == 1) {
			insert(no, no);
		}
		else if (res == 2)
		{
			insert(0, no);
		}
		else {
			printf("in what position do you want it to be inserted ");
			scanf("%d", &a);
			pos = a - 1;
			insert(pos, no);
		}
		break;
	case 3:
		m = search(no);
		if (m == -1) {
			printf("element not found");
			action(no);
		}
		else {
			delete(m, no);
		}
		break;
	case 4:
		m = search(no);
		if (m == -1) {
			printf("element not found");
			action(no);
		}
		else {
			printf("the element is found as %dth entry", m + 1);
		}
		action(no);
		break;
	case 5:
		exit(0);


	default:
		break;
	}

}
int delete(int pos, int no) {
	int i;
	for (i = pos; i < no; i++)
	{
		d[i] = d[i + 1];
	}
	no = no - 1;
	action(no);

}

int search(int no) {
	int i, pos;
	char nam[20];
	printf("Enter the name of the person who must be searched");
	scanf("%s", nam);
	for (i = 0;i <= no;i++) {
		if (strcmp(d[i].name, nam) == 0) {
			pos = i;
			return pos;

		}
		else {
			continue;
		}
	}
	return -1;
}
