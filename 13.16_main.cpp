// 12191706 ±èÁ¤Áø
// Chapter.13_13.16
// Complex test program.
#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex complex; // create object complex

	cout << "Enter complex number in the form real + imaginary'i':\n";

	if (((cin >> complex).fail()) == 0) {
		cout << "The complex number entered was:\n";
		cout << complex << endl;
	}
	else
		cout << "Wrong Data input\n";
}

// 123 + 123i