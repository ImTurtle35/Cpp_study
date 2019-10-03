// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.5
// Member-function definitions for class Quadratic.
#pragma once
#include <sstream>
#include <cmath>
#include <string>
#include "Quadratic_Equations.h" // include definition of class Quadratic from Quadratic_Equations.h
using namespace std;

// provide a constructor that enables objects of this class to be initialized when they are created.
Quadratic::Quadratic(double a_value, double b_value, double c_value, char value)
	: a{ a_value }, b{ b_value }, c{ c_value }, variable{ value } {
	if (a == 0)	a = 1; // if 0 is given to a, assign 1 to a.
}

// adds two quadratic equations by adding the corresponding values of a, b, and c.
void Quadratic::add(const Quadratic& quadratic) {
	a += quadratic.a;
	b += quadratic.b;
	c += quadratic.c;
}

// subtracts two quadratic equations by adding the corresponding values of a, b, and c.
void Quadratic::subtract(const Quadratic& quadratic) {
	a -= quadratic.a;
	b -= quadratic.b;
	c -= quadratic.c;
}

// return a string representation of a quadratic in the form ax^2 + bx + c = 0.
string Quadratic::toString() const {
	ostringstream output;
	output << a << variable << "^2 + " << b << variable << " + " << c << " = " << 0;
	return output.str();
}

// solves a quadratic equation using the quadratic frmula
string Quadratic::solve() const {
	ostringstream output;
	if (pow(b, 2) - 4 * a * c > 0) {
		output << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << " ¶Ç´Â " << (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << "\n";
		return output.str();
	}

	else if (pow(b, 2) - 4 * a * c == 0) {
		output << (-b) / (2 * a) << "\n";
		return output.str();
	}

	else {
		output << "No Real Roots.\n";
		return output.str();
	}
}
