#ifndef __WARRIOR_H__
#define __WARRIOR_H__

using namespace std;
#include <iostream>
#include "Character.h"


class Warrior : public Character {
    
    private:
        
        string allegiance;
    
    public:
    
        Warrior(const string &name, double health, double attackStrength, string org);
    
        
        void attack(Character &);
        
    
};

#endif
