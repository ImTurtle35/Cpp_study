#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

double withdraw;
double deposit;

int main() {
	// create class objects
	CheckingAccount checkingaccount{ 2000, 100 };
	SavingsAccount savingsaccount{ 1500, 0.01 };

	// create and initialize vector of three base-class pointers
	vector<Account*> accounts{ &savingsaccount, &checkingaccount };

	for (Account* accountPtr : accounts) {
		cout << fixed << setprecision(2);
		cout << "Account has been created.\n"
			<< "\nInput an amount of money to withdraw : ";
		cin >> withdraw;
		accountPtr->Debit(withdraw);
		cout << "\nInput an amount of money to deposit : ";
		cin >> deposit;
		accountPtr->Credit(deposit);
		SavingsAccount* derivedPtr = dynamic_cast<SavingsAccount*>(accountPtr);
		if (derivedPtr != nullptr) {
			cout << "\nThis account is savingsaccount.";
			accountPtr->Credit(derivedPtr->CalculateInterest());
		}
		else {
			cout << "\nThis account is checkingaccount.";
		}

		cout << "\n\nThis account's current balance is : " << accountPtr->getBalance() << "\n\n";
	}
}