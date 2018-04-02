#include "Connector.h"

Connector::Connector(Base* lhs, Base* rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

Connector::Connector()  {
    this->lhs = NULL;
    this->rhs = NULL;
}
/*string Connector::get_data() {
    return "error called get data on connector";
}*/
