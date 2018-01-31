class Point //the blueprint of a new type.  no actual object yet.
{
    private:
        double xCoord;
        double yCoord;
    public:
        Point(double, double);
        Point();
        void display() const; // declared inside class, so it's a member function.  no longer a global function
        double getX() const;
        double getY() const;
        void setX(double x);
        void setY(double y);
        void move(double dx, double dy);
    
};