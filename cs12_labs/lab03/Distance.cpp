#include "Distance.h"

Distance::Distance()
{
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in)
{
    this->feet = ft;
    this->inches = in;
    init();
}

Distance::Distance(double in)
{
    this->feet = 0;
    this->inches = in;
    init();
    
}

unsigned Distance::getFeet() const
{
    return this->feet;
}

double Distance::getInches() const
{
    return this->inches;
}

double Distance::distanceInInches() const
{
    return ((this->feet * 12) + this->inches);
}

double Distance::distanceInFeet() const
{
    return (this->feet + (this->inches/12));
}

double Distance::distanceInMeters() const
{
    return(distanceInInches() * 0.0254);
}

const Distance Distance::operator+(const Distance &rhs) const
{
    Distance newDist = Distance((rhs.feet + this->feet), (rhs.inches + this->inches));
    return newDist;
}

const Distance Distance::operator-(const Distance &rhs) const
{
   Distance newDist = Distance(distanceInInches() - rhs.distanceInInches());
    return newDist; 
    
}

ostream & operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init()
{
    if(this->feet < 0)
    this->feet *= -1;
 
    if(this->inches < 0.0)
    this->inches *= -1;
 
    while(this->inches > 12)
    {
        inches = inches - 12;
        feet += 1;
    }
}