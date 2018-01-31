#include "BBoard.h"
#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>
#include <limits>

BBoard::BBoard()
{
    this->title = "CS12 Bulletin Board";
    //userList = "";
    currentUser = 0;
    //messageList = "";
}

BBoard::BBoard(const string & name)
{
    this->title = name;
    //userList = "";
    currentUser = 0;
    //messageList = "";
}

BBoard::~BBoard()
{
    for(unsigned i = 0; i < messageList.size(); i++)
    delete messageList.at(i); //i kill you ALL!!!!
    
}

bool BBoard::loadUsers(const string & fileName)
{
    ifstream inputFile;
   
   inputFile.open(fileName.c_str());
   string u;
   string p;
   
      if(!inputFile.is_open())
         return false;
    
      while(inputFile >> u >> p)
        userList.push_back(User(u, p));
      
     /* while(inputFile >> u >> p) {//!inputFile.eof()){
          
            userList.push_back(User(u, p));
         }*/
         
         inputFile.close();
         
         return true;
}

bool BBoard::loadMessages(const string & datafile)
{
    ifstream ipfile;
    ipfile.open(datafile.c_str());
    
    if (ipfile.fail())
        return false;
    
    string inputString = "";
    getline(ipfile, inputString);
    int messageCount = stringToInt(inputString);
    vector<vector<int> > tempChildren(messageCount);
    
    for(int i = 0; i < messageCount; i++)
    {
		
		string combining = "";
		string ending = "";
		string tOrR = "";
		string tempID = "";
		string sbjct = "";
		string bdy = "";
		string athr = "";
		string child = "";
		unsigned idNum;
		int locOfChild;

		getline(ipfile, tOrR);//type
		ipfile >> combining >> tempID >> combining;//id
		idNum = stringToInt(tempID); //id
		getline(ipfile, combining, ' '); //id
		getline(ipfile, sbjct);//auth
		ipfile >> combining >> athr >> combining;//auth

		//Checks and gets children to vector
		if (combining.at(1) == 'c')
		{
			getline(ipfile, child);
			istringstream inSS(child);
			
			while (inSS >> locOfChild)
			{
				tempChildren.at(i).push_back(locOfChild);
			}
			ipfile >> combining;
		}

		getline(ipfile, combining, ' ');
		getline(ipfile, combining);

		while (combining != "<end>")
		{
			bdy += combining + '\n';
			getline(ipfile, combining);
		}
	
		if (tOrR.at(7) == 'r') 
		{
			messageList.push_back(new Reply(athr, sbjct, bdy, idNum));
			
		}
		
		else if (tOrR.at(7) == 't')
		{
			messageList.push_back(new Topic(athr, sbjct, bdy, idNum));
		}
	}

	for (unsigned i = 0; i < tempChildren.size(); i++)
	{
		for (unsigned j = 0; j < tempChildren.at(i).size(); j++)
		{
			messageList.at(i)->addChild(messageList.at(tempChildren.at(i).at(j) - 1));
		}
	}

	ipfile.close();

	return true;
}

