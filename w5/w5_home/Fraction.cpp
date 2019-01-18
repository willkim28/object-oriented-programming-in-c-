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

	Fraction::Fraction(int numerIn, int denomIn) {
	    //If numerator is negative valued OR denominator is NOT positive valued
	    if (!(numerIn >= 0 && denomIn > 0)) {
	        //set to safe empty state
	        *this = Fraction();
	    //If numer is NOT negative valued AND denom is positive valued
	    } else {
	        //store data and reduce()
	        numer = numerIn;
	        denom = denomIn;
	        reduce();
	    }
	}

    //return whichever is higher
	int Fraction::max() const {
	    return (numer <= denom) ? denom : numer;
	}

    //return whichever is lower
	int Fraction::min() const {
	    return (numer <= denom) ? numer : denom;
	}

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

    //reduce numer and denom w gcd()
    void Fraction::reduce() {
        int reduceGcd = gcd();
        
        numer /= reduceGcd;
        denom /= reduceGcd;
    }

    void Fraction::display() const {
        if(isEmpty()) {
            cout << "no fraction stored";
        } else if (denom == 1) {
            cout << numer;
        } else {
            cout << numer << "/" << denom;
        }
    }

    //check if in safe empty state (numer AND denom)
    bool Fraction::isEmpty() const {
        return (numer == 0 && denom == 0);
    }

    Fraction Fraction::operator+(const Fraction& rhs) const {
      Fraction temp;
        //check empty state of both operands
        if(!(isEmpty() && rhs.isEmpty())) {
            //use temp function to operate
            Fraction temp(numer * rhs.denom + denom * rhs.numer, denom * rhs.denom);
            temp.reduce();
            //then return value
            return temp;
        }
        //MISC1 not needed, 'required' for the IDE I'm working with (control reaches end of non-void function)
        return temp;
    }
    
    Fraction Fraction::operator*(const Fraction& rhs) const {
      Fraction temp;
        if(!(isEmpty() && rhs.isEmpty())) {
            Fraction temp(numer * rhs.numer, denom * rhs.denom);
            temp.reduce();
            return temp;
        }
        //MISC1
        return temp;
    }

    //declared as bool since it returns bool value
    bool Fraction::operator==(const Fraction& rhs) const {
        //checks isEmpty state, and whether values match
        return ((!isEmpty()) && numer == rhs.numer && denom == rhs.denom);
    }
    
    //declared as bool since it returns bool value
    bool Fraction::operator!=(const Fraction& rhs) const {
        //checks isEmpty state, and whether values match
        return (!((isEmpty()) && numer == rhs.numer && denom == rhs.denom));
    }
    
    Fraction Fraction::operator+=(const Fraction& rhs) {
        //if not empty, operate
        if(!isEmpty()) {
            *this = *this + rhs;
            reduce();
        //else store in safe empty state?
        //maybe I'm misunderstanding the instruction, but shouldn't this be made to ADD instead of STORING a safe empty state to current object?
        } else {
          *this = Fraction();
        }
        return *this;
    }
}