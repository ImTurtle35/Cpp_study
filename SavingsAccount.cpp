// 12191706 ������
// derived from class SavingsAccount
#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(double b, double ir)
	: Account(b), interestRate(ir) {}

double SavingsAccount::CalculateInterest() {
	return (interestRate * balance);
}