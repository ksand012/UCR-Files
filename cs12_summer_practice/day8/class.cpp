#include "Rectangle.h"
    
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