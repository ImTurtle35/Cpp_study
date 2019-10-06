// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.23
// DeckOfCards class definition.
#pragma once
#include <string>
#include "Card.h"

// prevent multiple inclusions of header
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

// DeckOfCards class definition
class DeckOfCards {
public:
	explicit DeckOfCards(); // (c) default constructor

	void shuffle(); // (d) shuffles the Cards in the deck.

	Card dealCard(); // (e) returns the next Card object from the deck.

	bool moreCards(); // (f) distinguish whether there are more Cards to deal.
private:
	int currentCard; // (b) An integer currentCard representing the next card to deal.
	Card deck[53]; // (a) An array of Cards named deck to store the Cards.
};

#endif
