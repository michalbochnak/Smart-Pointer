//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
// April 23, 2018
//


#include "Node.h"


Node::Node(int _id, Appliance* _appliancePtr, Node* _next) {
    this->id = _id;
    this->appliancePtr.setAppliancePtr(_appliancePtr);
    this->appliancePtr.setId(id);
    this->next = _next;
}

Node::~Node() {

}


int Node::getId() {
    return this->id;
}

Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node* _next) {
   this->next = _next;
}

AppliancePtr& Node::getAppliancePtr () {
    return this->appliancePtr;
}