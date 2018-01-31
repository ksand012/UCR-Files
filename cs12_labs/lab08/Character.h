#ifndef __CHARACTER_H__
#define __CHARACTER_H__

using namespace std;
#include <iostream>

enum HeroType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100;

class Character
{
    protected:
    HeroType type;
    string name;
    double health;
    double attackStrength;
    
    public:
    Character(HeroType type, const string &name, double health, double attackStrength);
    HeroType getType() const;
    const string & getName() const;
    int getHealth() const;
    void setHealth(double h);
    void damage(double d);
    bool isAlive() const;
    virtual void attack(Character &) = 0;
    
    
};

#endif