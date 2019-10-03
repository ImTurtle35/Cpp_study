// 12191706 ±èÁ¤Áø
// Chapter 9 - 9.5
// driver program to test the functionality of the Quadratic class.
#include <iostream>
#include "Quadratic_Equations.h"

using namespace std;

double a1, a2, b1, b2, c1, c2;

// displays Quadratic Equation of each conditions 
void displayEquations(const string& message, const Quadratic& quadratic) {
	cout << message << quadratic.toString() << "\nThe answer is : " << quadratic.solve() << "\n\n";
}

int main() {
	Quadratic q0; // all arguments defaulted
	displayEquations("Default quadratic equation: ", q0);

	// create a quadratic equation and display it
	cout << "Input first quadratic equation's varaibles(a, b, c, variable): ";
	cin >> a1 >> b1 >> c1;
	Quadratic q1(a1, b1, c1);
	displayEquations("q1: ", q1);

	// create another quadratic equation and display it
	cout << "Input next quadratic equation's varaibles(a, b, c, variable): ";
	cin >> a2 >> b2 >> c2;
	Quadratic q2(a2, b2, c2);
	displayEquations("q2: ", q2);

	// adds two quadratic equations and display it
	q1.add(q2);
	displayEquations("add q1 and q2: ", q1);
	q1.subtract(q2); // roll back

	// subtracts two quadratic equations and display it
	q1.subtract(q2);
	displayEquations("subtract q2 from q1: ", q1);
	q1.add(q2); // roll back
}