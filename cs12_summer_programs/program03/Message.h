//Message.h
#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include <string>
#include <iostream>

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