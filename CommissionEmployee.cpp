// Fig. 12.14: CommissionEmployee.cpp
// CommissionEmployee class member-function definitions.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string& first,
	const string& last, const string& ssn, Date& birthdate, double sales, double rate)
	: Employee(first, last, ssn, birthdate) {
	setGrossSales(sales);
	setCommissionRate(rate);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales) {
	if (sales < 0.0) {
		throw invalid_argument("Gross sales must be >= 0.0");
	}

	grossSales = sales;
}

// return gross sales amount
double CommissionEmployee::getGrossSales() const { return grossSales; }

// set commission rate
void CommissionEmployee::setCommissionRate(double rate) {
	if (rate <= 0.0 || rate > 1.0) {
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
	}

	commissionRate = rate;
}

// return commission rate
double CommissionEmployee::getCommissionRate() const {
	return commissionRate;
}

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const {
	if (birthDate.getMonth() == 11) {
		return getCommissionRate() * getGrossSales() + 100;
	}
	else
		return getCommissionRate() * getGrossSales();
}

// return a string representation of CommissionEmployee's information
string CommissionEmployee::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "commission employee: " << Employee::toString()
		<< "\ngross sales: " << getGrossSales()
		<< "; commission rate: " << getCommissionRate();
	return output.str();
}