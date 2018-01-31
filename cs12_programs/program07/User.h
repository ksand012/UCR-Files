//User.h
#include <string>
#include <iostream>

#ifndef __U_H__
#define __U_H__

using namespace std;
 
class User {
 private:
  string username;
  string password;

 public:
  User();
  User(const string& uname, const string& pass);
  string getUsername() const;
  bool check(const string &uname, const string &pass) const;
  bool setPassword(const string &oldpass, const string &newpass);
};

#endif