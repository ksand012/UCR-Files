#include "IntList.h"
#include <iostream>

IntList::IntList()
{
    head = 0;
    tail = 0;
    
}//Initializes an empty list.


IntList::~IntList()
{
    IntNode* cur = head;
    while( cur != 0 )
    {
        IntNode* nex = cur->next;
        delete cur;
        cur = nex;
    }
    head = 0;
    tail = 0;
    
}//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
void IntList::display() const
{
    IntNode *cur;
    for(cur = head; cur != 0; cur = cur->next)
    {
        cout << cur->data;
        if(cur->next != 0)
        cout << ' ';
    }
    
}//Displays to a single line all of the int values stored in the list, each separated by a space. This function does NOT output a newline or space at the end.
void IntList::push_front(int value)
{
    IntNode *temp = new IntNode(value);
    temp->next = head;
    head = temp;
    
    if(tail == 0)
    {
        tail = head;
    }
   /* IntNode* cur = head;
    while( cur != 0 )
    {
        IntNode* nex = cur->next;
        if(nex !=0)
        this->tail = cur;
        else
        this->tail = temp;
        cur = nex;
    }*/

    
}//Inserts a data value (within a new node) at the front end of the list.
void IntList::pop_front()
{
    if(empty())
    {
        return;
    }
    
    IntNode *temp = head->next;
    delete head;
    head = temp;
    
   /* IntNode* cur = head;
    
    while( cur != 0 )
    {
        IntNode* nex = cur->next;
        this->tail = cur;
        cur = nex;
    }*/
    
    if(head == 0)
    tail = 0;
    
}//Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
bool IntList::empty() const
{
    return(this->tail == 0);
    
}//Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.

//////NEW FOR PROGRAM////////


IntList::IntList(const IntList &cpy)
{
    
    /*if(this == &cpy)
    return;
    
    if(cpy.empty())
    {*/
        head = 0;
        tail = 0;
        
    //}
    for(IntNode *i = cpy.head; i!=0; i=i->next)
    {
        this->push_back(i->data);
    }
    
}//the copy constructor. Make sure this performs deep copy.

IntList & IntList::operator=(const IntList &rhs)
{
    if(this == &rhs)
    return *this;
    
    if(rhs.empty())
    {
        //clear();
        head = 0;
        tail = 0;
    }
    else
    {
    clear();
    for(IntNode *i = rhs.head; i!=0; i=i->next)
    {
        this->push_back(i->data);
    }
    }
    
    return *this;
    
    
    
}//the overloaded assignment operator. Make sure this performs deep copy.

void IntList::push_back(int value)
{
    /*
    IntNode *temp = 0;
    temp->data = value;
    if(this->head !=0)
    this->tail->next = temp;
    else
    {
        this->head = temp;
    }
    this->tail = temp;
    */
    /*
    if(this->tail != 0)
    {
    IntNode *temp = new IntNode(value);
    tail->next = temp;
    tail = temp;
    }
    else
    {
        IntNode *temp = new IntNode(value);
        tail = temp;
        head = temp;
    }
    */
    IntNode *temp = new IntNode(value);
    if(tail == 0)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }   
        
    /*
    IntNode* cur = head;
    while( cur != 0 )
    {
        IntNode* nex = cur->next;
        this->tail = cur;
        cur = nex;
    }
    */
    
}//Inserts a data value (within a new node) at the back end of the list.

void IntList::clear()
{
    while(!empty())
    pop_front();
    
    
} //Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.

void IntList::selection_sort()
{
    IntNode *i = 0;
    
    for(i = head; i!= 0; i = i->next)
    {
        IntNode *minLoc = i;
        
        for(IntNode *j = i->next; j !=0; j=j->next)
        {
            if(j->data < minLoc->data)
            minLoc = j;
        }
        swap(i->data, minLoc->data);
    }
    
}//Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.


void IntList::insert_ordered(int value)
{
    
    if(empty())
    push_front(value);
    
    else if(head->data >=value)
    {
        push_front(value);
    }
    
    else if(tail->data <= value)
    {
        push_back(value);
    }
    
    
    else
    {
        
        IntNode* current = head;
        IntNode* nextOne = head->next;
        IntNode* temp = new IntNode(value);
        while(nextOne != 0) {
          
            if(value < nextOne->data)
            {
                current->next = temp;
                temp->next = nextOne;
                return;
            }
          
            current = current->next;
            nextOne = nextOne->next;
    /*for(IntNode *i = this->head; i != 0; i = i->next)
    {
        if(i->data >= i->next->data && i->data <= i->next->next->data)
        {
            IntNode *temp = 0;
            temp->data = value;
            temp->next = i->next->next;
            i->next = temp;
            
        }*/
    }
    }
    
}//Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.


void IntList::remove_duplicates()
{
    
    if(head == tail)
    {
        return;
    }
    else
    {
        IntNode *temp = 0;
    for(IntNode *i = head; i != 0; i=i->next)
    {
        temp = i;
        
        for(IntNode *j = i->next; j!=0; j=temp->next)
        {
            if((i->data == j->data) && (j == tail))
            {
                delete j;
                tail = temp;
                tail->next = 0;
                
                if(head == tail)
                return;
                
            }
            
            else if((i->data == j->data) && (j != tail))
            {
                temp->next = j->next;
                delete j;
                
            }
            else
            {
                temp = temp->next;
            }
        }
        
        
    }
    }
    
    /*IntNode *i = 0;
    
    for(i = this->head; i!= 0; i = i->next)
    {
        IntNode *minLoc = i;
        
        for(IntNode *j = i; j !=0; j=j->next)
        {
            if(j->next->data == minLoc->data && j->next->next != 0 && j->next != 0)
            {
            IntNode *temp = j->next;
            j->next = j->next->next;
            delete temp;
            }
        }
        
    }*/
    
}// Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.

ostream & operator<<(ostream &out, const IntList &rhs)
{
    
    for(IntNode *i = rhs.head; i != 0; i = i->next)
    {
        out << i->data;
        if(i->next != 0)
        out << ' ';
    }
    
    return out;
    
}// A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.