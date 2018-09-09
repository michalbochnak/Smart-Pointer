//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
// April 23, 2018
//


#ifndef CS_474_PROJECT_03_SMART_POINTER_APPLIANCE_H
#define CS_474_PROJECT_03_SMART_POINTER_APPLIANCE_H


#include <string>
#include <vector>

using namespace std;


//
// Class to encapsulate data for the appliance
//
class Appliance {
public:
    friend class AppliancePtr;
    enum applianceType {
        LAUNDRY_MACHINE,
        DISH_WASHER,
        DRYER
    };
    void displayInfo();
    void setPrice(double newPrice);

private:
    int id;
    int applType;
    double price;
    string manufacturer;
    vector<string> paths;
    Appliance(int _id, int _type, string _man, double _price,
              vector<string> _paths);
    ~Appliance();
    string generateApplianceType(int type);
};


#endif //CS_474_PROJECT_03_SMART_POINTER_APPLIANCE_H
