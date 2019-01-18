// Milestone 2
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Error.h

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#ifndef ERROR_H
#define ERROR_H

namespace aid {
    
    class Error {
        char* msgAddress;
        
    public:
        explicit Error(const char* errorMessage = nullptr);
        Error(const Error&) = delete;
        Error& operator=(const Error&) = delete;
        virtual ~Error();
        void clear();
        bool isClear() const;
        void message(const char*);
        const char* message() const;
        
        //Helper operator
    };
    std::ostream &operator<<(std::ostream& ostr, const Error& o);
}

#endif