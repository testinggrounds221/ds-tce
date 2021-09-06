#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct Card {
	int Suit;
	int rank;
};

struct CardList
{
	struct Card* A;
	int size;
	int length;
};

void createDeck(struct CardList* deck, int sz) {
	deck->size = sz;
	deck->A = (struct Card*)(malloc(deck->size * sizeof(struct Card)));
	deck->length = 0;
}


int isValidCard(struct Card card) {
	if (card.Suit != -1 && card.rank != -1) return 1;
	return 0;
}

int isFull(struct CardList* deck) { //str-check
	return deck->length == deck->size;
}

int isEmpty(struct CardList deck) { //str-check
	if (isValidCard(deck.A[0])) return 0;
	return 1;
}


void DisplayCard(struct Card card) {
	char* suit = "";
	char rank[10];
	switch (card.Suit)
	{
	case 0:
		suit = "Spade";
		break;
	case 1:
		suit = "Heart";
		break;
	case 2:
		suit = "Club";
		break;
	case 3:
		suit = "Diamond";
		break;
	default:
		suit = "invalidSuit";
	}
	switch (card.rank) {
	case 0:
		strcpy(rank, "A");
		break;
	case 10:
		strcpy(rank, "J");
		break;
	case 11:
		strcpy(rank, "Q");
		break;
	case 12:
		strcpy(rank, "K");
		break;
	default:
		if ((card.rank > 1) && (card.rank) < 10) sprintf(rank, "%d", card.rank);
		else strcpy(rank, "iR");
	}
	printf("(%s of %ss) ", rank, suit);
}

void Display(struct CardList deck) {
	int i;
	printf("\nElements are\n");
	for (i = 0;i < deck.length;i++) DisplayCard(deck.A[i]);
}

void Insert(struct CardList* deck, int index, struct Card x)
{
	if (isFull(deck)) return;
	int i;
	if (index >= 0 && index <= deck->length)
	{
		for (i = deck->length;i > index;i--)
			deck->A[i] = deck->A[i - 1];
		deck->A[index] = x;
		deck->length++;
	}
}

void InsertCard(struct CardList* deck, int index) {
	int suit = 0;
	int rank = 0;
	printf("Enter Suit of Card(0-Spade 1-Hearts 2-Clubs 3-Diamond) : \n");
	scanf("%d", &suit);
	printf("Enter Rank of Card(1 - Ace, 11 - Jack, 12 - Queen, 13 - King) : \n");
	scanf("%d", &rank);
	struct Card cd = { suit,rank - 1 };
	Insert(deck, index, cd);
}

int isSameCard(struct Card card1, struct Card card2) {
	if ((card1.rank == card2.rank) &&
		(card1.Suit == card2.Suit)) return 1;
	return 0;
}

int Search(struct CardList deck, struct Card x) {
	for (int i = 0;i < deck.length;i++)
		if (isSameCard(deck.A[i], x)) return i;
	return -1;
}

int SearchCard(struct CardList deck) {
	int suit = 0;
	int rank = 0;
	printf("Enter Suit of Card(0-Spade 1-Hearts 2-Clubs 3-Diamond) : \n");
	scanf("%d", &suit);
	printf("Enter Rank of Card(1 - Ace, 11 - Jack, 12 - Queen, 13 - King) : \n");
	scanf("%d", &rank);
	struct Card cd = { suit,rank - 1 };
	return Search(deck, cd);
}

struct Card* GetElement(struct CardList deck, int index) {
	struct Card* card = (struct Card*)malloc(sizeof(struct Card));
	if (!isEmpty(deck) && (0 <= index) && (index < deck.length)) {
		card = &deck.A[index];
		return card;
	}
	card->rank = -1;
	card->Suit = -1;
	return card;
}

struct Card* GetFirst(struct CardList deck) { //str-check  
	return GetElement(deck, 0);
}

struct Card* GetLast(struct CardList deck) {
	return GetElement(deck, deck.length - 1);
}

void copyCard(struct Card* card1, struct Card* card2) {
	card1->rank = card2->rank;
	card1->Suit = card2->Suit;
}

struct Card* DeleteIndex(struct CardList* deck, int index) //Return typ
{
	struct Card* card = (struct Card*)malloc(sizeof(struct Card));
	if ((!isEmpty(*deck)) && (index >= 0) && (index < deck->length))
	{
		copyCard(card, &deck->A[index]);
		for (int i = index;i < deck->length - 1;i++)
			deck->A[i] = deck->A[i + 1];
		deck->length--;
		return card;
	}
	card->rank = -1;
	card->Suit = -1;
	return card;
}

void InsertLast(struct CardList* deck) {//Change parametre//str-check
	InsertCard(deck, deck->length);
}

void InsertFirst(struct CardList* deck, struct Card x) { //Change parametre//str-check
	Insert(deck, 0, x);
}

struct Card* DeleteLast(struct CardList* deck) { //Return typ
	return DeleteIndex(deck, deck->length - 1);
}

struct Card* DeleteFirst(struct CardList* deck) { //Return typ
	return DeleteIndex(deck, 0);
}

struct Card* DeleteElement(struct CardList* deck, struct Card card) { //Return typ
	int ind = Search(*deck, card);
	if (ind != -1) { return DeleteIndex(deck, ind); }
}

int main()
{
	struct CardList deck1, deck2;

	struct Card c1 = { 0,5 };
	struct Card c2 = { 2,6 };
	struct Card c3 = { 1,7 };



	// DisplayCard(c);

	int ch;
	int index, size;

	createDeck(&deck1, 13);

	do
	{
		printf("\nMenu\n");
		printf("1. Append\t");
		printf("2. Delete\t");
		printf("3. Search\t");
		printf("4. Display\t");

		printf("5.Exit\t");
		printf("\nEnter you choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: printf("Insertion of Card ");
			InsertLast(&deck1);
			break;
		case 2: printf("Enter index to Delete :");
			scanf("%d", &index);
			printf("Deleted Card is \n");
			DisplayCard(*DeleteElement(&deck1, *GetElement(deck1, index - 1)));
			break;
		case 3:printf("Enter card to search ");
			index = SearchCard(deck1);
			printf("Element position %d", index + 1);
			break;
		case 4:Display(deck1);
			break;
		}
	} while (ch < 5);
	return 0;
}
