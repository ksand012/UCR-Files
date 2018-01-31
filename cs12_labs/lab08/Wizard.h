#ifndef __WIZARD_H___
#define __WIZARD_H___
using namespace std;

#include <iostream>
#include "Character.h"


class Wizard : public Character
{
    
    protected:
    int rank;
    public:
    Wizard(const string &name, double health, double attackStrength, int rank);
    void attack(Character &);
    
    
    
};

#endif