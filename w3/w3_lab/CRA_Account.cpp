// Workshop 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: CRA_Account.cpp

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace sict;
using namespace std;

namespace sict {
    void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
        if (sin >= min_sin && sin <= max_sin) {
            strcpy(famName_t, familyName);
            strcpy(givenName_t, givenName);
            sin_t = sin;
        }
        else {
            *famName_t = '\0';
            *givenName_t = '\0';
            sin_t = 0;
        }
    }

    bool CRA_Account::isEmpty() const {
        if (sin_t == 0) {
            return true;
        }
        else {
            return false;
        }
    }


    
    void CRA_Account::display() const {
        if (!isEmpty()) {
            cout << "Family Name: " << famName_t << endl;
			cout << "Given Name : " << givenName_t << endl;
			cout << "CRA Account: " << sin_t << endl;
		}
		else {
		    cout << "Account object is empty!" << endl;
		}
    }
}