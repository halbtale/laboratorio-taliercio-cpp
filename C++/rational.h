#ifndef RATIONAL
#define RATIONAL

#include <iostream>
using namespace std;

class Rational {
public:
	Rational() = default;

	explicit Rational(const int n) : numerator{n}, denominator{1} {};

	Rational(const int num, const int den) : numerator{num}, denominator{den} {};
	
	int getNumerator() const {
		return numerator;
	}
	
	int getDenominator() const {
		return denominator;
	}
	
	double toDouble() const {
		return static_cast<double>(numerator) / static_cast<double>(denominator);
	}
	
	Rational& operator=(const Rational& rational);
	
private:
	int numerator {0};
	int denominator {1};
};

ostream& operator<<(ostream& stream, const Rational& rational);
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator+(int n1, const Rational& r2);
Rational operator+(const Rational& r1, int n2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator<(const Rational& r1, const Rational& r2);

#endif
