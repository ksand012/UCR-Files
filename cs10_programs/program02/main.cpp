#include <iostream>
#include <cmath>     // Note: Needed for math functions in part (3)
using namespace std;

int main() {
   double wallHeight = 0.0;
   double wallWidth  = 0.0;
   double wallArea   = 0.0;
   const double PAINT_COVER = 350.0;
   double paintNeeded = 0.0;
   
   cout << "Enter wall height (feet): ";
   cin  >> wallHeight;
   cout << endl;
   
   cout << "Enter wall width (feet): ";
   cin >> wallWidth;
   cout << endl;
   
   // (1) Calculate and output wall area
   wallArea = wallHeight * wallWidth;                // FIXME Replace by actual calculation
   cout << "Wall area: " << wallArea << " square feet" << endl;  // FIXME Finish this output statement

   
   paintNeeded = wallArea / PAINT_COVER;
   
   cout << "Paint needed: " << paintNeeded << " gallons" << endl;
   
   paintNeeded = ceil(paintNeeded);
   
   cout << "Cans needed: " << paintNeeded << " cans" << endl;
   // FIXME (2) Calculate and output needed paint gallons

   // FIXME (3) Calculate and output needed paint cans (round gallons up to nearest integer)

   return 0;
}