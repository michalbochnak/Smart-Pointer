//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
// April 23, 2018
//

#include "AppliancePtr.h"

// Initialize static member for allocated instances
AppliancePtr* AppliancePtr::allocatedAppl[] = {nullptr, nullptr, nullptr};

AppliancePtr::AppliancePtr() {
    appliance = nullptr;
}

AppliancePtr::~AppliancePtr() {
    delete appliance;
}

Appliance& AppliancePtr::operator*() {
    if (this->appliance == nullptr)
        createApplianceInstanceFromFile(this->id);
    return *(this->appliance);
}

Appliance* AppliancePtr::operator->() {
    if (this->appliance == nullptr)
        createApplianceInstanceFromFile(this->id);
    return this->appliance;
}

void AppliancePtr::setId(int _id) {
    this->id = _id;
}

//
// Function allocates needed appliance based on the data from file.
// If there is currently 3 objects allocated it will save oldest one
// to the file and deallocate it. Then new object will be allocated
// using the same freed up.
//
void AppliancePtr::createApplianceInstanceFromFile(int id) {
    ifstream inFile;
    inFile.open("Appliances/" + to_string(id) + ".txt");
    if (!inFile) {
        cout << "Opening file Appliances/" + to_string(id)
                + ".txt" + "failed." << endl;
        exit(-1);
    }

    int _id = -1, _type = -1;
    string _man = "none", _tmp = "none";
    double _price = -1.0;
    vector<string> _paths;

    // get id
    inFile >> _id;
    // get type
    inFile >> _type;
    // get manufacturer
    inFile >> _man;
    // get price
    inFile >> _price;
    // get all paths
    while (inFile >> _tmp)
        _paths.push_back(_tmp);

    // clean old appliance in memory
    delete appliance;

    if (threeAllocated() == true) {
        // save oldest to file
        saveApplianceToFile((allocatedAppl[0])->appliance);
        // deallocate oldest AppliancePtr
        delete (allocatedAppl[0])->appliance;
        allocatedAppl[0]->appliance = nullptr;
    }

    // move over to prepare space for the new instance
    allocatedAppl[0] = allocatedAppl[1];
    allocatedAppl[1] = allocatedAppl[2];

    // allocate new applinace
    this->appliance = new Appliance(_id, _type, _man, _price, _paths);
    allocatedAppl[2] = this;
}

//
// Returns true if 3 instances are allocated,
// returns false if less than 3 instances are allocated
//
bool AppliancePtr::threeAllocated() {
    return allocatedAppl[0] != nullptr
        && allocatedAppl[1] != nullptr
            && allocatedAppl[2] != nullptr;
}

void AppliancePtr::setAppliancePtr(Appliance* applPtr) {
    this->appliance = applPtr;
}

Appliance* AppliancePtr::getAppliance(int _id) {
    if (this->appliance == nullptr) {
        createApplianceInstanceFromFile(_id);
    }
    return this->appliance;
}

//
// Creates new appliance based on the data received and saves it to the file
// and allocate in memory.
//
void AppliancePtr::createAppliance(int id, int type, string man, double price,
                     vector<string> paths) {

    // save appliance to file
    saveApplianceToFile(id, type, man, price, paths);

    if (appliance != nullptr) {
        appliance->id = id;
        appliance->applType = type;
        appliance->manufacturer = man;
        appliance->price = price;
        appliance->paths = paths;
    }
    else {
        createApplianceInstanceFromFile(id);
    }
}

void AppliancePtr::saveApplianceToFile(int id, int type, string man, double price,
                                       vector<string> paths) {

    // delete old file
    if (remove(("Appliances/" + to_string(id) + ".txt").c_str()) != 0) {
        cout << "Error deleting file";
    }
        // save to file
    else {
        ofstream myFile;
        myFile.open("Appliances/" + to_string(id) + ".txt");
        myFile << id << "\r\n" << type << "\r\n"  << man << "\r\n"  << price << "\r\n" ;
        for (string p : paths)
            myFile << p << "\r\n";
    }
}

//
// Saves all appliances that are currently allocated to the
// corresponding files.
//
void AppliancePtr::saveAllToFile() {
    for (int i = 0; i <= 2; ++i) {
        if (allocatedAppl[i] != nullptr)
            saveApplianceToFile(allocatedAppl[i]->appliance);
    }
}

//
// Allocates appliance if it is not currently in memory
//
void AppliancePtr::allocate() {
    if (appliance == nullptr) {
        // save oldest allocated to file
        if (allocatedAppl[0] != nullptr)
           saveApplianceToFile(allocatedAppl[0]->appliance);
        createApplianceInstanceFromFile(id);
    }
}

void AppliancePtr::saveApplianceToFile(Appliance *appl) {
    if (appl != nullptr) {
             saveApplianceToFile(appl->id, appl->applType, appl->manufacturer,
            appl->price, appl->paths);
    }
}
