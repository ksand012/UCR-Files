//Don't forget inclusion guards!!

//Message.h
#include <string>
#include <iostream>

#ifndef __M_H__
#define __M_H__
using namespace std;

class Message {
 private:
	string author;
	string subject;
	string body;

 public:

	// default constructor
	Message();
	
	// Parameterized constructor; 
	Message(const string &athr, 
	     const string &sbjct, 
	     const string &body);
	
	// Displays the Message using the following format:
      //
	// subject
	// from author: body
	void display() const;	
};

#endif