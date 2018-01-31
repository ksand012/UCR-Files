#include "Wizard.h"


Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength), rank(rank)
{}
    
void Wizard::attack(Character &opponent)
{
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
            double dam = 0;
            dam = (attackStrength) * ((this-> rank * 1.0) / opp.rank);
            opp.damage(dam);
            cout << "Wizard " << this->getName() << " attacks " << opp.getName() << " --- POOF!!" << endl << opp.getName() << " takes " << dam << " damage." << endl;
    }
    else
    {
        double dam = 0;
        dam = this->attackStrength;
        opponent.damage(dam);
        cout << "Wizard " << this->getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl << opponent.getName() << " takes " << dam << " damage." << endl;
    }
        
}