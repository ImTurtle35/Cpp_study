// 12191706 ±èÁ¤Áø
// HugeInteger class definition.
#pragma once
#ifndef HugeInteger_H
#define HugeInteger_H

#include <array>
#include <iostream>
#include <string>

class HugeInteger {
	friend std::ostream& operator<<(std::ostream&, const HugeInteger&);
public:
	static const int digits{ 40 }; // maximum digits in a HugeInteger;

	HugeInteger(long = 0); // conversion/default constructor
	HugeInteger(const std::string&); // conversion constructor

	// addition operators;
	HugeInteger operator+(const HugeInteger&) const; // HugeInteger + HugeInteger
	HugeInteger operator+(int) const; // HugeInteger + int
	HugeInteger operator+(const std::string&) const; // HugeInteger + string that represents large integer value

	// minus operators;
	HugeInteger operator-(const HugeInteger&) const; // HugeInteger + HugeInteger
	HugeInteger operator-(int) const; // HugeInteger + int
	HugeInteger operator-(const std::string&) const; // HugeInteger + string that represents large integer value

	// multiplication operators;
	HugeInteger operator*(const HugeInteger&) const; //  HugeInteger * HugeInteger
	HugeInteger operator*(int) const; // HugeInteger * int
	HugeInteger operator*(const std::string&) const; // HugeInteger * string that represents large integer value

	// division operators;
	HugeInteger operator/(const HugeInteger&) const; // HugeInteger / HugeInteger
	HugeInteger operator/(int) const; // HugeInteger / int
	HugeInteger operator/(const std::string&) const; // HugeInteger / string that represents large integer value

	// equality operators;
	bool operator==(const HugeInteger&) const; // HugeInteger == HugeInteger
	bool operator==(int) const; // HugeInteger == int
	bool operator==(const std::string&) const; // HugeInteger == string that represents large integer value

	// Not equality operators;
	bool operator!=(const HugeInteger&) const; // HugeInteger != HugeInteger
	bool operator!=(int) const; // HugeInteger != int
	bool operator!=(const std::string&) const; // HugeInteger != string that represents large integer value

	// greater than operators;
	bool operator>(const HugeInteger&) const; // HugeInteger > HugeInteger
	bool operator>(int) const; // HugeInteger > int
	bool operator>(const std::string&) const; // HugeInteger > string that represents large integer value

	// less than operators;
	bool operator<(const HugeInteger&) const; // HugeInteger < HugeInteger
	bool operator<(int) const; // HugeInteger < int
	bool operator<(const std::string&) const; // HugeInteger < string that represents large integer value

	// greater than and equal operators;
	bool operator>=(const HugeInteger&) const; // HugeInteger >= HugeInteger
	bool operator>=(int) const; // HugeInteger >= int
	bool operator>=(const std::string&) const; // HugeInteger >= string that represents large integer value

	// less than and equal operators;
	bool operator<=(const HugeInteger&) const; // HugeInteger <= HugeInteger
	bool operator<=(int) const; // HugeInteger <= int
	bool operator<=(const std::string&) const; // HugeInteger <= string that represents large integer value
private:
	std::array<short, digits> integer{}; // default init to 0s
};
#endif
