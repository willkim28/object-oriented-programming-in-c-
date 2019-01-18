// Workshop 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Kingdom.cpp


#include <iostream>
#include "Kingdom.h"
using namespace sict;
using namespace std;

namespace sict {
    //displays the kingdom w its population
    void display(const Kingdom& kingdom) {
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }
    //displays all kingdoms w each population
    void display(const Kingdom kingdom[], int count) {
        int total = 0;
        cout << "------------------------------" << endl;
        cout << "Kingdoms of SICT" << endl;
        cout << "------------------------------" << endl;
        //loops through each kingdom and lists each population + adds each pop to a total variable
        for (int i = 0; i < count; i++) {
            cout << i+1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
            total += kingdom[i].m_population;
        }
        //displays total population of all kingdoms
        cout << "------------------------------" << endl;
        cout << "Total population of SICT: " << total << endl;
        cout << "------------------------------" << endl;
    }
}
