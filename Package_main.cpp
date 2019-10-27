// 12191706 ±èÁ¤Áø
// Test program that creates objects of each type of Package and tests member function calculateCost.
#include <iostream>
#include <iomanip>
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

using namespace std;

int main() {
	// creates basepackage object and tests member function calculateCost.
	Package basepackage{ "Faker", 1234, "Seoul", "SKT", "T1", "Nuguri", 5678, "Incheon", "Damwon", "DW", 100, 0.1 };
	cout << fixed << setprecision(2);
	cout << "Basepackage inforamation has been created!\n"
		<< "Package's weight is 100 ounce.\n"
		<< "Cost per weight is 0.1\n"
		<< "Calculated Cost is : " << basepackage.calculateCost() << "\n\n";

	// creates tdpackage object and tests member function calculateCost.
	TwoDayPackage tdpackage{ "Khan", 1357, "Berlin", "SKT", "T1", "TheShy", 2468, "Sanghai", "Invictus Gaming", "IG", 100, 0.1, 30 };
	cout << "Twodaypackage information has been created!\n"
		<< "Flat fee is 30\n"
		<< "Calculated Cost is : " << tdpackage.calculateCost() << "\n\n";

	// creates onpackage object and tests member function calculateCost.
	OvernightPackage onpackage{ "Clid", 9876, "Seoul", "SKT", "T1", "Teddy", 5432, "Busan", "SKT", "T1", 100, 0.1, 0.2 };
	cout << "Overnight information has been created!\n"
		<< "Additional fee per ounce is 0.2\n"
		<< "Calculated Cost is : " << onpackage.calculateCost() << "\n";
}