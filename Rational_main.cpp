// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.6
// driver program to test the functionality of the Rational class.
#include <iostream>
#include <string>
#include "Rational.h"
using namespace std;

int numerator, denominator;

void displayFraction(const string& message, const Rational& rational) {
	cout << message << "\nRational number: " << rational.toRationalString()
		<< "\nDecimal: " << rational.toDouble() << "\n\n";
}

int main() {
	Rational R1; // all arguments defaulted
	displayFraction("Default Rational number(R1): ", R1);

	// create new Rational number and display it
	cout << "Input next Rational number's numerator and denominator: ";
	cin >> numerator >> denominator;
	Rational R2(numerator, denominator);
	displayFraction("Another Rational number(R2): ", R2);

	// add two Rational numbers and display it
	R1.add(R2);
	displayFraction("R1 + R2: ", R1);
	R1.subtract(R2); // roll back

	// subtract two Rational numbers and display it
	R1.subtract(R2);
	displayFraction("R1 - R2: ", R1);
	R1.add(R2); // roll back

	// multiply two Rational numbers and display it
	R1.multiply(R2);
	displayFraction("R1 * R2: ", R1);
	R1.divide(R2); // roll back

	// divide two Rational numbers and display it
	R1.divide(R2);
	displayFraction("R1 / R2: ", R1);
	R1.multiply(R2); // roll back
}
