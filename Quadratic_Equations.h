// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.5
// Quadratic class definition.
#pragma once
#include <string>

// prevent multiple inclusions of header
#ifndef QUADRATIC_H
#define QUADRATIC_H

// Quadratic class definition
class Quadratic {
public:
	explicit Quadratic(double a = 1, double b = 0, double c = 0, char value = 'x'); // default constructor

	void add(const Quadratic&); // add function

	void subtract(const Quadratic&); // subtract function

	std::string toString() const; // quadratic equation format string
	
	std::string solve() const; // answer of equation format string

private:
	double a = 1; // not allow 0
	double b = 0; 
	double c = 0;
	char variable = 'x'; // variable used in the equation
};

#endif