// 12191706 ±èÁ¤Áø
// member-fucntions definitions for class PieceWorker
#include <iomanip>
#include <sstream>
#include "PieceWorker.h"

using namespace std;

PieceWorker::PieceWorker(const string& first,
	const string& last, const string& ssn, double w, int p)
	: Employee(first, last, ssn), wage(w), pieces(p) {}

double PieceWorker::earnings() const{
	return wage * pieces;
}

// return a string representation of PieceWorker's information
string PieceWorker::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << typeid(*this).name() << ": "
		<< Employee::toString(); // reuse abstract base-class function
	return output.str();
}