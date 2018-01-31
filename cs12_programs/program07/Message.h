//Don't forget inclusion guards!!

//Message.h
#include <string>
#include <iostream>
#include <vector>

#ifndef __M_H__
#define __M_H__
using namespace std;

//inclusion guards
  //includes

  class Message {  // abstract base class
   // protected will allow access to these members by objects of derived classes
   protected:
     string author;
     string subject;
     string body;
     unsigned id;  // New !!
     // This will be the size of the messageList vector to which the
     // newly constructed Message * is being pushed_back
     vector<Message *> childList; // New !!
     // This is how a Message is able to keep track of its Replies
 
   public:

     // default constructor
     Message();

     // Parameterized constructor; 
     // id will be the size of current BBoard's messageList
     Message(const string &athr, 
             const string &sbjct, 
             const string &body, 
             unsigned id);

     // Be very careful here: some Messages will have two pointers to 
     // them, stored in very different places!
     // Where are they, and who should be responsible for deleting 
     // them?
     virtual ~Message();
	 
     // returns true if the object is a Reply.
     virtual bool isReply() const = 0;	 

     virtual string toFormattedString() const = 0; // New!!
      void print(unsigned indentation) const; // New !!

     //returns the subject string.
     const string & getSubject() const;

     // returns the ID.
     unsigned getID() const; // New !!    

     // Adds a pointer to the child to the parent's childList. 
     void addChild(Message *child); // New !! 
     
     	void display() const;	

  };

  //end inc guards

/*
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

*/

#endif