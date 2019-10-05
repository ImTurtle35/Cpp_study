// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.14
// Member-functions definitions for class HugeInteger.
#include "HugeInteger.h" // include definition of class HugeInteger from HugeInteger.h
#include <iostream>
using namespace std;

//HugeInteger Class Functions

// provide a constructor that enables objects of this class to be initialized when they are created.
HugeInteger::HugeInteger() {
	for (int i{ 0 }; i < 40; i++) {
		number[i] = 0;
	}
}

HugeInteger::~HugeInteger() {}

// input 40 one-digit integers for each digit of a 40-digit integer.
void HugeInteger::input(int num[40]) {
	for (int i{ 0 }; i < 40; i++) {
		number[i] = num[i];
	}
}

// output 40-digit integer.
void const HugeInteger::output() {
	for (int i{ 0 }; i < 40; i++) {
		cout << number[i];
	}
	cout << "\n";
}

// distinguish hugeinteger is zero or not.
bool HugeInteger::isZero() {
	bool result = true;
	for (int i{ 0 }; i < 40; i++) {
		if (number[i] != 0) {
			result = false;
			break;
		}
	}
	return result;
}

// distinguish two hugeintegers are equal.
bool HugeInteger::isEqualTo(const HugeInteger& other) {
	for (int i{ 0 }; i < 40; i++) {
		if (number[i] != other.number[i]) {
			return false;
		}
	}
	return true;
}

// distinguish two hugeintegers are not equal.
bool HugeInteger::isNotEqualTo(const HugeInteger& other) {
	bool result = false;
	if (isEqualTo(other) == false)
		result = true;
	return result;
}

// distinguish hugeinteger is greater than other.
bool HugeInteger::isGreaterThan(const HugeInteger& other) {
	bool result = false;
	for (int i{ 0 }; i < 40; i++) {
		if (number[i] > other.number[i]) {
			result = true;
			break;
		}
		else if (number[i] < other.number[i])
			break;
	}
	return result;
}

// distinguish hugeinteger is less than other.
bool HugeInteger::isLessThan(const HugeInteger& other) {
	bool result = false;
	for (int i{ 0 }; i < 40; i++) {
		if (number[i] < other.number[i]) {
			result = true;
			break;
		}
		else if (number[i] > other.number[i])
			break;
	}
	return result;
}

// distinguish hugeinteger is greater than or equal to other.
bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) {
	bool result = false;
	if (isGreaterThan(other) == true || isEqualTo(other) == true)
		result = true;
	return result;
}

// distinguish hugeinteger is less than or equal to other.
bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) {
	bool result = false;
	if (isLessThan(other) == true || isEqualTo(other) == true)
		result = true;
	return result;
}

// add two huge integer
HugeInteger HugeInteger::add(const HugeInteger& other) {
	HugeInteger result;
	int save = 0;
	for (int i{ 39 }; i >= 0; i--) {
		result.number[i] = number[i] + other.number[i] + save;
		if (i > 0) {
			if (result.number[i] >= 10) {
				result.number[i] -= 10;
				save = 1;
			}
		}
	}
	return result;
}

// subtract two huge integer
HugeInteger HugeInteger::subtract(const HugeInteger& other) {
	HugeInteger result;
	int save = 0;
	for (int i{ 39 }; i >= 0; i--) {
		result.number[i] = number[i] - other.number[i] - save;
		save = 0;
		if (i > 0) {
			if (result.number[i] < 0) {
				result.number[i] += 10;
				save = 1;
			}
		}
	}
	return result;
}

