// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: ChequingAccount.h

#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H
#include "Account.h"

namespace sict {
    class ChequingAccount : public Account {
        double transFee, monthlyFee;
    
    public:
        ChequingAccount(double, double, double);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}

#endif