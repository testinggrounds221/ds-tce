#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song {
	char song_name[30];
	int duration;
	float rating;
}*emptySong;

struct Node {
	char ch;
	struct Song* song;
	struct Node* next;
};

struct LL {
	struct Node* head;
};

void displaySong(struct Song song) {
	printf("Song Name : %s\n", song.song_name);
	printf("Duration in Secs : %d\n", song.duration);
	printf("Rating (x/10) : %.1f\n", song.rating);
}

void traverse(struct LL* ll) {
	struct Node* ptr = ll->head;
	while (ptr) {
		displaySong(*ptr->song);
		printf("\n");
		ptr = ptr->next;
	}
}

void insertSongPos(struct LL* ll, int pos, struct Song* song) { // Inserts After
	struct Node* nwNd = (struct Node*)(calloc(1, sizeof(struct Node)));
	nwNd->song = song;
	if (pos == 0 || !ll->head) {
		if (ll->head) {
			ll->head = ll->head->next;
			ll->head = nwNd;
		}
		else {
			ll->head = nwNd;
			ll->head->song = song;
		}
	}
	else {
		struct Node* ptr = ll->head;
		int i = 0;

		while (ptr->next && i < pos) { ptr = ptr->next;i++; }
		if (ptr->next) {
			nwNd->next = ptr->next;
			ptr->next = nwNd;
		}
		else {
			nwNd->next = NULL;
			ptr->next = nwNd;
		}
	}
}

struct Node* getNode(struct LL* ll, int pos) {
	if (pos == 0) return ll->head;
	int i = 0;
	struct Node* ptr = ll->head;
	while (ptr->next && i < pos - 1) { ptr = ptr->next;i++; }
	return ptr->next;
}

struct Song* dltHead(struct LL* ll) {
	if (!ll->head) return emptySong;
	struct Node* ptr = ll->head;
	struct Song* x = ptr->song;
	ll->head = ll->head->next;
	free(ptr);
	return x;
}

struct Song* dltNext(struct LL* ll, struct Node* dltNxt) { // Deletes Next Node
	if (!dltNxt || !dltNxt->next) return emptySong;
	struct Node* ptr = dltNxt->next;
	struct Song* x = ptr->song;
	dltNxt->next = dltNxt->next->next;
	free(ptr);
	return x;
}

struct Song* dltPos(struct LL* ll, int pos) { // Deletes Node	
	if (pos == 0) return dltHead(ll);
	if (!ll->head) return emptySong;
	return dltNext(ll, getNode(ll, pos - 1));

}

void appendSong(struct LL* ll, struct Song* song) {
	insertSongPos(ll, 9999, song);
}

struct Song* readSong() {
	struct Song* song = (struct Song*)(calloc(1, sizeof(struct Song)));
	printf("Enter Song Name : ");
	scanf("%s", &song->song_name);
	printf("Enter rating (x/10) : ");
	scanf("%f", &song->rating);
	printf("Enter duration in Secs : ");
	scanf("%d", &song->duration);

	return song;
}


