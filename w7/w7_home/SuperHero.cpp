// Workshop 7
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: SuperHero.cpp

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;
using namespace sict;

namespace sict {
    SuperHero::SuperHero() : Hero() {
        shABonus = 0;
        shDBonus = 0;
    }
    
    SuperHero::SuperHero(const char* name, int health, int attack, int shAttack, int shDefend) : Hero(name, health, attack) {
        shABonus = shAttack;
        shDBonus = shDefend;
    }
    
    int SuperHero::attackStrength() const {
        if (!(Hero::attackStrength() == 0)) {
            return Hero::attackStrength() + shABonus;
        }
            return 0;
    }
    
    int SuperHero::defend() const {
        if (!(shDBonus == 0)) {
            return shDBonus;
        } else {
            return 0;
        }
    }
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
        cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
        SuperHero left = first, right = second;
        const SuperHero *winner = nullptr;
        
        int noOfRounds = 0;
        
        while (left.isAlive() && right.isAlive() && noOfRounds < MAX_ROUNDS) {
            left -= right.attackStrength() - left.defend();
            right -= left.attackStrength() - right.defend();
            ++noOfRounds;
        }
        
        if (!left.isAlive()) {
            winner = &second;
        }
        if (!right.isAlive() || (!left.isAlive() && !right.isAlive())) {
            winner = &first;
        }
        cout << *winner << " in " << noOfRounds << " rounds." << endl;
        return *winner;
    }
}