bool BBoard::saveMessages(const string &datafile)
{
    ofstream opfile;
    opfile.open( datafile.c_str() );
    
    if (!opfile.is_open())//if file can be accessed
    {
        return false;
    }
    
    opfile << messageList.size() << endl;
    
    for (unsigned i = 0; i < messageList.size(); i++)
    {
        opfile << messageList.at(i) -> toFormattedString();
    }   
    
    opfile.close(); //close
    return true;    //return true
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
        
        if(usertemp == "Q" || usertemp == "q")
        {
            cout << "Bye!" << endl;
            return false;
            
        }
        
        cout << "Enter your password: ";
        cin >> passtemp;
        //cout << endl;
       unsigned i = 0; 
       bool found = false;
        for(i = 0; i < userList.size(); i++)
        {
            if(userList.at(i).check(usertemp, passtemp))
            {
                found = true;
                currentUser = &userList.at(i);
                break;
            }
            
        }
        
        if(found)
        {
            bool correct = currentUser->check(usertemp, passtemp);
            if(correct)
            {
                cout << endl << "Welcome back " << this->currentUser->getUsername() << "!";
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
    string bdy2 = "";
    if(this->currentUser->getUsername() == "") //If and only if there is a valid currentUser, enter the main loop
    exit(1);
    do
    {
        /*input = 'a';
        subct = "";
        bdy = "";
        bdy2 = "";*/
        cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl << "- Add New Topic ('N' or 'n')" << endl << "- Add Reply to a Topic ('R' or 'r')" << endl << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
        cin >> input;
        /*if(input != 'Q' || input != 'q')
        {
            //cin.ignore();
            cout << endl;
        }*/
        
        if(input == 'D' || input == 'd')
        {
            if(!messageList.size())
            {
                cout << endl << "Nothing to Display." << endl << endl;
            }
            else
            {
                cout << endl;
                for (unsigned i = 0; i < messageList.size(); i++)
                {
            
                    if ( !(messageList.at(i) -> isReply()) )
                    {
                        if(i == 0)
                        cout << "---------------------------------------------------------" << endl;
                        this->messageList.at(i) -> print(0);
                        
                        cout << "---------------------------------------------------------" << endl;
                    }
                }
        
        cout << endl;
                
            //     for(unsigned i = 0; i < messageList.size(); i++)
            //     {
            //         cout << "---------------------------------------------------------\nMessage #" << (i+1) << ": ";
            //         messageList.at(i)->display();
            //         cout << endl;
            //     }
            //     cout <<  "---------------------------------------------------------" << endl << endl;
            // }
        }
        }
        else if(input == 'N' || input == 'n')
        {
            string tempSub = "";
            string tempBdy = "";
            string tempComb = "";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Subject: ";
            getline(cin, tempSub);
            //cout << endl;
            cout << "Enter Body: ";
            getline(cin, tempComb);
            
            while(tempComb != "")
            {
                tempBdy += tempComb + "\n";
                getline(cin, tempComb);
            }
            cout << endl;
            bdy = bdy.substr(0, bdy.size()-1);
            
            string findUser = this->currentUser->getUsername();
    
            //Topic* createdTopic = new Topic(findUser, tempSub, tempBdy, messageList.size() + 1);
            messageList.push_back(new Topic(findUser, tempSub, tempBdy, messageList.size() + 1));
            /*
            getline(cin, bdy);
            cout << endl;
            messageList.push_back(Message(currentUser.getUsername(), subct, bdy));
            cout << "Message Recorded!";
            cout << endl << endl;
            */
        }
        
        else if(input == 'R' || input == 'r')
        {
            addReply();
        }
        
        else if(input == 'Q' || input == 'q')
        done = true;
        else
        cout << "Invalid action. Please try again." << endl << endl;
        
    }while(!done);
    cout << "Bye!" << endl;
    exit(0);
}

void BBoard::addUser( const string &name, const string &pass )
{
    userList.push_back( User(name,pass) );
}


const User* BBoard::getUser(const string& name, const string& pw) const
{
    for (unsigned i = 0; i < this->userList.size(); i++)
    {
        if (userList.at(i).check(name, pw))
        {
            return &userList.at(i);
        }
    }
    
    return 0;
}

void BBoard::addReply()
{
    string tempSub = "";
    string tempBdy = "";
    string tempComb = "";
    //bool doneYet = false;
    string typing = "";
    int temp = 0;
    
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> temp;
        
        if (temp == -1)
        {
            return;  //back to menu you go
        }
            
        while(static_cast<unsigned>(temp-1) >= messageList.size())
        {
            cout << "Invalid Message ID!!" << endl << endl;
            cout << "Enter Message ID (-1 for Menu): ";
            cin >> temp;
        }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    tempSub = "Re: " + messageList.at( temp - 1 ) -> getSubject();
    cout << "Enter Body: ";
    getline(cin, typing);
    
    
     while(typing != "")
     {
        tempBdy += typing + "\n";
        getline(cin, typing);
    }
    cout << endl;
    
    //bdy += bdy.substr(0, bdy.size()-1);
    
    string getUser = this->currentUser->getUsername();
    Reply* newReply = new Reply(getUser, tempSub, tempBdy, messageList.size()+1);
    messageList.push_back(newReply);
    messageList.at(temp - 1) -> addChild(messageList.at(messageList.size()));
    
    return;
    
}

unsigned BBoard::stringToInt(string input)
{
	istringstream inSS(input);
	unsigned temp;
	inSS >> temp;
	return temp;    
    
}