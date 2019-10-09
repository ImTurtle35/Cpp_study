// 12191706 ±èÁ¤Áø
// Chapter 10 - 10.12
// Compound-interest calculations with class DollarAmount and integers.
#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmount.h"
using namespace std;

int main() {
	DollarAmount d1{ 123, 45 }; // $123.45
	DollarAmount d2{ 15, 76 }; // $15.76

	cout << "After adding d2 (" << d2.toString() << ") into d1 ("
		<< d1.toString() << "), d1 = ";
	d1 = d1 + d2; // modifies object d1
	cout << d1.toString() << "\n";

	cout << "After subtracting d2 (" << d2.toString() << ") from d1 ("
		<< d1.toString() << "), d1 = ";
	d1 = d1 - d2; // modifies object d1
	cout << d1.toString() << "\n";

	cout << "After dividing d2 (" << d2.toString() << ") from d1 ("
		<< d1.toString() << "), d1 = ";
	d1 = ((d1 / d2) * 100); // modifies object d1
	cout << d1.toString() << "\n";

	cout << "After multiplying d2 (" << d2.toString() << ") into d1 ("
		<< d1.toString() << "), d1 = ";
	d1 = (d1 * d2) / 100; // modifies object d1
	cout << d1.toString() << "\n\n";

	cout << "Enter integer interest rate and divisor. For example:\n"
		<< "for     2%, enter:    2 100\n"
		<< "for   2.3%, enter:   23 1000\n"
		<< "for  2.37%, enter:  237 10000\n"
		<< "for 2.375%, enter: 2375 100000\n> ";
	int rate; // whole - number interest rate
	int divisor; // divisor for rate
	cin >> rate >> divisor;

	DollarAmount balance{ 1000, 0 }; // initial principal amount in pennies
	cout << "\nInitial balance: " << balance.toString() << endl;

	// display headers
	cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

	// calcurate amount on deposit for each of ten years
	for (unsigned int year{ 1 }; year <= 10; year++) {
		// increase balance by rate % (i.e., rate / divisor)
		balance.addInterest(rate, divisor);

		// display the year and the amount;
		cout << setw(4) << year << setw(20) << balance.toString() << endl;
	}
}