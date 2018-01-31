#include "Wizard.h"
#include <iostream>
using namespace std;
#include "Character.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank):Character(WIZARD, name, health, attackStrength), rank(rank)
{
}


void Wizard::attack(Character &opponent)
{
    if (opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        
        double dam = (attackStrength) * ((this-> rank * 1.0) / opp.rank);
        opp.damage(dam);
        cout << "Wizard " << this->name << " attacks " << opp.name << " --- POOF!!" << endl;
        cout << opp.name << " takes " << dam << " damage." << endl;
        
    }
    
    else
    {
        double dam = attackStrength;
        opponent.damage(dam);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << dam << " damage." << endl;
          
    }
    
}