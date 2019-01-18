// Milestone 5
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Perishable.h

#ifndef PERISHABLE_H
#define PERISHABLE_H

#include <iostream>
#include "Good.h"
#include "Date.h"

namespace aid {
    class Perishable : public Good {
        Date expDate;
    
    public:
        Perishable();
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        const Date& expiry() const;
    };
}

#endif