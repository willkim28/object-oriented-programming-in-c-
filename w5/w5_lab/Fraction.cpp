// Workshop 5
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Fraction.cpp

#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
using namespace sict;

namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
	    numer = 0;
	    denom = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerIn, int denomIn) {
	    if (!(numerIn >= 0 && denomIn > 0)) {
	        *this = Fraction();
	    } else {
	        numer = numerIn;
	        denom = denomIn;
	        reduce();
	    }
	}

	// TODO: implement the max query
	int Fraction::max() const {
	    return (numer <= denom) ? denom : numer;
	}

    // TODO: implement the min query
	int Fraction::min() const {
	    return (numer <= denom) ? numer : denom;
	}
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce() {
        int reduceGcd = gcd();
        
        numer /= reduceGcd;
        denom /= reduceGcd;
    }

    // TODO: implement the display query
    void Fraction::display() const {
        if(isEmpty()) {
            cout << "no fraction stored";
        } else if (denom == 1) {
            cout << numer;
        } else {
            cout << numer << "/" << denom;
        }
    }

    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
        return (numer == 0 && denom == 0);
    }

// TODO: implement the + operator
    Fraction Fraction::operator+(const Fraction& rhs) const {
        Fraction temp(numer * rhs.denom + denom * rhs.numer, denom * rhs.denom);
        return temp;
    }

}