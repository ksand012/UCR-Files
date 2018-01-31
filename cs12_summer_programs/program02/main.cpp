#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   Date();
   Date(unsigned m, unsigned d, unsigned y);
   Date(const string &mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;

 private:
   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   unsigned number(const string &mn) const;
};

Date::Date()
{
    // creates the date January 1st, 2000.
    this->month = 1;
    this->monthName = name(1);
    this->day = 1;
    this->year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   bool didBad = false;
   this->month = m;
   
   if(name(m) == "Invalid Date")
   {
       if(this->month > 12)
       this->month = 12;
       else
       this->month = 1;
       
       didBad = true;
   }
   
   
   this->day = d;
   
   if((d < 1) || (d > daysPerMonth(this->month, y)))
   {
       if(d < 1)
       this->day = 1;
       else
       this->day = daysPerMonth(this->month, y);
       
       didBad = true;
   }
   
   this->year = y;
   this->monthName = name(this->month);
   
   if(didBad)
   cout << "Invalid date values: Date corrected to " << this->month << '/' << this->day << '/' << this->year << '.' << endl;
    
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
    bool nameBad = false;
       bool didBad = false;
       string str = name(number(mn));
   this->month = number(str);
   
   if(number(str) == 0)
   {
       if(this->month > 12)
       this->month = 12;
       else
       this->month = 1;
       
       //didBad = true;
       nameBad = true;
   }
   
   
   this->day = d;
   
   if((this->day < 1) || (d > daysPerMonth(this->month, y)))
   {
       if(this->day < 1)
       this->day = 1;
       else if(this->day > daysPerMonth(this->month, y))
       this->day = daysPerMonth(this->month, y);
       
       didBad = true;
   }
   
   this->year = y;
   this->monthName = name(this->month);
   
   if(didBad && !nameBad)
   cout << "Invalid date values: Date corrected to " << this->month << '/' << this->day << '/' << this->year << '.' << endl;
   else if(nameBad)
   {
       this->day = 1;
       this->year = 2000;
   cout << "Invalid month name: the Date was set to " << this->month << '/' << this->day << '/' << this->year << '.' << endl;
   }
    
}

void Date::printNumeric() const
{
       /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */
    cout << this->month << '/' << this->day << '/' << this->year;
}

void Date::printAlpha() const
{
       /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
    cout << this->monthName << ' ' << this->day << ", " << this->year;
}

bool Date::isLeap(unsigned y) const
{
    /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
    bool temp = false;
    if(y % 4 == 0) //implies leap year
    temp = true;
    
    if(y % 100 == 0) //implies NOT leap year
    temp = false;
    
    if(y % 400 == 0) //implies leap year
    temp = true;
    
    return temp;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
        return 31;
    else if((m==4)||(m==6)||(m==9)||(m==11))
    return 30;
    else if(m==2)
    {
        if(isLeap(y))
        return 29;
        else
        return 28;
        
    }
    else
    return 0;
      /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */ 
    
}

string Date::name(unsigned m) const
{
    string mName = "";
    switch(m)
    {
        case 1: mName = "January";
        break;
        case 2: mName = "February";
        break;
        case 3: mName = "March";
        break;
        case 4: mName = "April";
        break;
        case 5: mName = "May";
        break;
        case 6: mName = "June";
        break;
        case 7: mName = "July";
        break;
        case 8: mName = "August";
        break;
        case 9: mName = "September";
        break;
        case 10: mName = "October";
        break;
        case 11: mName =  "November";
        break;
        case 12: mName = "December";
        break;
        default: mName = "Invalid Date";
        
    }
    
    return mName;
   
    
    
}

unsigned Date::number(const string &mn) const
{
    unsigned m = 0;
       /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   
   if(mn == "January" || mn == "january")
   m = 1;
   else if(mn == "February" || mn == "february")
   m = 2;
   else if(mn == "March" || mn == "march")
   m = 3;
   else if(mn == "April" || mn == "april")
   m = 4;
   else if(mn == "May" || mn == "may")
   m = 5;
   else if(mn == "June" || mn == "june")
   m = 6;
   else if(mn == "July" || mn == "july")
   m = 7;
   else if(mn == "August" || mn == "august")
   m = 8;
   else if(mn == "September" || mn == "september")
   m = 9;
   else if(mn == "October" || mn == "october")
   m = 10;
   else if(mn == "November" || mn == "november")
   m =  11;
   else if(mn == "December" || mn == "december")
   m = 12;
   else
   m = 0;
	
	return m;
    
}

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}