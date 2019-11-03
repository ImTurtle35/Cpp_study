// 12191706_±èÁ¤Áø
// Account abstract base class.
#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
	Account(double);
    virtual void Credit(double);
	virtual bool Debit(double);

	double getBalance();

protected:
	double balance;
};

#endif // !ACCOUNT_H

