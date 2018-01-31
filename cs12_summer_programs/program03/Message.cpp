#include "Message.h"


	// default constructor
	Message::Message()
	{
	    this->author = "";
	    this->subject = "";
	    this->body = "";
	}
	
	// Parameterized constructor; 
	Message::Message(const string &athr, const string &sbjct, const string &body)
	{
	    this->author = athr;
	    this->subject = sbjct;
	    this->body = body;
	}
	
	
	// Displays the Message using the following format:
      //
	// subject
	// from author: body
	void Message::display() const
	{
	    cout << this->subject << endl << "from " << this->author << ": " << this->body << endl;
	}