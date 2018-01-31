#include <iostream>

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
            
            void move(double dx, double dy);
            void changeWidth(double perc);
            void changeHeight(double perc);
            double width() const;
            double height() const;
            double area() const;
            double perimeter() const;
    };
    
    Rectangle::Rectangle()
    {
        lowerLight.setX(0);
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