//User.cpp
#include "User.h"


  //creates a user with empty name and password.
  User::User()
  {
      this->username = "";
      this->password = "";
  }

  // creates a user with given username and password.
  User::User(const string& uname, const string& pass)
  {
      this->username = uname;
      this->password = pass;
  }

  //returns the username
  string User::getUsername() const
  {
      return this->username;
  }

  // returns true if the stored username/password matches with the
  // parameters. Otherwise returns false.
  // Note that, even though a User with empty name and password is 
  // actually a valid User object (it is the default User), this 
  // function must still return false if given a empty uname string.
  bool User::check(const string &uname, const string &pass) const
  {
      if(this->username == uname && this->password == pass && this->username != "" && this->password != "")
      return true;
      return false;
  }

  // sets a new password.
  // This function should only set the new password if the current (old) 
  // password is passed in. Also, a default User cannot have its 
  // password changed. 
  // returns true if password changed, false if not.
  bool User::setPassword(const string &oldpass, const string &newpass)
  {
      if(oldpass == this->password && this->password != "")
      {
        this->password = newpass;
        return true;
      }
      
      return false;
      
  }