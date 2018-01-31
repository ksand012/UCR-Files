#include "BBoard.h"
#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"

#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

const string DASHES = "---------------------------------------------------------";

BBoard::BBoard() {
	title = "CS 12 Message Board";
	currentUser = 0;
}

BBoard::BBoard(const string &title) {
	this->title = title;
	currentUser = 0;
}

BBoard::~BBoard() {
	for (size_t i = 0; i < messageList.size(); ++i) {
		delete messageList.at(i);
	}
}

bool BBoard::loadUsers(const string &filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		return false;
	}

	string user, pass;
	while (file >> user >> pass) {
		userList.push_back(User(user, pass));
	}

	file.close();	
	return true;
}

bool BBoard::loadMessages(const string & savefile) {
	ifstream file(savefile);

	if (!file.is_open()) {
		return false;
	}

	string numString;
	getline(file, numString);
	int numMessages = Str2UInt(numString);
	vector<vector<int> > children(numMessages);

	for (int i = 0; i < numMessages; ++i) {
		
		string junk, endString;
		string messageType, idString, subjectString, bodyString, authorString, childString;
		unsigned idNum;
		int childLoc;

		//Gets Type
		getline(file, messageType);

		//Gets ID
		file >> junk >> idString >> junk;
		idNum = Str2UInt(idString);
		getline(file, junk, ' ');

		//Gets Author
		getline(file, subjectString);
		file >> junk >> authorString >> junk;

		//Checks and gets children to vector
		if (junk.at(1) == 'c') {
			getline(file, childString);
			istringstream inSS(childString);
			
			while (inSS >> childLoc) {
				children.at(i).push_back(childLoc);	
			}

			file >> junk;
		}

		//Gets Body
		getline(file, junk, ' ');
		getline(file, junk);

		while (junk != "<end>") {
			bodyString += junk + '\n';

			getline(file, junk);
		}
	
		if (messageType.at(7) == 'r') {
			messageList.push_back(new Reply(authorString, subjectString, bodyString, idNum));
			
		} else if (messageType.at(7) == 't') {
			messageList.push_back(new Topic(authorString, subjectString, bodyString, idNum));
		}
	}

	for (size_t i = 0; i < children.size(); ++i) {
		for (size_t j = 0; j < children.at(i).size(); ++j) {
			messageList.at(i)->addChild(messageList.at(children.at(i).at(j) - 1));
		}
	}

	file.close();

	return true;
}

bool BBoard::saveMessages(const string & savefile) {
	ofstream file(savefile);

	if (!file.is_open()) {
		return false;
	}

	file << messageList.size() << endl;
	
	for (unsigned i = 0; i < messageList.size(); ++i) {
		file << messageList.at(i)->toFormattedString();
	}

	file.close();
	return true;
}

bool BBoard::login() {
	string user, pass;

	cout << "Welcome to " << title << endl;
	do {
		
		cout <<	"Enter your username ('Q' or 'q' to quit): ";
		cin  >> user;
	
		if (tolower(user.at(0)) != 'q') {

			cout << "Enter your password: ";
			cin  >> pass;

			for (size_t i = 0; i < userList.size(); ++i) {
				if (userList.at(i).check(user, pass)) {
					currentUser = &userList.at(i);
				}
			}


			if (currentUser) {
				cout << endl << "Welcome back " << currentUser->getUsername() << '!' << endl << endl;
				return true;
			}
			

			cout << "Invalid Username or Password!" << endl << endl;
		}
	} while (tolower(user.at(0)) != 'q');

	cout << "Bye!" << endl;

	return false;
}

void BBoard::run() {

	string action;

	if (!currentUser) return;

	do {	

		cout << "Menu" << endl;
		cout << "- Display Messages ('D' or 'd')" << endl;
		cout << "- Add New Topic ('N' or 'n')" << endl;
		cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
		cout << "- Quit ('Q' or 'q')" << endl;
		cout << "Choose an action: "; 
		cin  >> action;

		if (tolower(action.at(0)) == 'd') {
			this->display();
		} else if (tolower(action.at(0)) == 'n') {
			this->addTopic();
		} else if (tolower(action.at(0)) == 'r') {
			this->addReply();
		} else if (tolower(action.at(0)) == 'q') {
			cout << "Bye!" << endl;
		}
	
	} while (tolower(action.at(0)) != 'q');
	return;
}

void BBoard::display() const {

	if (!messageList.size()) {
		cout << endl;
		cout << "Nothing to Display." << endl << endl;
		return;
	}

	cout << endl;
	for (size_t i = 0; i < messageList.size(); ++i) {
		
		if (!messageList.at(i)->isReply()) {
			if (i == 0) {
				cout << DASHES << endl;
			}
				
			this->messageList.at(i)->print(0);
		
			cout << DASHES << endl;
		}
	}
	cout << endl;
}

void BBoard::addReply() {
	string subject, body, junk;
	string author = currentUser->getUsername();

	int parentID = 0;

	cout << "Enter Message ID (-1 for Menu): ";
	cin >> parentID;

	if (parentID == -1) {
		return;
	}

	while (static_cast<unsigned>(parentID - 1) >= messageList.size()) {
		cout << "Invalid Message ID!!" << endl << endl;

		cout << "Enter Message ID (-1 for Menu): ";
		cin >> parentID;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;


	subject = messageList.at(parentID - 1)->getSubject();
	
	cout << "Enter Body: ";
	getline(cin, junk);

	while (junk != "") {
		body += junk + '\n';

		getline(cin, junk);
	}
	cout << endl;
	
	unsigned messageID = messageList.size() + 1;

	messageList.push_back(new Reply(author, "Re: " + subject, body, messageID));
	messageList.at(parentID - 1)->addChild(messageList.at(messageID - 1));	

	return;
}

void BBoard::addTopic() {
	string subject, body, junk;
	string author = currentUser->getUsername();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Subject: ";
	getline(cin, subject);

	cout << "Enter Body: ";
	getline(cin, junk);

	while (junk != "") {
		body += junk + '\n';

		getline(cin, junk);
	}
	cout << endl;

	unsigned messageID = messageList.size() + 1;

	messageList.push_back(new Topic(author, subject, body, messageID));

	return;
}

unsigned Str2UInt(string s) {
	istringstream inSS(s);
	unsigned num;
	inSS >> num;
	return num;
}
