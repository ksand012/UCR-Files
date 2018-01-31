#ifndef POINT_H
#define POINT_H

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
    
    #endif