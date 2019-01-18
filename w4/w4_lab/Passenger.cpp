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
        name[0] = '\0';
        dest[0] = '\0';
    }
    
    Passenger::Passenger(const char *pName, const char *pDest) {
        if (pName == nullptr || pDest == nullptr) {
            *this = Passenger();
        } else {
            strncpy(name, pName, LIMIT-1);
            strncpy(dest, pDest, LIMIT-1);
        }
    }
    
    bool Passenger::isEmpty() const {
        if (strlen(name) > 0 && strlen(dest) > 0) {
            return false;
        } else {
            return true;
        }
    }
    
    void Passenger::display() const {
        if (!isEmpty()) {
            cout << name << " - " << dest << endl;
        } else {
            cout << "No passenger!" << endl;
        }
    }
}