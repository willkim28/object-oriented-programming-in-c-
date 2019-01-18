// Workshop 7
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Hero.cpp

#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {
    Hero::Hero() {
        hero_name[0] = '\0';
        hero_hp = 0;
        hero_as = 0;
    }
    
    Hero::Hero(const char* name, int health, int attack) {
        strncpy(hero_name, name, MAX_NAME);
        hero_name[MAX_NAME-1] = '\0';
        
        hero_hp = health;
        hero_as = attack;
    }
    
    void Hero::operator-=(int attack) {
        if (attack > 0) {
            hero_hp -= attack;
            if (hero_hp < 0) {
                hero_hp = 0;
            }
        }
    }
    
    bool Hero::isAlive() const {
        return (hero_hp > 0);
    }
    
    bool Hero::isEmpty() const {
        return (hero_name[0] == '\0' && hero_hp == 0 && hero_as == 0);
    }
    
    int Hero::attackStrength() const {
        if (!isEmpty()) {
            return hero_as;
        } else {
            return 0;
        }
    }
    
    std::ostream& operator<<(ostream& os, const Hero& hero) {
        if (hero.hero_name[0] == '\0') {
            os << "No hero";
        } else {
            os << hero.hero_name;
        }
        return os;
    }
    
    const Hero& operator*(const Hero& first, const Hero& second) {

      cout << "Ancient Battle! " << first << " vs " << second;

        Hero left = first, right = second;
        const Hero *winner;
        
        int noOfRounds = 0;
        
        //this probably should be its own function
        while (left.isAlive() && right.isAlive() && noOfRounds < MAX_ROUNDS) {
            left -= right.attackStrength();
            right -= left.attackStrength();
            ++noOfRounds;
        }
        
        if (!left.isAlive()) {
            winner = &second;
        }
        if (!right.isAlive() || (!left.isAlive() && !right.isAlive())) {
            winner = &first;
        }
        cout << " : Winner is " << *winner << " in " << noOfRounds << " rounds." << endl;
        return *winner;
    }
}