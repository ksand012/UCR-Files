#include "Connector.h"

Connector::Connector(Base* lefty, Base* righty) {
    this->lefty = lefty;
    this->righty = righty;
}

Connector::Connector()  {
    this->lefty = NULL;
    this->righty = NULL;
}