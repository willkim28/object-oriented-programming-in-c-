// Workshop 6
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Contact.h

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
    const int MAX_CHAR = 20;
    const int areaLength = 3;
    const int numberLength = 7;
    const int numSize = 12;
    
    class Contact {
        char cName[MAX_CHAR+1];
        long long* cNumbers;
        int cNoOfNumbers;

    public:
        Contact();
        Contact(const char*, const long long*, const int);

        //destructor
        ~Contact();
        
        bool isEmpty() const;
        void display() const;
        bool isValid(const long long) const;
        
        //copy constructors
        Contact(const Contact&);
        Contact& operator=(const Contact&);
        
        Contact& operator+=(long long);
    };
}
#endif