// 12191706_±èÁ¤Áø
// derived from class Account
#pragma once
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
	SavingsAccount(double, double);

	double CalculateInterest();

private:
	double interestRate;
};
#endif // !SAVINGACCOUNT_H