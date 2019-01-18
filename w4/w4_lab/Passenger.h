// Workshop 4
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Passenger.h

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define LIMIT 19

namespace sict {
    class Passenger {
        private:
            char name[LIMIT];
            char dest[LIMIT];
        public:
                Passenger();
                Passenger(const char *pName, const char *pDest);
                bool isEmpty() const;
                void display() const;
    };
    
}
#endif