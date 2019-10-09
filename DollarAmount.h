// 12191706 ±èÁ¤Áø
// Chapter 10 - 10.12
// DolloarAmount class stores dolloar amount as a whole numbers of pennies
#pragma once
#include <string>
#include <cmath>

class DollarAmount {
public:
	// initialize amount from an calculate by int64_t dollars and cents
	DollarAmount(int64_t dollars, int64_t cents)  {
		amount = (dollars * 100) + cents;
	};

	// addition operator; amount + amount
    DollarAmount operator+(const DollarAmount& right) const{
		DollarAmount temp(amount/100, amount%100);
		temp.amount = amount + right.amount;

		return temp;
	}
	// amount + int
	DollarAmount operator+(int right) const {
		return ((*this) + (DollarAmount(right / 100, right % 100)));
	}

	// subtraction operator; amount - amount
	DollarAmount operator-(const DollarAmount& right) const {
		DollarAmount temp(amount / 100, amount % 100);
		temp.amount = amount - right.amount;

		return temp;
	}
	// amount - int
	DollarAmount operator-(int right) const {
		return ((*this) - (DollarAmount(right / 100, right % 100)));
	}

	// multiplication operator; amount * amount
	DollarAmount operator*(const DollarAmount& right) const {
		DollarAmount temp(amount / 100, amount % 100);
		temp.amount = (amount) * (right.amount);

		return temp;
	}
	// amount * int
	DollarAmount operator*(int right) const {
		return ((*this) * (DollarAmount(right / 100, right % 100)));
	}

	// division operator; amount / amount
	DollarAmount operator/(const DollarAmount& right) const {
		DollarAmount temp(amount / 100, amount % 100);
		temp.amount = (amount) / (right.amount);

		return temp;
	}
	// amount / int
	DollarAmount operator/(int right) const {
		return ((*this) / (DollarAmount(right / 100, right % 100)));
	}

	// divide right's amount from this object's amount
	void divide(int num) {
		// can access private data of other objects of the same class
		amount = (amount + num/2) / num; // use rounding techniques to divide amount
	}

	// uses integer arithmetic to calculate interest amount,
	// then calls add with the interest amount
	void addInterest(int rate, int divisor) {
		// create DollarAmount representing the interest
		// use banker's rounding
		int save_amount = (amount * rate)/divisor;
		if (save_amount % 1 < 0.5)
			save_amount += 0;
		else if (save_amount % 1 > 0.5)
			save_amount += 1;
		else
			save_amount += ((save_amount % 2) == 1 ? 1 : 0);
		DollarAmount interest {
			save_amount/100, save_amount%100
		};

	     *this = *this + interest; // add interest to this object's amount
	}


	// return a string representation of a DollarAmount object
	std::string toString() const {
		std::string dollars{ std::to_string(amount / 100) };
		std::string cents{ std::to_string(std::abs(amount % 100)) };
		return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
	}

private:
	int64_t amount{ 0 }; // dollar amount in pennies
};
