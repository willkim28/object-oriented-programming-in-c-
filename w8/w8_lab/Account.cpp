// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Account.cpp

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {
    Account::Account(double initBal) {
        if (initBal <= 0) {
            accBal = 0;
        } else {
            accBal = initBal;
        }
    }
    
    bool Account::credit(double cdtAmt) {
        if (cdtAmt > 0) {
            accBal += cdtAmt;
            return true;
        } else { 
            return false;
        }
    }
    
    bool Account::debit(double dbtAmt) {
        if (dbtAmt > 0) {
            accBal -= dbtAmt;
            return true;
        } else {
            return false;
        }
    }
    
    double Account::balance() const {
        return accBal;
    }
}