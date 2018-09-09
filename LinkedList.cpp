//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
// April 23, 2018
//

#include "LinkedList.h"

//
// Create 10 nodes with appliance pointer pointing to NULL
//
LinkedList::LinkedList() {
    // create 10 empty nodes
    this->head = new Node(0, nullptr, nullptr);
    Node* curr = head;

    for (int i = 1; i <= 9; ++i) {
        curr->setNext(new Node(i, nullptr, nullptr));
        curr = curr->getNext();
    }
}

LinkedList::~LinkedList() {
    if (this->head != nullptr)
        this->recDelete(head);
}

//
// Recursively deallocates linked list
//
void LinkedList::recDelete(Node* node) {
    if (node->getNext()!= nullptr)
        this->recDelete(node->getNext());
    delete node;
}

//
// Display the linked listss
//
void LinkedList::display() {
    Node* curr = this->head;
    while (curr != nullptr) {
        cout << endl << endl;
        curr->getAppliancePtr()->displayInfo();
        curr = curr->getNext();
    }
}

//
// Returns the node that corresponds to the id from parameter
//
Node* LinkedList::getNodeById(int id) {

    Node* curr = this->head;
    while (curr != nullptr) {
        if (curr->getId() == id)
            return curr;
        curr = curr->getNext();
    }
}

void LinkedList::createAppliance(int id, int type, string man, double price,
                                          vector<string> paths) {

    getNodeById(id)->getAppliancePtr().createAppliance(id, type, man, price, paths);
}

//
// Saves all allocated appliances to the file
//
void LinkedList::saveAllToFile() {
    this->getNodeById(0)->getAppliancePtr().saveAllToFile();
}

//
// Displays the appliance for the given id
//
void LinkedList::displayApplianceAt(int id) {
    if (this->getNodeById(id)->getAppliancePtr().getAppliance(id) != nullptr)
        this->getNodeById(id)->getAppliancePtr().getAppliance(id)->displayInfo();
}

void LinkedList::allocateAppliance(int id) {
    this->getNodeById(id)->getAppliancePtr().allocate();
}

void LinkedList::setPrice(double newPrice, int id) {
    getNodeById(id)->getAppliancePtr()->setPrice(newPrice);
}