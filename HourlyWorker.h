// 12191706 ±èÁ¤Áø
// represents an employee whose pay is based on 
// an hourly wage and the number of hours worked.
#pragma once
#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>

class HourlyWorker :public Employee {
public:
	HourlyWorker(const std::string&, const std::string&,
		const std::string&, double, int);
	virtual ~HourlyWorker() = default; // virtual destructor

	// keyword virtual signals intent to override
	virtual double earnings() const override; // calculate earnings
	virtual std::string toString() const override; // string representation
private:
	double wage = 500;
	int hours = 50;
};

#endif // !HOURLYWORKER_H

