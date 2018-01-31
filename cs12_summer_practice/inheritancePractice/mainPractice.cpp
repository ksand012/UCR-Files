int main()
{
    Employee e1 = "";
    
    
    
    vector<Employee> employees;
    employees.push_back(emp1);
    employees.push_back(lec1);
    employees.push_back(lec2);
    
    for(unsigned i = 0; i < employees.size(); i++)
    {
        employees.at(i).display();
        cout << endl;
    }
    
    //only displays employee variables, not variables from derived classes.
    
    //instead, store employee pointer
    
    vector<Employee *> employees;
    employees.push_back(&emp1);
    employees.push_back(&lec1);
    employees.push_back(&lec2);
    
    for(unsigned i = 0; i < employees.size(); i++)
    {
        employees.at(i)->display();
        cout << endl;
        
    }
    
}
