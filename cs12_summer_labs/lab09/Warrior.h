#ifndef __WAR_H__
#define __WAR_H__

#include "Character.h"

class Warrior : public Character
{
    private:
    string aleg;
    public:
    Warrior(const string &name, double health, double attackStrength, string aleg);
    void attack(Character &);
};

#endif