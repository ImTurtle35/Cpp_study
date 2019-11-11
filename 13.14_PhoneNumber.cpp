// 12191706 ±èÁ¤Áø
// Fig. 10.4: PhoneNumber.cpp
// Overloaded stream insertion and stream extraction operators
// for class PhoneNumber.
#include <iomanip>
#include "PhoneNumber.h"
using namespace std;


// Overloaded stream insertion operaotr; cannot be a member function
// if we would like to invoke it with cout << somePhoneNumber;
ostream& operator<< (ostream& output, const PhoneNumber& number) {
	output << "Area code: " << number.areaCode
		<< "\nExchange: " << number.exchange
		<< "\nLine: " << number.line
		<< "\n(" << number.areaCode << ") " << number.exchange << "-" << number.line << "\n";

	return output; // enables cout << a << b << c;
}

// Overloaded stream extraction operator; cannot be a member function
// if we would like to invoke it with cin >> somePhoneNumber;
istream& operator>> (istream& input, PhoneNumber& number) {
	number.areaCode = "";
	number.exchange = "";
	number.line = "";
	char chararray[15] = {};
	int i = 0;
	int character;
	while ( i < 14) {
		switch (i) {
		case 0: 
			if ((character = cin.get()) == '(') {
				chararray[i] = character;
			}
			else {
				cin.clear(ios::failbit);
			}
			break;
		case 4:
			if ((character = cin.get()) == ')') {
				chararray[i] = character;
			}
			else {
				cin.clear(ios::failbit);
			}
			break;
		case 5:
			if ((character = cin.get()) == ' ') {
				chararray[i] = character;
			}
			else {
				cin.clear(ios::failbit);
			}
			break;
		case 9:
			if ((character = cin.get()) == '-') {
				chararray[i] = character;
			}
			else {
				cin.clear(ios::failbit);
			}
			break;
		default:
			if ((character = cin.get())) {
				if(character >= '0' && character <= '9')
				chararray[i] = character;
			}
			else {
				cin.clear(ios::failbit);
			}
			break;
		}
		i++;
	}

	if (chararray[1] == '1' || chararray[1] == '0')
		cin.clear(ios::failbit);
	if (chararray[5] == '1' || chararray[5] == '0')
		cin.clear(ios::failbit);
	if (chararray[2] != '0' && chararray[2] != '1')
		cin.clear(ios::failbit);

	if (cin.fail() == 0) {
		for (int j{ 1 }; j < 4; j++) {
			number.areaCode += chararray[j];
		}
		for (int j{ 6 }; j < 9; j++) {
			number.exchange += chararray[j];
		}
		for (int j{ 10 }; j < 13; j++) {
			number.line += chararray[j];
		}
	}
	else {
		cout << "Wrong input input.\n";
	}
	
	return input; // enables cin >> a >> b >> c;
}

/*
input.ignore(); // skip (
input >> setw(3) >> number.areaCode; // input area code
input.ignore(2); // skip ) and space
input >> setw(3) >> number.exchange; // input exchange
input.ignore(); // skip dash(-)
input >> setw(4) >> number.line; // input line
*/