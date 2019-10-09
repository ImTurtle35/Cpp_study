// 12191706 ±èÁ¤Áø
// HugeInteger test program.
#include <iostream>
#include "HugeInteger_Ch_10.h"
using namespace std;

int main() {
	HugeInteger n1{ 7654321 };
	HugeInteger n2{ 7891234 };
	HugeInteger n3{ "99999999999999999999999999999" };
	HugeInteger n4{ "1" };
	HugeInteger n5;
	HugeInteger n6;
	HugeInteger n7;

	cout << "n1 is " << n1 << "\nn2 is " << n2
		<< "\nn3 is " << n3 << "\nn4 is " << n4
		<< "\nn5 is " << n5 << "\n\n";

	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

	cout << n3 << " + " << n4 << "\n=" << (n3 + n4) << "\n\n";

	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << "\n\n";

	
	// HugeInteger n6 is for test multipication operation
	n6 = n1 * n2;
	cout << n1 << " * " << n2 << " = " << n6 << "\n\n";

	cout << n3 << " * " << n4 << " = " << (n3 * n4) << "\n\n";

	n6 = n1 * 9;
	cout << n1 << " * " << 9 << " = " << n6 << "\n\n";

	n6 = n2 * "10000";
	cout << n2 << " * " << "10000" << " = " << n6 << "\n\n";

	// HugeInteger n7 is for test division operation
	n6 = n1 / n2;
	cout << n1 << " / " << n2 << " = " << n6 << "\n\n";

	cout << n3 << " / " << n4 << " = " << (n3 / n4) << "\n\n";

	n6 = n1 / 9;
	cout << n1 << " / " << 9 << " = " << n6 << "\n\n";

	n6 = n2 / "10000";
	cout << n2 << " / " << "10000" << " = " << n6 << "\n\n";

	// test relational and equality operators.
	cout << "Display equality and relation of n1 and n2.\n";
	if (n1 == n2)
		cout << n1 << " == " << n2 << "\n";
	
	if (n1 != n2)
		cout << n1 << " != " << n2 << "\n";

	if (n1 > n2)
		cout << n1 << " > " << n2 << "\n";

	if (n1 < n2)
		cout << n1 << " < " << n2 << "\n";

	if (n1 >= n2)
		cout << n1 << " >= " << n2 << "\n";

	if (n1 <= n2)
		cout << n1 << " <= " << n2 << "\n";
}