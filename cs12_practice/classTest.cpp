#include <iostream>
#include "classTest.h"
using namespace std;


Point::Point(double x, double y)
{
   xCoord = x;
   yCoord = y;
    
}

Point::Point()
{
    xCoord = 0.0;
    yCoord = 0.0;
    
}

void Point::display() const
{
    cout << "(" << this->xCoord << ", " << this->yCoord << ")" << endl;
    
    //this-> is implicit parameter
}

double Point::getX() const
{
    return this->xCoord;
}

double Point::getY() const
{
    return this->yCoord;
}

void Point::setX(double x)
{
    this->xCoord = x;
}

void Point::setY(double y)
{
    this->yCoord = y;
}

void Point::move(double dx, double dy)
{
    xCoord = xCoord + dx;
    yCoord = yCoord + dy;
    
}
int main()
{
    Point p1; //now an actual object..
    p1.display();
    cout << endl;
    Point p2 = Point(3.5, 5.6);
    p2.display();
    cout << endl;
    cout << p1.getX() << ' ' << p1.getY();
    cout << endl;
    p1.setX(-1.1);
    p1.setY(8.34);
    cout << p1.getX() << ' ' << p1.getY();
    
    return 0;
}