// 12191706 ±èÁ¤Áø
// Chapter.13_ 13.16
// Complex class definition
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>

class Complex {
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
private:
	int real;
	int imaginary;
};
#endif // !COMPLEX_H

