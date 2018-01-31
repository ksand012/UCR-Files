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
    
    IntNode* cur = head;
    while( cur != 0 )
    {
        IntNode* nex = cur->next;
        this->tail = cur;
        cur = nex;
    }

    
}//Inserts a data value (within a new node) at the front end of the list.
void IntList::pop_front()
{
    IntNode *temp = head->next;
    delete head;
    head = temp;
    
    IntNode* cur = head;
    while( cur != 0 )
    {
        IntNode* nex = cur->next;
        this->tail = cur;
        cur = nex;
    }
    
    if(head == 0)
    tail = 0;
    
}//Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
bool IntList::empty() const
{
    return(this->tail == 0);
    
}//Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
