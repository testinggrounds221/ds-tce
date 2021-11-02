#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAXKEYLENGTH 10
#define MAXVALLENGTH 50

struct Song {
	char song_name[30];
	int duration;
	float rating;
}*emptySong;

struct Node {
	struct Node* lchild;
	int val;
	struct Node* rchild;
};



