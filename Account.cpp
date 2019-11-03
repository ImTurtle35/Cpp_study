// 12191706 ±èÁ¤Áø
// Member-functions definition for class Account
#include "Account.h"
#include <stdexcept>

using namespace std;

Account::Account(double b) {
	if (b < 0.0) {
		throw invalid_argument("The initial balance is invalid. Set it 0");
		balance = 0.0;
	}
	else {
		balance = b;
	}
}

void Account::Credit(double b) {
	balance += b;
}

bool Account::Debit(double b) {
	if (balance < b) {
		throw invalid_argument("Debit amount exceeded account balance.");
		return false;
	}
	else {
		balance -= b;
		return true;
	}
}

double Account::getBalance() {
	return balance;
}