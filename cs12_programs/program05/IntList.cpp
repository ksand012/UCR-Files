#include "IntList.h"

IntList::IntList()
{
    head = 0;
    tail = 0;
    
}

IntList::IntList(const IntList &cpy)
{
    this->head = 0;
	this->tail = 0;
    if (!cpy.empty())
	{
	    IntNode* temp = cpy.head;
	    while(temp != 0)
	    {
	        push_back(temp->data);
	        temp = temp->next;
	        
	    }
	}
    
}

IntList::~IntList()
{
    while(!empty())
    pop_front();
}

void IntList::display() const
{
    if(empty())
    return;
    
    else
    {
    IntNode *temp = this->head;
    cout << this->head->data;
    while(temp->next != 0)
    {
        temp = temp->next;
        cout << " " << temp->data;
        //temp = temp->next;
        
    }
    
    }
    
}

void IntList::push_front(int value)
{
    IntNode* tmpNext = head;
    head = new IntNode(value);
    head->next = tmpNext;
    
    if(tail == 0)
    {
        tail = head;
    }
    
}

void IntList::pop_front()
{
  if(empty())
  {
      return;
  }
  else if(head != 0)
  {
      IntNode *temp = head->next;
      delete head;
      head = temp;
      
  }
  
  if(head == 0)
  tail = 0;
}

bool IntList::empty() const
{
    if(head == 0 && tail == 0)
    return true;
    
    return false;
    
}

IntList & IntList::operator=(const IntList &rhs)
{
    if (this != &rhs)
	{
		clear();
		IntNode *temp = rhs.head;
		while(temp != 0)
		{
		    push_back(temp->data);
		    temp = temp->next;
		    
		}
	}
	else if(rhs.empty())
	{
	    head = 0;
	    tail = 0;
	}
	else
	{
	    return *this;
	    
	}
	return *this;
    
}

void IntList::push_back(int value)
{
    IntNode* tmpNext = new IntNode(value);
    
    if(empty())
    {
        head = tmpNext;
        tail = tmpNext;
    }
    else
    {
        tail->next = tmpNext;;
        tail = tmpNext;
        
    }
    
}

void IntList::clear()
{
    while(!empty())
    pop_front();
}

void IntList::selection_sort()
{
    if(empty())
    return;
    
    else
    {
    int replace = 0;
    IntNode *pos_min = head;
    for(IntNode *i = head; i->next != 0; i = i->next)
    {
        pos_min = i;  
        
        for(IntNode *j = i->next; j != 0; j=j->next)
        {
            if(pos_min->data > j->data)
            {
                pos_min = j;
            }
        }
        replace = i->data;
        i->data = pos_min->data;
        pos_min->data = replace;
        
    }
    }
    
    
}

void IntList::insert_ordered(int value)
{
    
    if(this->empty())
        push_front(value);
        
    else if(value <= head->data)
        push_front(value);
        
    else if(value >= tail->data)
        push_back(value);
    
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
        }
        
    }
}

void IntList::remove_duplicates()
{
    
    if(empty() || (head == tail))
    return;
    else
    {
        IntNode *temp = 0;
    for(IntNode *i = head; i != 0; i=i->next)
    {
        temp = i;
        //IntNode *temp2 = i;
        
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
    
}

ostream & operator<<(ostream &out, const IntList &rhs)
{
    if(rhs.empty())
    return out;
    else
    {
    IntNode *temp = rhs.head;
    out << temp->data;
    while(temp->next != 0)
    {
        temp = temp->next;
        out << " " << temp->data;
        //temp = temp->next;
        
    }
    
    }
    
    return out;
    
}