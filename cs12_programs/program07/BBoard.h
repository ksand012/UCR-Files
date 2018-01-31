//Don't forget inclusion guard!!

//BBoard.h
#include <string>
#include <vector>

#ifndef __B_H__
#define __B_H__
using namespace std;

#include "Message.h"
#include "User.h"
#include "Reply.h"
#include "Topic.h"


class BBoard {
 private:
    string title;
    vector<User> userList;
    const User* currentUser;
    vector<Message*> messageList;

 public:
    BBoard();
    BBoard(const string &);
    
    ~BBoard(); //destructor
    bool loadUsers(const string &);
    bool loadMessages(const string& datafile); //new
    
    bool saveMessages(const string& datafile); //new
    
    bool login();
    void run();
    
    private:    
    void addUser(const string& name, const string& pass);
    const User* getUser(const string& name, const string& pw) const;
    void addReply();
    unsigned stringToInt(string input);

};

#endif