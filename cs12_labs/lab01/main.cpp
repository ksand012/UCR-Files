// This program implements the Monte Carlo Method for estimating the value of PI.
	   
#include <iostream>
#include <cstdlib>
#include <cmath>
   
using namespace std;
   
// given the coordinates of a point (x,y) computes if the point is inside or on the circle 
// centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
bool isInside(double x, double y, double r)
{
   if((pow(x, 2) + pow(y, 2)) <= pow(r, 2))
   return true;
   else
   return false;
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s)
{
   int x, y; 
   x = (-s/2) + (rand() % (int) ((s/2) - (-s/2) + 1));
   y = (-s/2) + (rand() % (int) ((s/2) - (-s/2) + 1));
   // assign x and y to two random integers between -s/2 and s/2 

   if(isInside(x, y, s/2))
   return true;
   else
   return false;
   //Call the isInside function and return its output. 
   //You do not have to cast x & y to doubles, it is done automatically.
 
}

int main()
{
   srand(333);
   int side = 0; 
   // this is the side of the square and is also our resolution. 
   int tries = 0;  
   // this is the number of tries.

   cout << "Enter the size of a side of the square" << endl;
   
   cin >> side;
   //Get the users input using cin

   
   cout << "Enter number of tries" << endl;
 
   cin >> tries;
   //Get the users input using cin.
 
 
   int inCount = 0; 
   //counter to track number of throws that fall inside the circle

   for(int i = 0; i < tries; ++i)
   {
      if(throwDart(side))
      inCount++;
      //throw a dart using throwDart method and increment the counter depending on its output.
   }
   double pi = (double)4 * (inCount) /( tries);
   cout << "Estimated value of PI is " << pi;
   //Compute and display the estimated value of PI. Make sure you are not using integer division.


   return 0;
}