// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.6
// Member-function definitions for class Rational.
#include <sstream>
#include <string>
#include "Rational.h"
using namespace std;

int save;

// return the greatest common measure for smooth calcurate
int gcd(int num1, int num2) {
	if (num2 == 0)
		return num1;
	else
		return gcd(num2, num1 % num2);
}

// Rational constructor initializes each data member
Rational::Rational(int n, int d) : numerator{ n }, denominator{ d } {
	// store the fraction in reduced form
	numerator /= gcd(n, d); 
	denominator /= gcd(n, d);
}

// adds two Rational numbers
void Rational::add(const Rational& rational) {
	numerator = (numerator * rational.denominator) + (rational.numerator * denominator);
	denominator *= rational.denominator;

	// store the fraction in reduced form
	save = gcd(numerator, denominator);
	numerator /= save;
	denominator /= save;
}

// subtracts two Rational numbers
void Rational::subtract(const Rational& rational) {
	numerator = (numerator * rational.denominator) - (rational.numerator * denominator);
	denominator *= rational.denominator;

	// store the fraction in reduced form
	save = gcd(numerator, denominator);
	numerator /= save;
	denominator /= save;
}

// multiplyies two Rational numbers
void Rational::multiply(const Rational& rational) {
	numerator *= rational.numerator;
	denominator *= rational.denominator;

	// store the fraction in reduced form
	save = gcd(numerator, denominator);
	numerator /= save;
	denominator /= save;
}

// divides two Rational numbers
void Rational::divide(const Rational& rational) {
	numerator *= rational.denominator;
	denominator *= rational.numerator;

	// store the fraction in reduced form
	save = gcd(numerator, denominator);
	numerator /= save;
	denominator /= save;
}

// returns a string representation of a Rational number in the form a/b
string Rational::toRationalString() const {
	ostringstream output;
	output << numerator << '/' << denominator;
	return output.str();
}

// returns the Rational number as a doulbe
double Rational::toDouble() const {
	double decimal;
	decimal = static_cast<double>(numerator) / static_cast<double>(denominator);
	return decimal;
}