// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: iAccount.h

#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>

namespace sict {
    class iAccount {
        
    public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream&) const = 0;

        virtual ~iAccount() {}
    };
    iAccount* CreateAccount(const char*, double);
}

#endif