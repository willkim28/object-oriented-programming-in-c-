// Workshop 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Kingdom.cpp


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict {
    void display(const Kingdom& kingdom) {
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }
}