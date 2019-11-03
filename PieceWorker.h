// 12191706 ±èÁ¤Áø
// represents an employee whose pay is based on 
// the number of pieces of mechandise produced.
#pragma once
#ifndef PIECEWORKER_H
#define PIECEWORKER_H
#include <string>
#include "Employee.h"

class PieceWorker :public Employee {
public:
	PieceWorker(const std::string&, const std::string&,
		const std::string&, double, int);
	virtual ~PieceWorker() = default; // virtual destructor

	// keyword virtual signals intent to override
	virtual double earnings() const override; // calculate earnings
	virtual std::string toString() const override; // string representation
private:
	double wage;
	int pieces;
};

#endif // !PIECEWORKER_H

