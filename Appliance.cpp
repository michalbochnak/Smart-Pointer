//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
// April 23, 2018
//

#include <iostream>
#include "Appliance.h"
using namespace std;


Appliance::Appliance(int _id, int _type, string _man, double _price,
          vector<string> _paths) {
    this->id = _id;
    this->applType = _type;
    this->manufacturer = _man;
    this->price = _price;
    this->paths = _paths;
}

Appliance::~Appliance() {

}

void Appliance::displayInfo() {
    cout << "Id: " << id << endl;
    cout << "Type: " << generateApplianceType(applType) << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Price: $" << price << endl;
    cout << "Paths: ";
    for (string p : paths)
        cout << p << ", ";
}

void Appliance::setPrice(double newPrice) {
    this->price = newPrice;
}

string Appliance::generateApplianceType(int type) {
    switch(type) {
        case 0:
            return "LAUNDRY_MACHINE (0)";
        case 1:
            return "DISH_WASHER (1)";
        case 2:
            return "DRYER (2)";
    }
}