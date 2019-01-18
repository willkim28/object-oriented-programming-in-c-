// Workshop 7
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: SuperHero.h

#ifndef SUPERHERO_H
#define SUPERHERO_H
#include "Hero.h"

namespace sict {
    class SuperHero: public Hero {
        int shABonus;
        int shDBonus;
    
    public:
        SuperHero();
        SuperHero(const char*, int, int, int, int);
        
        int attackStrength() const;
        int defend() const;
    };
        const SuperHero& operator*(const SuperHero&, const SuperHero&);
}

#endif