// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.23
// Member-function definitions for class Card.
#include "Card.h"
#include <sstream>
#include <iostream>
using namespace std;

// (c) initialize static arrays of strings representing the faces and suits
std::string Card::s_face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
"Eight", "Nine", "Ten", "Jack", "Queen", "King" };
std::string Card::s_suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

// (b) provide a constructor that enables objects of this class to be initialized when they are created.
Card::Card(){}
Card::Card(Faces f, Suits s) : face(f), suit(s) {}

// (d) return a string representation of a Card in the form face of suit.
string Card::toString(){
	return s_face[static_cast<int>(face)-1] + " of " + s_suit[static_cast<int>(suit)-1] + " ";
}
