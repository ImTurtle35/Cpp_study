// 12191706 ±èÁ¤Áø
// Member-functions definition for class CheckingAccount
#include "CheckingAccount.h"
#include <stdexcept>

using namespace std;

CheckingAccount::CheckingAccount(double b, double fpt)
    : Account(b) , feePerTransaction(fpt){}

void CheckingAccount::Credit(double b) {
	Account::Credit(b);
	balance += feePerTransaction;
}

bool CheckingAccount::Debit(double b) {
	if (Account::Debit(b) == true) {
		balance -= feePerTransaction;
		return true;
	}
}