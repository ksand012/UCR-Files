#include "IntVector.h"    
    
    /*private:
    unsigned sz;
    //stores the size of the IntVector (the number of elements currently being used).
    unsigned cap;
    //store the size of the array
    int *data; 
    //stores the address of the dynamically-allocated array of integers
    */
    
    
    IntVector::IntVector()
    {
        this->sz = 0;
        this->cap = 0;
        this->data = 0;
    }
    IntVector::IntVector(unsigned size, int value)
    {
        this->sz = size;
        this->cap = size;
        this->data = new int[this->sz];
        
        for(unsigned i = 0; i < this->size(); i++)
        {
            data[i] = value;
        }
    }
    IntVector::~IntVector()
    {
        delete [] this->data;
    }
    unsigned IntVector::size() const
    {
        return this->sz;
    }
    
    
    unsigned IntVector::capacity() const
    {
        return this->cap;
    }
    
    bool IntVector::empty() const
    {
        if(this->sz == 0)
        return true;
        
        return false;
    }
    const int & IntVector::at(unsigned index) const
    {
        if(index >= this->size())
        throw out_of_range("IntVector::at_range_check");
        
        return data[index];
    }
    const int & IntVector::front() const
    {
        return data[0];
    }
    const int & IntVector::back() const
    {
        return data[this->size()-1];
    }
    
    void IntVector::expand()
    {
        int *temp = 0;
        if(this->cap == 0)
        temp = new int[1];
        else
        temp = new int[this->cap * 2];
        
        for(unsigned i = 0; i < this->size(); i++)
        {
            temp[i] = this->data[i];
        }
        
        delete data;
        this->data = temp;
        if(this->cap == 0)
        this->cap = 1;
        else
        this->cap *= 2;
    }
    
    void IntVector::expand(unsigned amount)
    {
        int *temp = new int[this->capacity() + amount];
        
        for(unsigned i = 0; i < this->size(); i++)
        {
            temp[i] = this->data[i];
        }
        
        delete data;
        this->data = temp;
        this->cap += amount;
    }
    
    void IntVector::insert(unsigned index, int value)
    {
        if(index >= this->size())
        throw out_of_range("IntVector::insert_range_check");
        
        while(this->size()+1 >= this->cap)
        this->expand();
        
        int *temp = new int[this->cap];
        
        for(unsigned i = 0; i < index; i++)
        {
            temp[i] = this->data[i];
        }
        
        temp[index] = value;
        
        for(unsigned j = index; j < this->size(); j++)
        {
            temp[j+1] = this->data[j];
        }
        
        delete data;
        this->data = temp;
        this->sz += 1;
    }
    
     void IntVector::erase(unsigned index)
    {
        if(index >= this->size())
        throw out_of_range("IntVector::erase_range_check");
        
        int *temp = new int[this->cap];
        
        for(unsigned i = 0; i < index; i++)
        {
            temp[i] = this->data[i];
        }
        
        for(unsigned j = index; j < this->size()-1; j++)
        {
            temp[j] = this->data[j+1];
        }
        
        delete data;
        this->data = temp;
        this->sz -= 1;
    }
    
    void IntVector::push_back(int value)
    {
        if(this->size() == 0)
        
        while(this->size()+1 >= this->cap)
        this->expand();
        this->sz += 1;
        
        int *temp = new int[this->cap];
        
        for(unsigned i = 0; i < this->size(); i++)
        {
            temp[i] = this->data[i];
        }
        
        temp[this->size()+1] = value;
        
        delete data;
        this->data = temp;
        //this->sz += 1;
        //this->insert(this->size()-1, value);
    }
    
    void IntVector::pop_back()
    {
        this->sz -= 1;
    }
    
    void IntVector::clear()
    {
        this->sz = 0;
    }
    
    void IntVector::resize(unsigned size, int value)
    {
        if(size < this->size())
        this->sz = size;
        else if(size > this->size())
        {
            while(size > this->size())
            this->push_back(value);
        }
    }
    
    void IntVector::reserve(unsigned n)
    {
        if(this->capacity() <= n)
        this->cap = n;
        
        if(n > this->capacity())
        this->expand(n);
    }
    
    void IntVector::assign(unsigned n, int value)
    {
        if(n <= this->capacity())
        {
            this->sz = n;
            for(unsigned i = 0; i < this->size(); i++)
            {
                data[i] = value;
            }
        }
        
        if(n > this->capacity() * 2)
        {
            expand(n);
            this->sz = this->capacity() + n;
            for(unsigned i = 0; i < this->size(); i++)
            {
                data[i] = value;
            }
        }
        else if(n > this->capacity())
        {
            expand();
            this->sz = this->capacity() + n;
            for(unsigned i = 0; i < this->size(); i++)
            {
                data[i] = value;
            }            
            
        }
        
        
        /*int *temp = new int[this->capacity()];
        for(unsigned i = 0; i < n; i++)
        {
            temp[i] = value;
        }
        
        delete data;
        data = temp;
        this->sz = n;*/
        
        
    }
    
     int & IntVector::at(unsigned index)
    {
        if(index >= this->size())
        throw out_of_range("IntVector::at_range_check");
        
        return data[index];
    }
    
    int & IntVector::front()
    {
        return data[0];
    }
    
    int & IntVector::back()
    {
        return data[this->size()-1];
    }