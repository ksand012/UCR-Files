#include "Warrior.h"
#include <iostream>


Warrior::Warrior(const string &name, double health, double attackStrength, string org):Character(WARRIOR, name, health, attackStrength), allegiance(org)
{
}

void Warrior::attack(Character &opponent)
{
    if (opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);

        if(opp.allegiance == this-> allegiance)
        {
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else
        {
            double dam = (this-> health / MAX_HEALTH) * (this-> attackStrength);
            opponent.damage(dam);
            cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << dam << " damage." << endl;

        }
    }

    else
    {
        double dam = (this-> health / MAX_HEALTH) * (this-> attackStrength);
        opponent.damage(dam);
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << dam << " damage." << endl;

    }
    
}