// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.14
// driver program to test the functionality of the HugeInteger class.
#include <iostream>
#include "HugeInteger.h"

using namespace std;

int HI1[40], H2[40];

void displayZero(const string&, HugeInteger&);
void displayRelationship(const string& , const string& , HugeInteger&, HugeInteger&);

int main() {
	HugeInteger H0;
	H0.output();
	displayZero("H0", H0);

	int h1[40];
	HugeInteger H1;
	for (int i{ 0 }; i < 40; i++) {
		cin >> h1[i];
	}
	H1.input(h1);
	H1.output();
	displayZero("H1", H1);
	displayRelationship("H1", "H0", H1, H0);

	int h2[40];
	HugeInteger H2;
	for (int i{ 0 }; i < 40; i++) {
		cin >> h2[i];
	}
	H2.input(h2);
	H2.output();
	displayZero("H1", H1);
	displayRelationship("H1", "H2", H1, H2);

	(H1.add(H2)).output();
	(H1.subtract(H2)).output();
}

void displayZero(const string& message , HugeInteger& huge) {
	if (huge.isZero())
		cout << message << " = 0.\n";
	else
		cout << message << " != 0.\n";
}

void displayRelationship(const string& message, const string& message2, HugeInteger& huge, HugeInteger& other) {
	if (huge.isEqualTo(other))
		cout << message << " == " << message2 << ".\n";
	if (huge.isNotEqualTo(other))
		cout << message << " != " << message2 << ".\n";
	if (huge.isGreaterThan(other))
		cout << message << " > " << message2 << ".\n";
	if (huge.isLessThan(other))
		cout << message << " < " << message2 << ".\n";
	if (huge.isGreaterThanOrEqualTo(other))
		cout << message << " >= " << message2 << ".\n";
	if (huge.isLessThanOrEqualTo(other))
		cout << message << " <= " << message2 << ".\n";
}

/* h1's testcase:
   1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4

   h2's testcase:
   9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1 9 8 7 6 5 4 3 2 1 9 8 7 6
*/