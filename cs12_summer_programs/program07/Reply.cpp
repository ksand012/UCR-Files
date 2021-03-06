#include "Reply.h"
#include <sstream>

Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id):Message(athr, sbjct, body, id)
{
}

bool Reply::isReply() const
{
    return true;
}

string Reply::toFormattedString() const
{
    
    ostringstream converter;
    
    converter << "<begin_reply>\n:id: " << id << "\n:subject: " << subject << "\n:from: " << author << "\n";
    
    //ok, now need to make sure there's children.
    
    if(childList.size() != 0)//whoa, dude, you had a baby
    {
        converter << ":children: "; //implenting children string here
        
        //now we gotta add all the kiddies with a for loop
        
        for(size_t i = 0; i < childList.size(); i++)
        {
            if(i == childList.size() - 1)
            converter << childList.at(i) ->getID();
            else
            converter << childList.at(i) ->getID() << ' ';
        }
        converter << "\n";
    }
    
    converter << ":body: " << this->body;
    
    if(body.at(body.size()-1) != '\n')
    converter << "\n";
    
    converter << "<end>" << "\n";
    
    return converter.str();
}