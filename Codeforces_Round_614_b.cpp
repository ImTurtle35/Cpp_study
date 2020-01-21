#include <iostream>

using namespace std;

const double t = 1;
double n, answer;

int main() {
	cin >> n;
	for (double s{ 1 }; s <= n; s++) {
		answer += (t/s);
	}
	cout.precision(12);
	cout << fixed;
	cout << answer << endl;
} 