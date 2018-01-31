#include <iostream>

using namespace std;
    
    class Point
    {
        private:
            double xCoord;
            double yCoord;
        public:
            Point();
            double getX() const; //Accessor, getter
            double getY() const; //Accessor, getter
            void setX(double); //Mutator, setter
            void setY(double); //Mutator, setter
            void move(double dx, double dy);
            void display() const; //Accessor, getter, prints: (x,y)
    };
    
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
    
    int main()
    {
        Point p1;
        cout << p1.getX() << endl;
        p1.setX(4.5);
        p1.display();
        p1.move(1, 1);
        p1.display();
        
        Point p2;
        cout << ' ';
        p2.display();
        return 0;
        
    }