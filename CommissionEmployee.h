// Fig. 12.13: CommissionEmployee.h
// CommissionEmployee class derived from Employee.
#pragma once
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string> // C++ standard string class
#include "Employee.h" // Employee class definition

class CommissionEmployee : public Employee {
public:
	CommissionEmployee(const std::string&, const std::string&,
		const std::string&, Date&, double = 0.0, double = 0.0);
	virtual ~CommissionEmployee() = default; // virtual destructor

	void setCommissionRate(double); // set commission rate
	double getCommissionRate() const; // return commission rate

	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount

	// keyword virtual signals intent to override
	virtual double earnings() const override; // calculate earnings
	virtual std::string toString() const override; // string representation

private:
	double grossSales; // gross weekly sales
	double commissionRate; // commission percentage
};
#endif // !COMMISSION_H

