//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
// April 23, 2018
//


#ifndef CS_474_PROJECT_03_SMART_POINTER_APPLIANCEPTR_H
#define CS_474_PROJECT_03_SMART_POINTER_APPLIANCEPTR_H


#include <iostream>
#include <fstream>
#include "Appliance.h"
using namespace std;


//
// Smart Pointer class. Class have pointer to appliance and makes
// sure there is no more than 3 instances of the appliance currently
// allocated in the memory. The rest is stored inside of the files
// and loaded dynamically as needed. To keep track of the number
// of instances allocated class have static member variable which
// have data about which instances are currently allocated and which
// are not. That allows the class to deallocate instances if space
// is needed fo allocation of the new instance.
//
class AppliancePtr {

public:
    AppliancePtr();
    ~AppliancePtr();
    void saveAllToFile();
    Appliance& operator*();
    Appliance* operator->();
    void createAppliance(int id, int type, string man, double price,
                         vector<string>paths);
    Appliance* getAppliance(int _id);
    void setAppliancePtr(Appliance* applPtr);
    void allocate();
    void setId(int _id);

protected:
    AppliancePtr& operator=(const AppliancePtr& rhs);

private:
    int id;
    Appliance* appliance;
    static AppliancePtr* allocatedAppl[];
    void createApplianceInstanceFromFile(int id);
    void saveApplianceToFile(int id, int type, string man, double price,
                                           vector<string> paths);
    bool threeAllocated();
    void saveApplianceToFile(Appliance *appl);
};


#endif //CS_474_PROJECT_03_SMART_POINTER_APPLIANCEPTR_H
