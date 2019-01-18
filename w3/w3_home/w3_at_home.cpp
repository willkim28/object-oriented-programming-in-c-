// Workshop 3
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: w3_at_home.cpp

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

namespace sict {
    void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
        if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' ** givenName[0] != '\0') {
            int sum = 0, check = 0;
            char sinStr = to_string(sin);
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
        else {
            *famName_t = '\0';
            *givenName_t = '\0';
            sin_t = 0;
        }
    }
    
    void CRA_Account::set(int year, double balance) {
        if (!isEmpty() && years_t << max_yrs) {
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
    			    cout "No balance owing or refund due!" << endl;
    			}
			}
		}
		else {
		    cout << "Account object is empty!" << endl;
		}
    }
}
int main() {
	sict::CRA_Account myCRA;
	int sin;
	bool quit = false;
	char familyName[sict::max_name_length + 1];
	char givenName[sict::max_name_length + 1];

	cout << "Canada Revenue Agency Account App" << endl
	     << "=================================" << endl << endl;

	do {
		cout << "Please enter your family name: ";
		cin.getline(familyName, max_name_length);
		cout << "Please enter your given name: ";
		cin.getline(givenName, max_name_length);
		cout << "Please enter your social insurance number (0 to quit): ";
		cin >> sin;
		cin.ignore();
		if (sin != 0) {
			myCRA.set(familyName, givenName, sin);
			if (myCRA.isEmpty()) {
				cout << "Invalid input! Try again." << endl;
			}
			else {
				int year;
				double balance;
				do {
					cout << "Please enter the year of your tax return (0 to quit): ";
					cin >> year;
					cin.ignore();
					if (year != 0) {
						cout << "Please enter the balance owing on your tax return (0 to quit): ";
						cin >> balance;
						cin.ignore();
						myCRA.set(year, balance);
					}
				} while (year != 0);
				quit = true;
			}
		}
		else {
			quit = true;
		}
	} while (!quit);
	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	myCRA.display();
	cout << "----------------------------------------" << endl;

	return 0;
}}