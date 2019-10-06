// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.23
// Member-function definitions for class Card.
#include "Card.h"
#include <sstream>
#include <iostream>
using namespace std;

std::string Card::faces[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
"Eight", "Nine", "Ten", "Jack", "Queen", "King" };
std::string Card::suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
// provide a constructor that enables objects of this class to be initialized when they are created.

Card::Card() {
	
}

// return a string representation of a Card in the form face of suit.
string Card::toString(int a, int b) const {
	ostringstream output;
	output << faces[a] + " of " + suits[b] << endl;
}
