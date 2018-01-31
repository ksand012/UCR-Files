//BBoard.h
#ifndef __BBOARD_H__
#define __BBOARD_H__
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Message.h"
#include "User.h"

class BBoard {
 private:
    string title;
    vector<User> userList;
    User currentUser;
    vector<Message> messageList;

 public:
    // Constructs a board with a default title, 
    // empty user & message lists, 
    // and the "default" User
    BBoard();

    // Same as the default constructor except 
    // it sets the title of the board
    BBoard(const string &);

    // Imports all the authorized users from an input file, 
    // storing them as User objects in the vector userList
    // The name of the input file is passed in as a parameter to this function.
    // Returns true if the file opened, false if it did not. 
    // See specifications for file format.
    bool loadUsers(const string &);

    // Asks for and validates a user/password.
    // Always asks for both user and password combo unless 'q' or 'Q' entered.
    // Checks userList to validate user and password.
    // If valid, sets currentUser to this User, outputs welcome message, 
    // then returns true.
    // Otherwise outputs error message and then repeats request
    // for username/password.
    // Continues until valid user/password 
    // or until 'q' or 'Q' is entered for username.
    // If 'q' or 'Q' is entered, does not ask for password, outputs "Bye!"
    // and then returns false.
    bool login();

    // Contains main loop of Bulletin Board.
    // First verifies a User has been logged in before calling this function.
    // (Do not call login function within this function.)
    // Returns from **function** immediately if no User logged in (Default User).
    // Continues to display menu options to user and performs requested action
    // until user chooses to quit.
    // See output samples for exact format of menu.
    void run();

 private:
    // These are only suggestions, not required helper functions.
    // Feel free to make your own private helper functions as you see fit.
    void display() const;
    void addMessage();
    bool userExists(const string &, const string &);
};

#endif