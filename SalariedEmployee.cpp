// Fig. 12.12: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "SalariedEmployee.h" // Salaried Employee class definition
using namespace std;

// constructor 
SalariedEmployee::SalariedEmployee(const string& first,
	const string& last, const string& ssn, Date& birthdate, double salary)
	: Employee(first, last, ssn, birthdate) {
	setMonthlySalary(salary);
}

// set salary
void SalariedEmployee::setMonthlySalary(double salary) {
	if (salary < 0.0) {
		throw invalid_argument("Weekly salaray must be >= 0.0");
	}

	monthlySalary = salary;
}

// return salary
double SalariedEmployee::getMonthlySalary() const { return monthlySalary; }

// calculate earnings;
// override pure virtual earnings in Employee
double SalariedEmployee::earnings() const { 
	if (birthDate.getMonth() == 11) {
		return getMonthlySalary() + 100;
	}
	else {
		return getMonthlySalary();
	}
}

// return a string representation of SalariedEmployee's information
string SalariedEmployee::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "salaried employee: "
		<< Employee::toString() // reuse abstract base-class function
		<< "\nmonthly salary: " << getMonthlySalary();
	return output.str();
}