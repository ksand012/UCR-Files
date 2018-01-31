#include "BBoard.h"

/* private:
    string title;
    vector<User> userList;
    User currentUser;
    vector<Message> messageList;
    
    */

    // Constructs a board with a default title, 
    // empty user & message lists, 
    // and the "default" User
    BBoard::BBoard()
    {
        this->title = "Welcome to CS12 Bulletin Board";
        this->currentUser = User();
    }

    // Same as the default constructor except 
    // it sets the title of the board
    BBoard::BBoard(const string & title)
    {
        this->title = title;
        this->currentUser = User();
        
    }

    // Imports all the authorized users from an input file, 
    // storing them as User objects in the vector userList
    // The name of the input file is passed in as a parameter to this function.
    // Returns true if the file opened, false if it did not. 
    // See specifications for file format.
    bool BBoard::loadUsers(const string & temp)
    {
        ifstream ifSS;
        ifSS.open(temp.c_str());
        
        if(!ifSS.is_open())
        {
            return false;
        }
        
        string uInput = "";
        string pInput = "";
        
        while(ifSS >> uInput >> pInput)
        {
            if(uInput == "end")
            break;
            this->userList.push_back(User(uInput, pInput));
        }
        
        return true;
    }

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
    bool BBoard::login()
    {
        string userTemp = "";
        string passTemp = "";
        bool authLoop = false;
        cout << "Welcome to " << this->title << endl;
        while(!authLoop)
        {
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> userTemp;
            cout << endl;
            if(userTemp == "Q" || userTemp == "q")
            {
                cout << "Bye!" << endl;
                return false;
            }
        
            cout << "Enter your password: ";
            cin >> passTemp;
            cout << endl;
        
            if(userExists(userTemp, passTemp))
            {
                //currentUser = userList.at(i);
                authLoop = true;
            }
            else
            {
                cout <<"Invalid Username or Password!" << endl << endl;
            }   
        }
        cout << "Welcome back " << currentUser.getUsername() << "!" << endl;
        return true;
        
    }

    // Contains main loop of Bulletin Board.
    // First verifies a User has been logged in before calling this function.
    // (Do not call login function within this function.)
    // Returns from **function** immediately if no User logged in (Default User).
    // Continues to display menu options to user and performs requested action
    // until user chooses to quit.
    // See output samples for exact format of menu.
    void BBoard::run()
    {
        if(currentUser.getUsername() == "")
        return;
        bool done = false;
        char input = 'a';
        while(!done)
        {
        cout << endl << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Message ('N' or 'n')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
        cin >> input;
        cout << endl;
        
        if(input == 'D' || input == 'd')
        {
            display();
        }
        else if(input == 'N' || input == 'n')
        {
            addMessage();
        }
        else if(input == 'Q' || input == 'q')
        {
            done = true;
        }
        
        else
        cout << "Invalid entry." << endl;
        
        }
        
        cout << "Bye!" << endl;
        
        
        
        
        
        
    }
    
    void BBoard::display() const
    {
        if(messageList.size() != 0)
        {
        unsigned i = 0;
        for(i = 0; i < messageList.size(); i++)
        {
            cout << "---------------------------------------------------------" << endl << "Message #" << i+1 << ": ";
            messageList.at(i).display();
        }
        cout << "---------------------------------------------------------" << endl;
        }
        else
        cout << "Nothing to Display." << endl;
        
    }
    
    void BBoard::addMessage()
    {
        string tempSub = "";
        string tempBod = "";
        cout << "Enter Subject: ";
        cin.ignore();
        getline(cin, tempSub);
        cout << endl << "Enter Body: ";
        //cin.ignore();
        getline(cin, tempBod);
        cout << endl << "Message Recorded!" << endl;
        
        messageList.push_back(Message(this->currentUser.getUsername(), tempSub, tempBod));
        
    }
    
    bool BBoard::userExists(const string & u, const string & p)
    {
        for(unsigned i = 0; i < userList.size(); i++)
        {
            if(userList.at(i).check(u, p))
            {
                this->currentUser = User(u, p);
                return true;
            }
        }
        
        return false;
        
        
    }

 /*private:
    // These are only suggestions, not required helper functions.
    // Feel free to make your own private helper functions as you see fit.
    void display() const;
    void addMessage();
    bool userExists(const string &, const string &) const;
};*/