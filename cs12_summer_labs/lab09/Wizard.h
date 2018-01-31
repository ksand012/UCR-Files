#ifndef __WIZ_H__
#define __WIZ_H__

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