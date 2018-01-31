#include "IntList.h"

   /* Initializes an empty list.
   */
   IntList::IntList()
   {
       this->head = 0;
   }

   /* Inserts a data value to the front of the list.
   */
   void IntList::push_front(int data)
   {
    IntNode* tmpNext = head;
    head = new IntNode(data);
    head->next = tmpNext;
   }

   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   ostream & operator<<(ostream & out, const IntList &rhs)
   {
       if(rhs.head == 0)
       return out;
        operator <<(out, rhs.head);;
       return out;
       
       
   }

   /* Returns true if the integer passed in is contained within the IntList, 
      otherwise returns false.
   */
   bool IntList::exists(int contained) const
   {
        if(head == 0)
        return false;
        else if(head->data == contained)
            return true;
        return exists(head->next, contained);
       
   }


   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in,
      otherwise returns false.
   */
   bool IntList::exists(IntNode *start, int contained) const
   {
        if(start == 0)
        return false;
        else if(start->data == contained)
            return true;
        return exists(start->next, contained);
       
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
       out << " ";
        operator <<(out, rhs->next);;
       return out;
    
}

