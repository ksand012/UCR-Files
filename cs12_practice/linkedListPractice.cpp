#include <iostream>
#include <cstdlib>
using namespace std;

    struct IntNode
    {
        int data;
        IntNode *next;
        IntNode(int data) : data(data), next(0) {}
        
        
    };
    
    class IntList
    {
        private:
            IntNode *head;
        public:
            IntList();
            void push_front(int);
        
        
    };
    
IntList::IntList() : head(0) {}

void IntList::push_front(int d)
{
    IntNode *temp = headl
    head = new IntNode(d);
}
int main()
    {
        IntList l1;
        l1.push_front(13);
        
        return 0;
    }
    
    /*
    
    Notes:
    
    Linklist has variable that stores first node of the list, called head.
    
    Advantage of Linklist is never having more memory than we need, unlike arrays where it has extra we don't even use.
    
    Tail of linklist is data.
    
    Push front creates new LinkList, tells the head to point to the new Linklist, then the new Linklist is pointed to the rest of the list, thus allowing for push_front.
    
    
    
    */