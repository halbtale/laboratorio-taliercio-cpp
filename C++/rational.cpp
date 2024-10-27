#include "rational.h"

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.getNumerator() << "/" << rational.getDenominator() << "\n";
	return stream;
}

Rational& Rational::operator=(const Rational& rational) = default;

Rational operator+(const Rational& r1, const Rational& r2) {
	const int sumDenominator = r1.getDenominator() * r2.getDenominator();
	const int sumNumerator = r1.getNumerator() * r2.getDenominator() + r2.getNumerator() * r1.getDenominator();
	
	return Rational {sumNumerator, sumDenominator};
}

Rational operator+(const int n1, const Rational& r2) {
	return Rational {n1} + r2;
}

Rational operator+(const Rational& r1, const int n2) {
	return r1 + Rational {n2};
}

Rational operator-(const Rational& r1, const Rational& r2) {
	const int subDenominator = r1.getDenominator() * r2.getDenominator();
	const int subNumerator = r1.getNumerator() * r2.getDenominator() - r2.getNumerator() * r1.getDenominator();
	
	return Rational {subNumerator, subDenominator};
}

Rational operator*(const Rational& r1, const Rational& r2) {
	const int productDenominator = r1.getDenominator() * r2.getDenominator();
	const int productNumerator = r1.getNumerator() * r2.getNumerator();
	
	return Rational {productNumerator, productDenominator};
}

Rational operator/(const Rational& r1, const Rational& r2) {
	const int divisionDenominator = r1.getDenominator() * r2.getNumerator();
	const int divisionNumerator = r1.getNumerator() * r2.getDenominator();
	
	return Rational {divisionNumerator, divisionDenominator};
}

bool operator==(const Rational& r1, const Rational& r2) {
	return r1.getNumerator() == r2.getNumerator() && r1.getDenominator() == r2.getDenominator();
}

bool operator>(const Rational& r1, const Rational& r2) {
	return r1.getNumerator() * r2.getDenominator() > r2.getNumerator() * r1.getDenominator();
}

bool operator<(const Rational& r1, const Rational& r2) {
	return r1.getNumerator() * r2.getDenominator() < r2.getNumerator() * r1.getDenominator();
}

