// 12191706 ±èÁ¤Áø
// Chapter.13_13.16
// Overloaded stream insertion and stream extraction operators
// for class Complex.
#include <iomanip>
#include "Complex.h"
using namespace std;


// Overloaded stream insertion operaotr; cannot be a member function
// if we would like to invoke it with cout << somecomplex;
ostream& operator<< (ostream& output, const Complex& complex) {
	output << "Real: " << complex.real
		<< "\nImaginary: " << complex.imaginary << "i"
		<< "\nComplex: " << complex.real << " + " << complex.imaginary << "i\n";

	return output; // enables cout << a << b << c;
}

// Overloaded stream extraction operator; cannot be a member function
// if we would like to invoke it with cin >> somePhoneNumber;
istream& operator>>(istream& input, Complex& complex)
{
	int number;
	int multiplier;
	char temp; // temporary variable used to store input

	input >> number; // get input

	
	if (input.peek() == ' ') {
		complex.real = number;
		input >> temp;

		multiplier = (temp == '+') ? 1 : -1;

		if (input.peek() != ' ')
			input.clear(ios::failbit);
		else {
			if (input.peek() == ' ') {
				input >> number;
				complex.imaginary = number;
				complex.imaginary *= multiplier;
				input >> temp;

				if (temp != 'i') 
					input.clear(ios::failbit);
			}
			else
				input.clear(ios::failbit);
		}
	}
	else if (input.peek() == 'i') {
		input >> temp;

		if (temp == 'i') {
			complex.real = 0;
			complex.imaginary = number;
		} 
		else
			input.clear(ios::failbit);
	} 
	else if (input.peek() == '\n') {
		complex.real = number;
		complex.imaginary = 0;
	}
	else
		input.clear(ios::failbit);

	return input;
}