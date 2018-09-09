//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
//

#ifndef CS_474_PROJECT_03_SMART_POINTER_LINKEDLIST_H
#define CS_474_PROJECT_03_SMART_POINTER_LINKEDLIST_H


#include "AppliancePtr.h"
#include "Node.h"


//
// Class to handle the implementation of the linked list
// and operations on it
//
class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    void display();
    void createAppliance(int id, int type, string man, double price,
                         vector<string>paths);
    Node* getNodeById(int id);
    void saveAllToFile();
    void displayApplianceAt(int id);
    void allocateAppliance(int id);
    void setPrice(double newPrice, int id);

private:
    Node *head;
    void recDelete(Node* node);
};


#endif //CS_474_PROJECT_03_SMART_POINTER_LINKEDLIST_H
