#include <string>
#include <iostream>
#include "Message.h"
#ifndef __T_H__
#define __T_H__
using namespace std;

  class Topic : public Message
  {
   public:
     Topic();
     Topic(const string &athr, 
           const string &sbjct, 
           const string &body, 
           unsigned id);
	virtual bool isReply() const;
     virtual string toFormattedString() const;  // New !!

  };

#endif