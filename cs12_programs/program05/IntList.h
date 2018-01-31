#ifndef _INTLIST_H_
#define _INTLIST_H_

#include <iostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList
{
    private:
        IntNode *head;
        IntNode *tail;
    public:
        IntList(); //Initializes an empty list.
        ~IntList(); //Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
        void display() const; //Displays to a single line all of the int values stored in the list, each separated by a space. This function does NOT output a newline or space at the end.
        void push_front(int value); //Inserts a data value (within a new node) at the front end of the list.
        void pop_front(); //Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
        bool empty() const;// Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
        
        IntList(const IntList &cpy); //the copy constructor. Make sure this performs deep copy.
        IntList & operator=(const IntList &rhs); //the overloaded assignment operator. Make sure this performs deep copy.
        void push_back(int value); //Inserts a data value (within a new node) at the back end of the list.
        void clear(); //Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
        void selection_sort(); //Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
        void insert_ordered(int value); //Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
        void remove_duplicates(); //Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
        friend ostream & operator<<(ostream &out, const IntList &rhs); //A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.
};

#endif