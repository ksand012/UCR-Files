#include "Message.h"
#include "BBoard.h"
#include "User.h"
#include "Reply.h"
#include "Topic.h"
#include <fstream>

//includes

int main() {
    string userfile;
    string datafile;
    
    cout << "User file?" << endl;
    cin >> userfile;
    cout << endl;
 
    cout << "Message file?" << endl;
    cin >> datafile;
    cout << endl;

    BBoard bb("CS12 Bulletin Board");
   
    // load users from file
    if (!bb.loadUsers(userfile))
    {
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
   
    // load messages   
    if (!bb.loadMessages(datafile))
    {
        cout << "ERROR: Cannot load messages from " << datafile << endl;
        return 1;
    }
   
    bb.login();
    bb.run();

    // save messages
    if (!bb.saveMessages(datafile))
    {
        cout << "ERROR: Cannot save messages to " << datafile << endl;
        return 1;
    }

    return 0;
} 


