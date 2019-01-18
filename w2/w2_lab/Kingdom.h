// Workshop 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Kingdom.h

// TODO: header safeguards

#ifndef sict_Kingdom_h_
#define sict_Kingdom_h_

// TODO: sict namespace
namespace sict {
    #define MAX_NAME 32
    struct Kingdom {
        char m_name[MAX_NAME];
        int m_population;
    };
    void display(const Kingdom&);
}
// TODO: declare the function display(...),
//         also in the sict namespace

#endif