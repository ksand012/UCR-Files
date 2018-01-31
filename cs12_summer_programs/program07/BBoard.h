#ifndef BBoard_h
#define BBoard_h

#include "User.h"
#include "Message.h"
#include <vector>

class BBoard {
 private:
    string title;
    vector<User> userList;
	//Pointer to the user who is currently logged in, initialized to 0
	//Is set in login() 
	//All instances of .getUsername() need to be ->getUsername()
	const User *currentUser;
    vector<Message *> messageList;

 public:
    // Constructs a board with a default title, 
    // empty user & message lists, 
    // and the "default" User
    BBoard();

    // Same as the default constructor except 
    // it sets the title of the board
    BBoard(const string &);

	//Destructor that deallocates all Messages pointed to in the list
	~BBoard();

    // Imports all the authorized users from an input file, 
    // storing them as User objects in the vector userList
    // The name of the input file is passed in as a parameter to this function. 
    // See below for file format.
    bool loadUsers(const string &);

	//Reads from file and stores messages as pointers to messages.
	//Data format is specified in Google Doc.
	bool loadMessages(const string &);

	//Final action of the BBoard before closing.
	//Writes to the file in the given format and returns false only error
	//while opening the file.
	bool saveMessages(const string &);

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
    // First verifies a User has been logged in.
    // Exits **function** immediately if no User logged in (Default User).
    // Continues to display menu options to user and performs requested action
    // until user chooses to quit.
    // See output samples for exact format of menu.
    void run();

// Suggested private helper functions (not required)
 private:
 	void addUser(const string &, const string &);
	const User* getUser(const string&, const string &);
	void addTopic();
	void addReply();
    void display() const;
    void addMessage();
};

unsigned Str2UInt(string);

#endif
