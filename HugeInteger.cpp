#include "HugeInteger.h"
#include <iostream>
using namespace std;

//HugeInteger Class Functions

HugeInteger::HugeInteger(){
	for (int i{ 0 }; i < 40; i++) {
		number[i] = 0;
	}
}

HugeInteger::~HugeInteger(){}

void HugeInteger::input(int num[40]){
	for (int i{ 0 }; i < 40; i++) {
		number[i] = num[i];
	}
}

void const HugeInteger::output() {
	for (int i{ 0 }; i < 40; i++) {
		cout << number[i];
	}
	cout << "\n";
}

bool HugeInteger::isZero() {
	bool result = false;
	for (int i{ 0 }; i < 40; i++) {
		if (number[i] != 0) {
			result = true;
			break;
		}
    }
	return result;
}

bool HugeInteger::isEqualTo(const HugeInteger& other) {
	bool result = true;
	for (int i{ 0 }; i < 40; i++) {
		if (number[i] != other.number[i]) {
			result = false;
			break;
		}
	}
	return result;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& other) {
	bool result = false;
	if (isNotEqualTo(other) == false)
		result = true;
	return result;
}

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

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& other) {
	bool result = false;
	if (isGreaterThan(other) == true || isEqualTo(other) == true)
		result = true;
	return result;
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& other) {
	bool result = false;
	if (isLessThan(other) == true || isEqualTo(other) == true)
		result = true;
	return result;
}

HugeInteger HugeInteger::add(const HugeInteger& other) {
	HugeInteger result;
	for (int i{ 39 }; i >= 0; i--) {
		result.number[i] = number[i] + other.number[i];
		if (i > 0) {
			if (result.number[i] >= 10)
				result.number[i - 1]++;
		}
	}
	return result;
}

HugeInteger HugeInteger::subtract(const HugeInteger& other) {
	HugeInteger result;
	for (int i{ 39 }; i >= 0; i--) {
		result.number[i] = number[i] - other.number[i];
		if (i > 0) {
			if (result.number[i] < 0) {
				result.number[i] += 10;
				result.number[i - 1]--;
			}
		}
	}
	return result;
}

