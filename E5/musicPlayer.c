#include "ll.h"

int main(int argc, char const* argv[])
{
	struct LL* ll = (struct LL*)(calloc(1, sizeof(struct LL)));


	emptySong = (struct Song*)(malloc(sizeof(struct Song)));
	emptySong->duration = 0;
	emptySong->rating = 0.0;
	strcpy(emptySong->song_name, "ERROR_EMPTY_SONG");

	while (1) {
		int c = 0, pos = 0;
		printf("1.Add Song\t2.Delete Position\t3.Show List\t4.Append Song\t5.Exit\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("\nEnter Pos to add : ");
			scanf("%d", &pos);
			insertSongPos(ll, pos, readSong());
			break;
		case 2:
			printf("\nEnter Pos to del : ");
			scanf("%d", &pos);
			printf("\nDeleted Song -> \n");
			displaySong(*dltPos(ll, pos));
			break;
		case 3:
			printf("\nCurrent Playlist\n");
			traverse(ll);
			break;
		case 4:
			appendSong(ll, readSong());
			break;
		case 5:
			break;
		}
	}


	// appendSong(ll, readSong());
	// // appendSong(ll, readSong());
	// // appendSong(ll, readSong());
	// // appendSong(ll, readSong());


	// traverse(ll);

	// // dltPos(ll, 0);
	// if (!getNode(ll, 22)) { printf("Nothing to delte"); }
	// printf("\nDeleted Song -> \n");
	// displaySong(*dltPos(ll, 0));
	// traverse(ll);
	// printf("\nDeleted Song -> \n");
	// displaySong(*dltPos(ll, 2));
	// traverse(ll);

	// printf("\nProgram end\n");
	// displaySong(*readSong());
	return 0;
}
