// Workshop 5
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

// TODO: header file guard

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numer;
		int denom;

		// TODO: declare private member functions
		int max(void) const;
		int min(void) const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty(void) const;
		void display(void) const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		
	};
}

#endif