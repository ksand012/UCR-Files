#include "IntVector.h"

IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector::IntVector(unsigned sz, int cap)
{
    this->sz = sz;
    this->cap = sz;
    data = new int[this->sz];
    
    for(unsigned i = 0; i < sz; i++)
    {
        data[i] = cap;
    }
}

IntVector::~IntVector()
{
    delete[] data;
}

void IntVector::expand()
{
    /*
    this->cap *= 2;
    
    if(this->cap == 0)
    {
        this->cap += 1;        
        data = new int[this->cap];
    }
    else
    {
        this->cap *=2;
    
        int *temp = new int[this->cap];
    
        for(unsigned i = 0; i < this->size(); i++)
        {
            temp[i] = data[i];
        }
        //delete[] data;
        data = temp;
        //delete temp;
        }
    */
    
    int *temp = data;

    this->cap *= 2;

    if (this->cap == 0) 
    {
        this->cap += 1;
        data = new int [this->cap];
    }

    else 
    {
        data = new int [this->cap];
        for(unsigned i = 0; i < this->size(); i++)
        {
            data[i] = temp[i];
        }
    } 
}

void IntVector::expand(unsigned amount)
{
    /*
    if(this->cap == 0)
    {
      this->cap = amount;  
      data = new int[this->cap];
    }
    else
    {
    this->cap = amount;
    
    int *temp = new int[this->cap];
    
    for(unsigned i = 0; i < this->size(); i++)
    {
        temp[i] = data[i];
    }
    //delete[] data;
    data = temp;
    //delete temp;
    }
    */
    
    int *temp = data;

    if (this->cap == 0) 
    {
        this->cap = amount;

        data = new int [this->cap];
    }
    else
    {
        this->cap = amount;
        data = new int [this->cap];
        for(unsigned int i = 0; i < this->size(); i++)
        {
            data[i] = temp[i];
        }
    }    
    
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if(sz == 0)
    return true;
    return false;
}

const int & IntVector::at(unsigned index) const
{
    if(index >= this->size())
    throw out_of_range("IntVector::at_range_check");
    else
    return data[index];
    
}

int & IntVector::at(unsigned index)
{
    if(index >= this->size())
    throw out_of_range("IntVector::at_range_check");
    else
    return data[index];
    
}

const int & IntVector::front() const
{
    return data[0];
}

int & IntVector::front()
{
    return data[0];
}

const int & IntVector::back() const
{
    return data[this->size()-1];
}

int & IntVector::back()
{
    return data[this->size()-1];
}

void IntVector::insert(unsigned index, int value)
{
    if(index > this->size())
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    this->sz += 1;
    
    if(this->size() > this->capacity())
    {
        this->expand();
    }
    
    /*
    
    int *temp = new int[this->cap];
    
    for(unsigned i = 0; i < index; i++)
    {
        temp[i] = data[i];
    }
        
    temp[index] = value;
        
    for(unsigned i = index+1; i < this->size() - 1; i++)
    {
        temp[i] = data[i];
    }
        data = temp;
    */
    
    for(unsigned i = this->size() - 1; i > index; i--)
    {
        data[i] = data[i-1];
    }
    
    data[index] = value;
}

void IntVector::erase(unsigned index)
{
    if(index >= this->size())
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    else
    {
        /*
        this->sz -= 1;
        int *temp = new int[this->cap];
    
        for(unsigned i = 0; i < index; i++)
        {
            temp[i] = data[i];
        }
        
        for(unsigned i = index; i < this->size() + 1; i++)
        {
            if(i != this->size() + 1)
            temp[i] = data[i+1];
        }
        
        data = temp;
        */
        
        for(unsigned i = index; 1+i < this->size(); i++)
        {
            data[i] = data[i+1];
        }
        this->sz -= 1;
    }
}

void IntVector::assign(unsigned n, int value)
{
    /*for(unsigned i = 0; i < this->size(); i++)
    {
        this->erase(this->size() - 1);
    }*/
    
    //unsigned temp = 0;
    if(n <= this->capacity())
    {
        this->sz = n;
        
        for(unsigned i = 0; i < this->size(); i++)
        {
            data[i] = value;
        }
    }
    if(n > (this->capacity()*2))
    {
        expand(n);
        this->sz=n;
        for(unsigned i = 0; i < this->size(); i++)
        {
            data[i] = value;
        }
        //this->sz=size;
    }
    else if(n > this->capacity())
    {
        expand();
        this->sz = n;
        for(unsigned i = 0; i < this->size(); i++)
        {
            data[i] = value;
        }
    }
    
    
}

void IntVector::push_back(int value)
{
    if(this->size() >= this->capacity())
    this->expand();
    this->sz += 1;
    data[this->size()-1] = value;
}

void IntVector::pop_back()
{
    this->sz -= 1;
}

void IntVector::clear()
{
   /*for(unsigned i = 0; i < this->size(); i++)
    {
        this->erase(this->size() - 1);
    }
    this->resize(0, 0);
    */
    
    this->sz = 0;
}

void IntVector::resize(unsigned size, int value)
{
    unsigned temp = 0;
    if(size < this->size())
    {
        this->sz = size;
    }
    
    if(size > this->size())
    {
        temp = this->size();
        this->sz = size;
        
        if(this->size() > (this->capacity()*2))
        {
            expand(this->size());
        }
        
        else if(this->size() > this->capacity())
        {
            expand();
        }
        
        for(unsigned i = temp; i < this->size(); i++)
        {
            data[i] = value;
        }
    }
    
}

void IntVector::reserve(unsigned n)
{
    if(this->capacity() <= n)
        this->cap = n;
    if(n > this->capacity())
        expand(n);
    
    
}



