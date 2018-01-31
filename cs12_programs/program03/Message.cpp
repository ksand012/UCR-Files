#include "Message.h"

Message::Message()
{
    this->author = "";
    this->subject = "";
    this->body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &body)
{
    this->author = athr;
    this->subject = sbjct;
    this->body = body;
}

void Message::display() const
{
    cout << this->subject << endl << "from " << this->author << ": " << this->body;
}