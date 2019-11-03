// 12191706_±èÁ¤Áø
// derived from class Account
#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount : public Account {
public:
	CheckingAccount(double, double);

	virtual void Credit(double);
	virtual bool Debit(double);

private:
	double feePerTransaction;
};

#endif // !CHECKINGACCOUNT_H
