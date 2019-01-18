// Workshop 8
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: ChequingAccount.cpp

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
using namespace std;

namespace sict {
    ChequingAccount::ChequingAccount(double initBal, double trans, double fee) : Account(initBal) {
        if (trans <= 0) {
            transFee = 0;
        } else {
            transFee = trans;
        }
        
        if (fee <= 0) {
            monthlyFee = 0;
        } else {
            monthlyFee = fee;
        }
    }
    
    bool ChequingAccount::credit(double cdtAmt) {
        Account::debit(transFee);
        return Account::credit(cdtAmt);
    }
    
    bool ChequingAccount::debit(double dbtAmt) {
        return Account::debit(dbtAmt + transFee);
    }
    
    void ChequingAccount::monthEnd() {
        Account::debit(monthlyFee);
    }
    
    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << endl;
        os << setprecision(2) << fixed << "Balance: $" << balance() << endl;
        os << setprecision(2) << fixed << "Per Transaction Fee: " << transFee << endl;
        os << setprecision(2) << fixed << "Monthly Fee: " << monthlyFee << endl;
    }
}