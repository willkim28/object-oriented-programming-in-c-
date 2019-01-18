// Workshop 5
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

namespace sict {
	class Fraction {
		int numer;
		int denom;

		int max(void) const;
		int min(void) const;
		void reduce();
		int gcd() const;

	public:
		Fraction();
		Fraction(int, int);
		bool isEmpty(void) const;
		void display(void) const;

		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);
	};
}

#endif