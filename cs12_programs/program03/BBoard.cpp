#include "BBoard.h"
#include "Message.h"
#include "User.h"
#include <fstream>

BBoard::BBoard()
{
    this->title = "CS12 Bulletin Board";
    //userList = "";
    currentUser = User();
    //messageList = "";
}

BBoard::BBoard(const string & name)
{
    this->title = name;
    //userList = "";
    currentUser = User();
    //messageList = "";
}

bool BBoard::loadUsers(const string & fileName)
{
    ifstream inputFile;
   
   inputFile.open(fileName.c_str());
   string u;
   string p;
   
      if(!inputFile.is_open()) {
         return false;
      }
      
      inputFile >> u;
    
      while(u != "end")
      {
        inputFile >> p;
        
        userList.push_back(User(u, p));
        
        inputFile >> u;
      }
      
     /* while(inputFile >> u >> p) {//!inputFile.eof()){
          
            userList.push_back(User(u, p));
         }*/
         
         inputFile.close();
         
         return true;
}

bool BBoard::login()
{
    string usertemp;
    string passtemp;
    bool loginWorked = false;
    cout << "Welcome to " << this->title << endl;
    do
    {
    
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> usertemp;
        cout << endl;
        
        if(usertemp == "Q" || usertemp == "q")
        {
            cout << "Bye!" << endl;
            return false;
            
        }
        
        cout << "Enter your password: ";
        cin >> passtemp;
        cout << endl;
       unsigned i = 0; 
       bool found = false;
        for(i = 0; i < userList.size(); i++)
        {
            if(usertemp == userList.at(i).getUsername())
            {
                found = true;
                currentUser = userList.at(i);
                break;
            }
            
        }
        
        if(found)
        {
            bool correct = currentUser.check(usertemp, passtemp);
            if(correct)
            {
                cout << "Welcome back " << currentUser.getUsername() << "!";
                cout << endl;
                cout << endl;
                loginWorked = true;
            }
            else
            {
                cout << "Invalid Username or Password!";
                cout << endl;
                cout << endl;
                loginWorked = false;
            }
        }
        else
        {
            cout << "Invalid Username or Password!";
            cout << endl;
            cout << endl;
            loginWorked = false;
        }
    }while(!loginWorked);
    
    return true;
}

void BBoard::run()
{
    bool done = false;
    char input = 'a';
    string subct = "";
    string bdy = "";
    
    do
    {
        cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Message ('N' or 'n')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
        cin >> input;
        cin.ignore();
        cout << endl;
        
        if(input == 'D' || input == 'd')
        {
            if(messageList.size() < 1)
            {
                cout << "Nothing to Display." << endl << endl;
            }
            else
            {
                for(unsigned i = 0; i < messageList.size(); i++)
                {
                    cout << "---------------------------------------------------------\nMessage #" << (i+1) << ": ";
                    messageList.at(i).display();
                    cout << endl;
                }
                cout <<  "---------------------------------------------------------" << endl << endl;
            }
        }
        else if(input == 'N' || input == 'n')
        {
            cout << "Enter Subject: ";
            getline(cin, subct);
            cout << endl;
            cout << "Enter Body: ";
            getline(cin, bdy);
            cout << endl;
            messageList.push_back(Message(currentUser.getUsername(), subct, bdy));
            cout << "Message Recorded!";
            cout << endl << endl;
        }
        else if(input == 'Q' || input == 'q')
        done = true;
        else
        cout << endl;
        
    }while(!done);
    cout << "Bye!" << endl;
    exit(0);
}