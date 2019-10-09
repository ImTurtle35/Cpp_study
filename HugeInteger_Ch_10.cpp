// 12191706 ±èÁ¤Áø
// HugeInteger member-function and friend-function definitions.
#include <cctype> // isdigit function prototype
#include "HugeInteger_Ch_10.h" // HugeInteger class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger(long value) {
	// place digits of argument into array
	for (int j{ digits - 1 }; value != 0 && j >= 0; j--) {
		integer[j] = value % 10;
		value /= 10;
	}
}

// conversion constructor that converts a character string
// representing a large integer into a HugeInteger object
HugeInteger::HugeInteger(const string& number) {
	// place digits of arguments into array
	int length = number.size();

	for (int j{ digits - length }, k{ 0 }; j < digits; ++j, ++k) {
		if (isdigit(number[k])) { // ensure that character is a digit
			integer[j] = number[k] - '0';
		}
	}
}


// addtion operators
// HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+(const HugeInteger& op2) const {
	HugeInteger temp; // temporary result
	int carry = 0;

	for (int i{ digits - 1 }; i >= 0; i--) {
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		// determine whether to carry a 1
		if (temp.integer[i] > 9) {
			temp.integer[i] %= 10; // reduce to 0 - 9
			carry = 1;
		}
		else {
			// no carry
			carry = 0;
		}
	}

	return temp; // return copy of temporary object
}

// HugeInteger + int
HugeInteger HugeInteger::operator+(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this + HugeInteger(op2);
}

// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::operator+(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this + HugeInteger(op2);
}


// minus operators
// HugeInteger - HugeInteger
HugeInteger HugeInteger::operator-(const HugeInteger& op2) const {
	HugeInteger temp; // temporary result

	for (int i{ digits - 1 }; i >= 0; i--) {
		temp.integer[i] += integer[i] - op2.integer[i];

		// determine whether to carry a 10
		if (temp.integer[i] < 0) {
			temp.integer[i] += 10; 
			temp.integer[i-1] -= 1;
		}
		
	}

	return temp; // return copy of temporary object
}

// HugeInteger - int
HugeInteger HugeInteger::operator-(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator- for two HugeInteger objects
	return *this - HugeInteger(op2);
}

// HugeInteger - string that represents large integer value
HugeInteger HugeInteger::operator-(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator+ for two HugeInteger objects
	return *this - HugeInteger(op2);
}


// multiplication operators
// HugeInteger * HugeInteger
HugeInteger HugeInteger::operator*(const HugeInteger& op2) const {
	HugeInteger temp; // temporary result
	int carry = 0;

	for (int i{ 39 }; i >= (40 - digits); i--) {
		for (int j{ 39 }, k{ i }; k >= 0; j--, k--) {
			temp.integer[k] = (integer[j] * op2.integer[i]) + temp.integer[k] + carry;
			carry = temp.integer[k] / 10;
			temp.integer[k] = temp.integer[k] % 10;
		}
	}

	return temp; // return copy of temporary object
}

// HugeInteger * int
HugeInteger HugeInteger::operator*(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator* for two HugeInteger objects
	return ((*this) * (HugeInteger(op2)));
}

// HugeInteger * string that represents large integer value
HugeInteger HugeInteger::operator*(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator* for two HugeInteger objects
	return *this * HugeInteger(op2);
}


// division operators
// HugeInteger / HugeInteger
HugeInteger HugeInteger::operator/(const HugeInteger& op2) const {
	HugeInteger temp; // temporary result
	HugeInteger save;
	if (*(this) < op2)
		return temp;
	else if (*(this) == op2)
		return HugeInteger(1);
	else {
		for (int i{ 0 }; i < digits; i++) {
			save = (save*10) + integer[i];
			if(op2 <= save) {
				for (int j{ 9 }; j > 0; j--) {
					if (op2 * j <= save) {
						temp.integer[i] = j;
						save = save - (op2 * j);
					}
				}
			}
		}

		return temp;
	}
}

// HugeInteger / int
HugeInteger HugeInteger::operator/(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator/ for two HugeInteger objects
	return (*this) / (HugeInteger(op2));
}

