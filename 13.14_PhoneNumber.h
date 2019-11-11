// 12191706 ±èÁ¤Áø
// Fig. 10.3: PhoneNumber.h
// PhoneNumber class definition
#ifndef PHONENUMBER_H
#define PHONENUMBER_Hp

#include <iostream>
#include <string>


class PhoneNumber {
	friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
	friend std::istream& operator>>(std::istream&, PhoneNumber&);
private:
	std::string areaCode; // 3-digit area code
	std::string exchange; // 3-digit exchange
	std::string line; // 4-digit line
};

#endif