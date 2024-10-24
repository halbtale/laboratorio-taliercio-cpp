#include <iostream>
using namespace std;

#ifndef RATIONAL
#define RATIONAL

class Rational {
public:
	Rational() = default;
	Rational(int n) : numerator{n}, denominator{1} {};
	Rational(int num, int den) : numerator{num}, denominator{den} {};
	
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
