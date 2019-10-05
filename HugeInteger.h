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
	HugeInteger();

	void input(int num[40]);
	void const output();
	
	HugeInteger add(const HugeInteger&);
	HugeInteger subtract(const HugeInteger&);

	bool isEqualTo(const HugeInteger&);
	bool isNotEqualTo(const HugeInteger&);
	bool isGreaterThan(const HugeInteger&);
	bool isLessThan(const HugeInteger&);
	bool isGreaterThanOrEqualTo(const HugeInteger&);
	bool isLessThanOrEqualTo(const HugeInteger&);

	bool isZero();

	~HugeInteger();
private:
	int number[40];
};

#endif
