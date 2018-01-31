#include "Rectangle.h"
    
    Rectangle::Rectangle()
    {
        lowerRight.setX(0);
        upperLeft.setY(0);
        width = 0.0;
        height = 0.0;
        
    }
    
    Rectangle::Rectangle(const Point &lowerLeft, double width, double height)
    {
        this->lowerLeft = lowerLeft;
        this->upperRight = Point(lowerLeft.getX() + width, lowerLeft.getY() + height);
        
    }
    
    Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight)
    {
        this->lowerLeft = lowerLeft;
        this->upperRight = upperRight;
        //this->width = upperRight.getX() - lowerLeft.getX();
        //this->height = upperRight.getY() - lowerLeft.getY();
    }
    
    Point lowerLeft() const
    {
        return this->lowerLeft;
    }
    void Rectangle::display() const
    {
         //Output Format - LL (x,y), W: width, H: height
         cout << "LL ";
         this->lowerLeft.display();
         cout << ", W: " << width() << ", H: " << height();
        
    }
    
    void Rectangle::move(double dx, double dy)
    {
        this->lowerLeft.move(dx, dy);
        this->upperRight.move(dx, dy);
    }
    
    void Rectangle::changeWidth(double perc)
    {
        this->upperRight.setX(this->width() * perc);
    }
    
    