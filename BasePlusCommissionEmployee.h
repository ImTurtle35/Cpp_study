// Fig. 12.15: BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee class derived from CommissionEmployee.
#pragma once
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ standard string class
#include "CommissionEmployee.h" // CommissionEmployee class definition

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
	BasePlusCommissionEmployee(const std::string&, const std::string&,
		const std::string&, double = 0.0, double = 0.0, double = 0.0);
	virtual ~BasePlusCommissionEmployee() = default; // virtual destructor

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary

	// keyword virtual signals intent to override
	virtual double earnings() const override; // calcualte earnings
	virtual std::string toString() const override; // string representation

private:
	double baseSalary; // base salary per week
};
#endif // !BASEPLUS_H

