// Fig. 12. 9: Employee.h
// Employee abstract base class.
#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // C++ standard string class
#include "Date.h" // Date class definition

class Employee {
public:
	Employee(const std::string&, const std::string&, const std::string&, Date&);
	virtual ~Employee() = default; // compiler generates virtual destructor

	void setFirstName(const std::string&); // set first name
	std::string getFirstName() const; // return first name

	void setLastName(const std::string&); // set last name
	std::string getLastName() const; // return last name

	void setSocialSecurityNumber(const std::string&); // set SSN
	std::string getSocialSecurityNumber() const; // return SSN

	// pure Virtual function makes Employee an abstract base class
	virtual double earnings() const = 0; // pure virtual
	virtual std::string toString() const; // virtual

protected:
	Date& birthDate;

private:
	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
};

#endif // EMPLOYEE_H

