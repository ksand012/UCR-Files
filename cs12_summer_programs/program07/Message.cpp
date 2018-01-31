#include "Message.h"

Message::Message()
{
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id)
{
    this->author = athr;
    this->subject = sbjct;
    this->body = body;
    this->id = id;
}

Message::~Message()
{
    //empty for now 'til I figure out what the hell is going on here
}

void Message::print(unsigned input) const
{
	string space = "";
	
	string tempBody = this->body;

	for(unsigned i = 0; i < input; i++)
	{
		space += " ";
	}
	for(unsigned i = 0; i < tempBody.size() - 1; i++)
	{
		if(tempBody.at(i) == '\n')
		{
			tempBody.insert(i + 1, space);
			i+= space.size();
		}
	}
	
	cout << space << "Message #" << id << ": " << subject << endl << space << "from " << author << ": " << tempBody;
	if(childList.size())
	cout << endl;
	for(size_t i = 0; i < childList.size(); i++)
	{
		childList.at(i)->print(input + 2);
		if(i != childList.size() - 1)
		cout << endl;
	}
	return;
}

const string & Message::getSubject() const
{
    return this->subject;
}

unsigned Message::getID() const
{
    return this->id;
}

void Message::addChild(Message* child)
{
    childList.push_back(child);
}

/*void Message::display() const
{
    cout << this->subject << endl << "from " << this->author << ": " << this->body;
}*/