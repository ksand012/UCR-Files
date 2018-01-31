 #include "Point.h"
 
 Point::Point()
    {
        setX(0.0);
        setY(0.0);
        
    }

    double Point::getX() const //this is the header of the function.  goes: return type, name of class, ::, name of function
    {
        return this->xCoord;
    }
    
    double Point::getY() const
    {
        return this->yCoord;
    }
    
    void Point::setX(double input)
    {
        this->xCoord = input;
    }
    
    void Point::setY(double input)
    {
        this->yCoord = input;
    }
    
    void Point::move(double dx, double dy)
    {
        this->setX(this->getX() + dx);
        this->setY(this->getY() + dy);
        
    }
    
    void Point::display() const
    {
        cout << '(' << this->getX() << ',' << this->getY() << ')';
    }