// Milestone 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Error.cpp

#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;

namespace aid {
    Error::Error(const char* errorMessage) {
        if (errorMessage == nullptr) {
            msgAddress = nullptr;
        } else {
            msgAddress = new char[strlen(errorMessage) + 1];
            strncpy(msgAddress, errorMessage, strlen(errorMessage) + 1);
            msgAddress[strlen(errorMessage)] = '\0';
        }
    }
    
    Error::~Error() {
        delete[] msgAddress;
        msgAddress = nullptr;
    }
    
    void Error::clear() {
        delete[] this->msgAddress;
        this->msgAddress = nullptr;
    }
    
    bool Error::isClear() const {
        return (this->msgAddress == nullptr || this->msgAddress[0] == '\0');
    }
    
    void Error::message(const char* str) {
        delete[] msgAddress;
        if ((str != nullptr)) {
            msgAddress = new char[strlen(str) + 1];
            strncpy(msgAddress, str, strlen(str) + 1);
            msgAddress[strlen(str)] = '\0';
        } else {
            msgAddress = nullptr;
        }
    }
    
    const char* Error::message() const {
        return msgAddress;
    }
    
    std::ostream& operator<<(std::ostream& ostr, const Error& o) {
        if (!o.isClear()) {
            ostr << o.message();
        }
        return ostr;
    }
}