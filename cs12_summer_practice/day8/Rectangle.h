#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include <iostream>
#include "Point.h"

using namespace std;
    
    class Rectangle
    {
        private:
            Point lowerLeft();
            Point upperRight();
        public:
            ///default rectangle
            //located at Point (0,0) with width of 0.0 and height of 0.0
            Rectangle();
            Rectangle(const Point &lowerLeft, double width, double height);
            Rectangle(const Point &lowerLeft, const Point &upperRight);
            
            //Output Format - LL (x,y), W: width, H: height
            void display() const;
            Point lowerLeft() const;
            Point lowerRight() const;
            Point upperLeft() const;
            Point upperRight() const;
            
            void displayCorners() const;
            
            void move(double dx, double dy); //<---
            void changeWidth(double perc);  //<----
            void changeHeight(double perc);
            double width() const;
            double height() const;
            double area() const;
            double perimeter() const;
    };
    
    #endif