// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.6
// Rational Class definition.
#pragma once
#include <string>

// prevent multiple inclusions of header
#ifndef RATIONAL_H
#define RATIONAL_H

// raional class definition
class Rational {
public:
	explicit Rational(int n = 1, int d = 2); // default constructor

	void add(const Rational&); // add rational numbers

	void subtract(const Rational&); // subtract rational numbers

	void multiply(const Rational&); // multiply rational numbers

	void divide(const Rational&); // divide rational numbers

	std::string toRationalString() const; // rational number format string

	double toDouble() const; // decimal format string

private:
	int numerator;
	int denominator;
};

#endif