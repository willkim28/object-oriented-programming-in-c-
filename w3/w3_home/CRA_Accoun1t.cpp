// Workshop 3
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
      //declare variables and 'initialize' them first do avoid mishaps
        *famName_t = '\0';
        *givenName_t = '\0';
        sin_t = 0;
        for (int i = 0; i < max_yrs; i++) {
          balance_t[i] = 0;
        }
        years_t = 0;
        
        if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
            int sum = 0, check = 0;
            string sinStr = to_string(sin);
            for (int i = 1; i <= 7; i += 2) {
                if (2 * (sinStr[i]-'0') >= 10) {
                    sum += 2 * (sinStr[i]-'0') - 9;
                }
                else {
                    sum += 2 * (sinStr[i]-'0');
                }
            }
            for (int i = 0; i <= 8; i += 2) {
                sum += sinStr[i]-'0';
            }
            
            check = sum % 10;
            
            if (check == 0) {
                strcpy(famName_t, familyName);
                strcpy(givenName_t, givenName);
                sin_t = sin;        
            }
            
        }
    }
    
    void CRA_Account::set(int year, double balance) {
        if (!isEmpty() && years_t < max_yrs) {
            year_t[years_t] = year;
            balance_t[years_t] = balance;
            years_t++;
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
			      for (int i = 0; i < years_t; i++) {
			        cout << "Year (" << year_t[i] << ") ";
              if (balance_t[i] > 2) {
                  cout <<"balance owing: " << balance_t[i] << endl;
              }
              else if (balance_t[i] < -2) {
                  cout << "refund due: " << -balance_t[i] << endl;
              }
              else {
                  cout << "No balance owing or refund due!" << endl;
    		      }
			      }
		      }
        else {
            cout << "Account object is empty!" << endl;
        }
    }
}