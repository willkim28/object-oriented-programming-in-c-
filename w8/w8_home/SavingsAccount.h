// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

namespace sict {
    class SavingsAccount : public Account {
        double interest;

    public:
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}

#endif