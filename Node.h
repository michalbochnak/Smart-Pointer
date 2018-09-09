//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
//


#ifndef CS_474_PROJECT_03_SMART_POINTER_NODE_H
#define CS_474_PROJECT_03_SMART_POINTER_NODE_H


#include "AppliancePtr.h"

//
// Node to be used in the LinkedList class
//
class Node {

    public:
        Node(int _id, Appliance* _appliancePtr, Node* _next);
        ~Node();
        int getId();
        Node* getNext();
        void setNext(Node* _next);
        AppliancePtr& getAppliancePtr();

    private:
        int id;
        AppliancePtr appliancePtr;
        Node* next;
};


#endif //CS_474_PROJECT_03_SMART_POINTER_NODE_H
