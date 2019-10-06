// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.23
// Card class definition.
#pragma once
#include <string>

// prevent multiple inclusions of header
#ifndef CARD_H
#define CARD_H

enum class Faces { Ace = 1, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
enum class Suits { Spades = 1, Hearts, Diamonds, Clubs };

// Card class definition
class Card {
public:
	Card(Faces f, Suits s);

	std::string toString(); // face of suit format string

private:
	Faces face;
	Suits suit;

	static std::string s_face[];
	static std::string s_suit[];
};
#endif