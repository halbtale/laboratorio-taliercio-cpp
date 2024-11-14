#include <iostream>
#include "rational.h"

using namespace std;

int main() {
	const Rational r1 {1, 2};
	const Rational r2 {1};
	const Rational r3 {4, 2};

	cout << "r1: " << r1;
	cout << "r2: " << r2;
	cout << "r3: " << r3;
	
	cout << "sum: " << r1 + r2 + 1 + r3;
	cout << "sub: " << r3 - r2;
	cout << "product: " << r3 * r2;
	cout << "division: " << r2 / r3;
	cout << "equality: " << (r2 / r3 == Rational {2, 4}) << "\n";
	cout << "greater than: " << (r3 > r2) << "\n";
	cout << "less than: " << (r3 < r2) << "\n";
	cout << "double: " << r1.toDouble() << "\n";
	
	
	return 0;
}