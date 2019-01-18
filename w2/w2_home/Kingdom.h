// Workshop 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Kingdom.h

#ifndef sict_Kingdom_h_
#define sict_Kingdom_h_

namespace sict {
    #define MAX_NAME 32
    struct Kingdom {
        char m_name[MAX_NAME];
        int m_population;
    };
    void display(const Kingdom&);
    void display(const Kingdom kingdom[], int count);
}

#endif