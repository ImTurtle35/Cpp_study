// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.14
// HugeInteger Class definition.
#pragma once
#include <string>

// prevent multiple inclusions of header
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

// HugeInteger class definition
class HugeInteger {

public:
	HugeInteger(); // constructor

	void input(int num[40]); // input function
	void const output(); // output function

	HugeInteger add(const HugeInteger&); // add function
	HugeInteger subtract(const HugeInteger&); // subtract function

	bool isEqualTo(const HugeInteger&); // isEqualTo function
	bool isNotEqualTo(const HugeInteger&); // isNotEqualTo function
	bool isGreaterThan(const HugeInteger&); // isGreaterThan function
	bool isLessThan(const HugeInteger&); // isLessThan function
	bool isGreaterThanOrEqualTo(const HugeInteger&); // isGreaterThanOrEqualTo function
	bool isLessThanOrEqualTo(const HugeInteger&); // isLessThanOrEqualTo function

	bool isZero(); // isZero function

	~HugeInteger(); // destructor
private:
	int number[40]; // 40-element array of digits to store integers as large as 40 digits each.
};

#endif