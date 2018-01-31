#include <iostream>

using namespace std;

class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const; 
      void display() const; 
};

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int r)
{
    numerator = r;
    denominator = 1;
}

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
}

const Rational Rational::add(const Rational & c) const
{
    //(a/b) + (c/d) = (ad + bc) / (b*d)
    
    Rational c4;
    c4.numerator = ((this->numerator * c.denominator) + (this->denominator * c.numerator));
    c4.denominator = (this->denominator * c.denominator);
    return c4;
    
}

const Rational Rational::subtract(const Rational & c) const
{
    // (a/b) - (c/d) = (ad - bc) / (b*d)
    
    Rational c4;
    c4.numerator = ((this->numerator * c.denominator) - (this->denominator * c.numerator));
    c4.denominator = (this->denominator * c.denominator);
    return c4;

    
}

const Rational Rational::multiply(const Rational & c) const
{
    // (a/b) * (c/d) = (ac) / (bd)
    
    Rational c4;
    c4.numerator = (this->numerator * c.numerator);
    c4.denominator = (this->denominator * c.denominator);
    return c4;


    
}

const Rational Rational::divide(const Rational & c) const
{
    // (a/b) / (c/d) = (ad) / (cb)
    
    Rational c4;
    c4.numerator = (this->numerator * c.denominator);
    c4.denominator = (this->denominator * c.numerator);
    return c4;



    
}

void Rational::display() const
{
    cout << this->numerator << " / " << this->denominator;
}

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   int choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation (1 - 4):" << endl
      << "1 - Addition (A + B)" << endl
      << "2 - Subtraction (A - B)" << endl
      << "3 - Multiplication (A * B)" << endl
      << "4 - Division (A / B)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 2) {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 3) {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 4) {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}

Rational getRational() {
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
      << "1 - 2 parameters (numerator & denominator)" << endl
      << "2 - 1 parameter (numerator)" << endl
      << "3 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}