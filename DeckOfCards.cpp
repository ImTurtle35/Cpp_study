// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.23
// Member-function definitionsfor class DeckOfCards.
#include "Card.h"
#include "DeckOfCards.h"
#include <ctime>
#include <cstdlib>
using namespace std;

// (c) default constructor that initializes the Cards in the deck.
DeckOfCards::DeckOfCards() {
	currentCard = 0;
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			deck[(i - 1) * 4 + j] = Card(Faces(i), Suits(j));
		}
	}
}

// (d) shuffles the Cards in the deck.
void DeckOfCards::shuffle() {
	// For each Card, randomly select another Card in the deck and swap the two Cards.
	srand(static_cast<unsigned int>(time(0)));
	for (int i{ 1 }; i <= 52; i++) {
		Card savecard = deck[i];
		deck[i] = deck[rand() % 52 + 1];
		deck[(rand() % 52) + 1] = savecard;
	}
}

// (e) returns the next Card object from the deck.
Card DeckOfCards::dealCard() {
	Card savecard = (deck[++currentCard]);
	return savecard;
}

// (f) returns a bool value indicating whether there are more Cards to deal.
bool DeckOfCards::moreCards() {
	if (currentCard <= 52)
		return true;
	else
		return false;
}

