// Fig. 12.11: SalariedEmployee.h
// SalariedEmployee class derived from Employee.
#pragma once
#ifndef SALARIED_H
#define SALARIED_H

#include <string> // C++ standard string class
#include "Employee.h" // Employee class definition

class SalariedEmployee : public Employee {
public:
	SalariedEmployee(const std::string&, const std::string&,
		const std::string&, Date&, double = 0.0);
	virtual ~SalariedEmployee() = default; // virtual destructor

	void setMonthlySalary(double); // set monthly salary
	double getMonthlySalary() const; // return monthly salary

	// keyword virtual signals intent to override
	virtual double earnings() const override; // calculate earnings
	virtual std::string toString() const override; // string representation
	
private:
	double monthlySalary; // salary per week
};
#endif // !SALARIED_H

