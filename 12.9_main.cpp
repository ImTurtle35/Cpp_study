// Fig. 12.17: fig12_17.cpp
// Processing Employee drived-class objects with static binding
// then polymorphically cusing dyanmic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "Date.h"
using namespace std;

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype

int main() {
	cout << fixed << setprecision(2); // set floating-point formatting

	// create birth data of employees
	Date johnbirth(11, 5, 1996);
	Date suebirth(11, 2, 2000);
	Date bobbirth(11, 30, 1990);

	// create derived-class objects
	SalariedEmployee salariedEmployee{
		"John", "Smith", "111-11-1111", johnbirth, 800 };
	CommissionEmployee commissionEmployee{
		"Sue", "Jones", "333-33-3333", suebirth, 10000, .06 };
	BasePlusCommissionEmployee basePlusCommissionEmployee{
		"Bob", "Lewis", "444-44-4444", bobbirth, 5000, .04, 300 };

	// output each Employee's information and earnings using static binding
	cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
		<< "If the current month(11) is the month in which the Employee's birhtday occurs,\n"
		<< "add $100.00 bonus to the Employee's payroll"
		<< salariedEmployee.toString()
		<< "\nearned $" << salariedEmployee.earnings() << "\n\n"
		<< commissionEmployee.toString()
		<< "\nearned $" << commissionEmployee.earnings() << "\n\n"
		<< basePlusCommissionEmployee.toString()
		<< "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

	// create and initialize vector of three base-class pointers
	vector<Employee*> employees{ &salariedEmployee, &commissionEmployee,
	&basePlusCommissionEmployee };

	cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

	// call virtualViaPointer to print each Employee's information
	// and earnings using dynamic binding
	cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";

	for (const Employee* employeePtr : employees) {
		virtualViaPointer(employeePtr);
	}

	// call virtualViaReference to print each Employee's information
	// and earnings using dynamic binding
	cout << "VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCES\n";

	for (const Employee* employeePtr : employees) {
		virtualViaReference(*employeePtr); // note dereferencing
	}
}

// call Employee virtual functions toString and earnings off a 
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee* const baseClassPtr) {
	cout << baseClassPtr->toString()
		<< "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

// call Employee virtual functions toString and earnings off a
// base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef) {
	cout << baseClassRef.toString()
		<< "\nearned $" << baseClassRef.earnings() << "\n\n";
}