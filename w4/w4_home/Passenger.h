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
            char nameT[LIMIT];
            char destT[LIMIT];
            int year, month, day;
        public:
            Passenger();
            Passenger(const char *, const char *);
            Passenger(const char *, const char *, int, int, int);
            bool isEmpty() const;
            void display() const;
            const char* name() const;
            bool canTravelWith(const Passenger&) const;
    };
    
}
#endif