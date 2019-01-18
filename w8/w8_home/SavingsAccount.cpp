// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: SavingsAccount.cpp

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;

namespace sict {
    SavingsAccount::SavingsAccount(double initBal, double iRate) : Account(initBal) {
        if (iRate <= 0) {
            interest = 0;
        } else {
            interest = iRate;
        }
    }
    
    void SavingsAccount::monthEnd() {
        double monthInterest = balance() * interest;
        credit(monthInterest);
    }
    
    void SavingsAccount::display(std::ostream& os) const {
        os << "Account type: Savings" << endl;
        os << setprecision(2) << fixed << "Balance: $" << balance() << endl;
        os << setprecision(2) << fixed << "Interest Rate (%): " << interest * 100 << endl;
    }
}