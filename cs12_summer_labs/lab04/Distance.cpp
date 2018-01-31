// Distance.h file

#include "Distance.h"

    /* Constructs a default Distance of 0 (0 feet and 0.0 inches)
    */
    Distance::Distance()
    {
        //    unsigned feet;
        //    double inches;
        
        this->feet = 0;
        this->inches = 0.0;
        
        
    }


    /* Constructs a distance of ft feet and in inches,
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
    */
    Distance::Distance(unsigned ft, double in)
    {
        //    unsigned feet;
        //    double inches;
        
        this->feet = ft;
        this->inches = in;
        init();
        
    }


    /* Constructs a distance of 0 ft and in inches, 
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
    */
    Distance::Distance(double in)
    {
        this->inches = in;
        this->feet = 0;
        init();
        
        
    }


    /* Returns just the feet portion of the Distance
    */
    unsigned Distance::getFeet() const
    {
        return this->feet;
    }


    /* Returns just the inches portion of the Distance
    */
    double Distance::getInches() const
    {
        return this->inches;
    }


    /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
    */
    double Distance::distanceInInches() const
    {
        return (this->feet*12+this->inches);
    }


    /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
    */
    double Distance::distanceInFeet() const
    {
        return this->feet + inches/12;
    }


    /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
    */
    double Distance::distanceInMeters() const
    {
        return distanceInInches() * 0.0254;
    }


    /* Returns the sum of 2 Distances.
    */
    const Distance Distance::operator+(const Distance &rhs) const
    {
        Distance final(this->feet + rhs.feet, this->inches + rhs.inches);
        return final;
    }


    /* Returns the difference between 2 Distances.
    */
    const Distance Distance::operator-(const Distance &rhs) const
    {
        Distance final(distanceInInches() - rhs.distanceInInches());
        return final;
        
    }


    /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
    */
    ostream & operator<<(ostream &out, const Distance &rhs)
    {
        return (out << rhs.feet << "' " << rhs.inches << "\"");
        
        
    }


    /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
    */
    void Distance::init()
    {
        if(this->inches < 0)
        this->inches = this->inches * -1;
        
        if(this->feet < 0)
        this->feet = this->feet * -1;
        
        while(this->inches > 12)
        {
            inches = inches - 12;
            feet += 1;
        }
        
    }