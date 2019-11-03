// Fig. 12.12: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "SalariedEmployee.h" // Salaried Employee class definition
using namespace std;

// constructor 
SalariedEmployee::SalariedEmployee(const string& first,
	const string& last, const string& ssn, double salary)
	: Employee(first, last, ssn) {
	setWeeklySalary(salary);
}

// set salary
void SalariedEmployee::setWeeklySalary(double salary) {
	if (salary < 0.0) {
		throw invalid_argument("Weekly salaray must be >= 0.0");
	}

	weeklySalary = salary;
}

// return salary
double SalariedEmployee::getWeeklySalary() const { return weeklySalary; }

// calculate earnings;
// override pure virtual earnings in Employee
double SalariedEmployee::earnings() const {	return getWeeklySalary();}

// return a string representation of SalariedEmployee's information
string SalariedEmployee::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "salaried employee: "
		<< Employee::toString() // reuse abstract base-class function
		<< "\nweekly salary: " << getWeeklySalary();
	return output.str();
}