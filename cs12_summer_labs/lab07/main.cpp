#include <iostream>

using namespace std;

#include "IntList.h"


int main() {

  //tests constructor, destructor, push_front, pop_front, display

   {
      cout << "\nlist1 constructor called";
      IntList list1;
      cout << "\npushfront 10";
      list1.push_front(10);
      cout << "\npushfront 20";
      list1.push_front(20);
      cout << "\npushfront 30";
      list1.push_front(30);
      cout << "\nlist1: ";
      list1.display();
      cout << "\npop";
      list1.pop_front();
      cout << "\nlist1: ";
      list1.display();
      cout << "\npop";
      list1.pop_front();
      cout << "\nlist1: ";
      list1.display();
      cout << "\npop";
      list1.pop_front();
      cout << "\nlist1: ";
      list1.display();
      cout << "\npushfront 100";
      list1.push_front(100);
      cout << "\npushfront 200";
      list1.push_front(200);
      cout << "\npushfront 300";
      list1.push_front(300);
      cout << "\nlist1: ";
      list1.display();
      cout << endl;
   }
   cout << "list1 destructor called" << endl;

   return 0;
}