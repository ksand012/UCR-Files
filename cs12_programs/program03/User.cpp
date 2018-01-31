#include "User.h"

User::User()
{
    this->username = "";
    this->password = "";
}

User::User(const string& uname, const string& pass)
{
    this->username = uname;
    this->password = pass;
}

string User::getUsername() const
{
    return this->username;
}

bool User::check(const string &uname, const string &pass) const
{
    if(uname == "" || pass == "")
    return false;
    if((uname == this->username) && (pass == this->password))
    return true;
    
    
    return false;
}

bool User::setPassword(const string &oldpass, const string &newpass)
{
    if(oldpass == this->password)
    {
        this->password = newpass;
        return true;
    }
    else if(oldpass == "")
    {
        return false;
    }
    else
    return false;
}