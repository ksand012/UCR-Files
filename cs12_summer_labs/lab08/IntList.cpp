#include "IntList.h"

using namespace std;

   /* Initializes an empty list.
   */
   IntList::IntList()
   {
       head = 0;
   }

   /* Inserts a data value to the front of the list.
   */
   void IntList::push_front(int value)
   {
    IntNode *temp = new IntNode(value);
    temp->next = head;
    head = temp;
   }

   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   ostream & operator<<(ostream & out, const IntList &rhs)
   {
    IntNode *i = rhs.head;
    if(i!=0)
    {
        operator << (out, i);
    }
    return out;
       
       
   }

   /* Returns true if the integer passed in is contained within the IntList, 
      otherwise returns false.
   */
   bool IntList::exists(int value) const
   {
       IntNode *i = this->head;
       
       if(i == 0)
       return false;
       else if(i->data == value)
       return true;
       
       return exists(i, value);
       
       
       
   }

   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in,
      otherwise returns false.
   */
   bool IntList::exists(IntNode *lhs, int value) const
   {
       if(lhs == 0)
       return false;
       if(lhs->data == value)
       return true;
       
       return exists(lhs->next, value);
       
       
   }

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream & out, IntNode *rhs)
{
    if(rhs == 0)
    return out;
    
    out << rhs->data;
    
    if(rhs->next != 0)
    out << ' ';
    operator << (out, rhs->next);
    return out;
    
}