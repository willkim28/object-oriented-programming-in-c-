// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "iAccount.h"

namespace sict {
    class Account : public iAccount{
        double accBal;
    public:
        Account(double);
        bool credit(double);
        bool debit(double);
        
    protected:
        double balance() const;
    };
	iAccount* CreateAccount(const char*, double);
}

#endif