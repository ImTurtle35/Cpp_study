// 12191706_±èÁ¤Áø
// Exercises 13.6

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a{ 40000 };
	const int SIZE{ 80 };
	char b[SIZE];
	int c{ 200 };
	int d{ 100 };
	int e;
	char charArray[10] = { 0 };
	double f{ 1.234 };

	// a) print integer 40000 left justified in a 15-digit field.
	cout << left << setw(15) << a << "\n";

	// b) Read a string into character array variable state.
	cin.read(b, 20);

	// c) Print 200 with and without a sign.
	cout << showpos << c << "\n";
	cout << noshowpos << c << "\n";

	// d) Print the decimal value 100 in hexadecimal form preceded by 0x.
	cout << hex << d << "\n";

	// e) Read characters into charArray until the character 'p' is encountered,
	// up to a limit of 10 characters (including the terminating null character).
	// Extract the delimiter from the input stream, and discard it.
	int i = 0;
	int character;
	while ((character = cin.get()) != 'p' && i < 9)
	{
		charArray[i++] = character;
	}
	cout << charArray << endl;
	

	// Print 1.234 in a 9-digit field with preceding zeros.
	cout << right;
	cout.fill('0');
	cout << setw(10) << f << "\n";

}