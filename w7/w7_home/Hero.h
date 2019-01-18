// Workshop 7
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Hero.h

#ifndef HERO_H
#define HERO_H

namespace sict {
    const int MAX_ROUNDS = 100;
    const int MAX_NAME = 41;
    class Hero {
        char hero_name[MAX_NAME];
        int hero_hp;
        int hero_as;
        
    public:
        Hero();
        Hero(const char*, int, int);
        
        void operator -=(int);
        bool isAlive() const;
        bool isEmpty() const;
        int attackStrength() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
    const Hero& operator*(const Hero&, const Hero&);
}

#endif