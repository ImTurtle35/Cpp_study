// 12191706 ±èÁ¤Áø
// member-fucntions definitions for class HourlyWorker
#include <iomanip>
#include <sstream>
#include "HourlyWorker.h"

using namespace std;

HourlyWorker::HourlyWorker(const string& first,
	const string& last, const string& ssn, double w, int h)
	: Employee(first, last, ssn), wage(w), hours(h) {}

double HourlyWorker::earnings() const {
	if (hours > 40) {
		return ((hours - 40) * 1.5 + 40) * wage;
	}
	else
		return hours * wage;
}

// return a string representation of HourlyWorker's information
string HourlyWorker::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << typeid(*this).name() << ": "
		<< Employee::toString(); // reuse abstract base-class function
	return output.str();
}