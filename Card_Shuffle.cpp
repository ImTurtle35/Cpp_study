// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.23
// driver program to test the functionality of the Card and DeckOfCards class.
#include <iostream>
#include <iomanip>
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

// variable for line up
int row_count;

int main() {
	DeckOfCards dc; // Create new Card deck and initialize it to default form

	dc.shuffle(); // shuffles the Cards in the deck.

	// deal the Cards in the deck and line up
	while (dc.moreCards()) {
		row_count++;
		Card savecard = dc.dealCard();
		cout << setw(20) << left << savecard.toString();

		if (row_count == 4) {
			cout << "\n";
			row_count = 0;
		}
	}
}