// HugeInteger / string that represents large integer value
HugeInteger HugeInteger::operator/(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator/ for two HugeInteger objects
	return (*this) / (HugeInteger(op2));
}


// equality operators;
// HugeInteger == HugeInteger
bool HugeInteger::operator==(const HugeInteger& op2) const {
	for (int i{ 0 }; i < 40; i++) {
		if (integer[i] != op2.integer[i])
			return false;
	}
	return true;
}

// HugeInteger == int
bool HugeInteger::operator==(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator== for two HugeInteger objects
	return (*this) == (HugeInteger(op2));
}

// HugeInteger == string that represents large integer value
bool HugeInteger::operator==(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator== for two HugeInteger objects
	return (*this) == (HugeInteger(op2));
}


// Not equality operators;
// HugeInteger != HugeInteger
bool HugeInteger::operator!=(const HugeInteger& op2) const {
	if (*(this) == op2)
		return false;
	return true;
}

// HugeInteger != int
bool HugeInteger::operator!=(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator!= for two HugeInteger objects
	return (*this) != (HugeInteger(op2));
}

// HugeInteger != string that represents large integer value
bool HugeInteger::operator!=(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator!= for two HugeInteger objects
	return (*this) != (HugeInteger(op2));
}


// greater than operators;
// HugeInteger > HugeInteger
bool HugeInteger::operator>(const HugeInteger& op2) const {
	for (int i{ 0 }; i < digits; i++) {
		if (integer[i] < op2.integer[i])
			return false;
		if (integer[i] > op2.integer[i])
			return true;
	}
	return false;
}

// HugeInteger > int
bool HugeInteger::operator>(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator> for two HugeInteger objects
	return (*this) > (HugeInteger(op2));
}

// HugeInteger > string that represents large integer value
bool HugeInteger::operator>(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator> for two HugeInteger objects
	return (*this) > (HugeInteger(op2));
}


// less than operators;
// HugeInteger < HugeInteger
bool HugeInteger::operator<(const HugeInteger& op2) const {
	for (int i{ 0 }; i < digits; i++) {
		if (integer[i] > op2.integer[i])
			return false;
		if (integer[i] < op2.integer[i])
			return true;
	}
	return false;
}

// HugeInteger < int
bool HugeInteger::operator<(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator< for two HugeInteger objects
	return (*this) < (HugeInteger(op2));
}

// HugeInteger < string that represents large integer value
bool HugeInteger::operator<(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator< for two HugeInteger objects
	return (*this) < (HugeInteger(op2));
}


// greater than and equal operators;
// HugeInteger >= HugeInteger
bool HugeInteger::operator>=(const HugeInteger& op2) const {
	if (*(this) < op2)
		return false;
	else
		return true;
}

// HugeInteger >= int
bool HugeInteger::operator>=(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator>= for two HugeInteger objects
	return (*this) >= (HugeInteger(op2));
}

// HugeInteger >= string that represents large integer value
bool HugeInteger::operator>=(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator>= for two HugeInteger objects
	return (*this) >= (HugeInteger(op2));
}


// less than and equal operators;
// HugeInteger <= HugeInteger
bool HugeInteger::operator<=(const HugeInteger& op2) const {
	if (*(this) > op2)
		return false;
	else
		return true;
}

// HugeInteger <= int
bool HugeInteger::operator<=(int op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator<= for two HugeInteger objects
	return (*this) <= (HugeInteger(op2));
}

// HugeInteger <= string that represents large integer value
bool HugeInteger::operator<=(const string& op2) const {
	// convert op2 to a HugeInteger, then invoke
	// operator<= for two HugeInteger objects
	return (*this) <= (HugeInteger(op2));
}

// overloaded output operator
ostream& operator<<(ostream& output, const HugeInteger& num) {
	int i;

	// skip leading zeros
	for(i = 0; (i < HugeInteger::digits) && (0 == num.integer[i]); ++i) { }

	if (i == HugeInteger::digits) {
		output << 0;
	}
	else {
		for (; i < HugeInteger::digits; ++i) {
			output << num.integer[i];
		}
	}

	return output;
}