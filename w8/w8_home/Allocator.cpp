// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Allocator.cpp

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    const double interest = 0.05;
    const double transFee = 0.50;
    const double monthlyFee = 2.00;
    
    iAccount* CreateAccount (const char* accType, double initBal) {
        iAccount *p = nullptr;
        if (accType[0] == 'S') {
            p = new SavingsAccount(initBal, interest);
        } else if (accType[0] == 'C') {
            p = new ChequingAccount(initBal, transFee, monthlyFee);
        }
        return p;
    }
}