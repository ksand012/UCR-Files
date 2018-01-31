#include "Warrior.h"


Warrior::Warrior(const string &name, double health, double attackStrength, string aleg) : Character(WARRIOR, name, health, attackStrength), aleg(aleg)
{}
    
void Warrior::attack(Character &opponent)
{
    if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.aleg == this->aleg)
        {
            cout << "Warrior " << this->getName() << " does not attack Warrior " << opp.getName() << "." << endl << "They share an allegiance with " << this->aleg << "." << endl;
        }
        else
        {
            double dam = 0;
            dam = (health/MAX_HEALTH) * this->attackStrength;
            opponent.damage(dam);
            cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl << opponent.getName() << " takes " << dam << " damage." << endl;
        }
    }
    else
    {
        double dam = 0;
        dam = (health/MAX_HEALTH) * this->attackStrength;
        opponent.damage(dam);
            cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl << opponent.getName() << " takes " << dam << " damage." << endl;
    }
        
}