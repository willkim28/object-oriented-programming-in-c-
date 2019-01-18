// Workshop 4
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Passenger.cpp

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {
    Passenger::Passenger() {
        nameT[0] = '\0';
        destT[0] = '\0';
        year = 0;
        month = 0;
        day = 0;
    }
    
    Passenger::Passenger(const char *pName, const char *pDest) {
        if (pName == nullptr || pDest == nullptr) {
            *this = Passenger();
            //if condition is met, set variables to safe empty state
        } else {
            strncpy(nameT, pName, LIMIT-1);
            strncpy(destT, pDest, LIMIT-1);
            //else copy the strings into instance var (-1 to properly size)
            year = 2018;
            month = 10;
            day = 1;
            //and set date to 2018/10/01
        }
    }
    
    Passenger::Passenger(const char *pName, const char *pDest, int pYear, int pMonth, int pDay) {
        bool yValid = pYear >= 2018 && pYear <= 2020;
        bool mValid = pMonth >= 1 && pMonth <= 12;
        bool dValid = pDay >= 1 && pDay <= 31;
        //set bool to simplify conditional phrase
        
        if (pName == nullptr || pDest == nullptr || !yValid || !mValid || !dValid) {
            *this = Passenger();
            //if condition is met, set to safe empty state
        } else {
            strncpy(nameT, pName, LIMIT-1);
            strncpy(destT, pDest, LIMIT-1);
            year = pYear;
            month = pMonth;
            day = pDay;
            //else copy the data
        }
    }
    
    bool Passenger::isEmpty() const {
        if (strlen(nameT) > 0 && strlen(destT) > 0) {
            return false;
            //if length of both are more than 0, it's not empty
        } else {
            return true;
            //if either's empty
        }
    }
    
    void Passenger::display() const {
        if (!isEmpty()) {
            if (day >= 10) {
            cout << nameT << " - " << destT << " on " << year << "/" << month << "/" << day << endl;
            } else {
                cout << nameT << " - " << destT << " on " << year << "/" << month << "/0" << day << endl;
                //if day is one digit, manually add a 0 in front for YYYY/MM/DD format opposed to YYYY/MM/D
                //ugly formatting, but it works
                //proper implementation would use strftime?
            }
        } else {
            cout << "No passenger!" << endl;
        }
    }
    
    const char* Passenger::name() const {
        return nameT;
        //will return proper address if filled, else will return the address of safe empty state var
    }
    
    bool Passenger::canTravelWith(const Passenger& passenger) const {
        bool yCheck = (*this).year == passenger.year;
        bool mCheck = (*this).month == passenger.month;
        bool dCheck = (*this).day == passenger.day;
        //set flags again for simplicity
        
        if (yCheck && mCheck && dCheck) {
            return true;
        }
        return false;
    }
}