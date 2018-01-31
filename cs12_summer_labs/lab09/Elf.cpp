#include "Elf.h"


Elf::Elf(const string &name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength), family(family)
{}
    
void Elf::attack(Character &opponent)
{
    if(opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.family == this->family)
        {
            cout << "Elf " << this->getName() << " does not attack Elf " << opp.getName() << "." << endl << "They are both members of the " << this->family << " family." << endl;
        }
        else
        {
            double dam = 0;
            dam = (this->health/MAX_HEALTH) * (this->attackStrength);
            opponent.damage(dam);
            //The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.
            cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl << opponent.getName() << " takes " << dam << " damage." << endl;
        }
    }
    else
    {
        double dam = 0;
        dam = (this->health/MAX_HEALTH) * this->attackStrength;
        opponent.damage(dam);
        cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl << opponent.getName() << " takes " << dam << " damage." << endl;
    }
        
}