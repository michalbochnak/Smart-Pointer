//
// Michal Bochnak
// CS 474 Project 03
// Smart Pointer
//


#include <iostream>
#include "Appliance.h"
#include "LinkedList.h"
using namespace std;


void diplayHelp() {
    cout << "Commands available: " << endl;
    cout << "    l - list all appliances" << endl;
    cout << "    0...9 - edit an appliance" << endl;
    cout << "    c - create an appliance" << endl;
    cout << "    p - update price of an existing appliance" << endl;
    cout << "    s - save all appliance to files" << endl;
    cout << "    h - help" << endl;
    cout << "    q - quit program" << endl;
}

int getIdFromUser() {
    int id;
    while (true) {
        cout << "Enter id: ";
        cin >> id;
        if (id >= 0 && id <= 9)
            return id;

        cout << "Id must be between 0 - 9 inclusive." << endl;
    }
}

int getTypeFromUser() {
    int type;
    while (true) {
        cout << "Enter type: ";
        cin >> type;
        if (type >= 0 && type <= 2)
            break;

        cout << "Type must be 0, 1, or 2:" << endl;
        cout << "    0 - LAUNDRY_MACHINE\n"
                "    1 - DISH_WASHER\n"
                "    2 - DRYER" << endl;
    }

    switch (type) {
        case 0:
            return Appliance::applianceType::LAUNDRY_MACHINE;
        case 1:
            return Appliance::applianceType::DISH_WASHER;
        case 2:
            return Appliance::applianceType::DRYER;
    }
}

string getManufacturerFromUser() {
    string man;
    cout << "Enter manufacturer: ";
    cin >> man;
    return man;
}

double getPriceFromUser() {
    double price;
    while (true) {
        cout << "Enter price: ";
        cin >> price;
        if (price >= 0)
            return price;

        cout << "price must be positive number." << endl;
    }
}

vector<string>  getPathsFromUser() {
    vector<string> paths;
    string path;
    while (true) {
        cout << "Enter image path (enter 'd' when done): ";
        cin >> path;
        if (path == "d")
            return paths;
        paths.push_back(path);
    }
}

//
// Collect the specs from the user and creates new appliance
//
void createAppliance(LinkedList &appl) {
    int id, type;
    string man, path;
    double price;
    vector<string> paths;

    id = getIdFromUser();
    type= getTypeFromUser();
    man = getManufacturerFromUser();
    price = getPriceFromUser();
    paths = getPathsFromUser();

    appl.createAppliance(id, type, man, price, paths);
}

//
// Take new price from user and update the price for the
// appliance specified by parameter
//
void updatePrice(LinkedList &appl, int currApplianceIndex) {
    double newPrice = getPriceFromUser();
    appl.setPrice(newPrice, currApplianceIndex);
}

void displayAuthorInfo() {
    cout << "---------------------------" << endl;
    cout << " Michal Bochnak" << endl;
    cout << " CS 474, April 23, 2018" << endl;
    cout << " Smart pointer" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " Program dynamically allocates and deallocates objects" << endl;
    cout << " during runtime to save memory. Each object is saved" << endl;
    cout << " in the corresponding file and loaded by the Smart Pointer" << endl;
    cout << " class as needed during runtime. There is no more than 3" << endl;
    cout << " instances of the object allocated in the memory at any time." << endl;
    cout << "--------------------------------------------------------------" << endl;
}


//
// Main program loop to perform user requested operations
//
int main() {

    LinkedList appliances = LinkedList();
    char menuOption = 'a';
    int currApplianceIndex = 0;

    displayAuthorInfo();

    do {
        cout << endl << "Enter command ('h' for help): ";
        cin >> menuOption;

        // list all appliances
        if (menuOption == 'l') {
            appliances.display();
        }
        // change current working appliance id
        else if (menuOption == '0' || menuOption == '1' || menuOption == '2'
                || menuOption == '3' || menuOption == '4' || menuOption == '5'
                || menuOption == '6' || menuOption == '7' || menuOption == '8'
                || menuOption == '9') {

            currApplianceIndex = (int)menuOption - 48;
            appliances.allocateAppliance(currApplianceIndex);
        }
        // create new appliance
        else if (menuOption == 'c') {
            createAppliance(appliances);
        }
        // change price for the actual working appliance
        else if (menuOption == 'p') {
            updatePrice(appliances, currApplianceIndex);
            appliances.displayApplianceAt(currApplianceIndex);
        }
        // save all allocated appliances to the files
        else if (menuOption == 's') {
            appliances.saveAllToFile();
        }
        // display help
        else if (menuOption == 'h') {
            diplayHelp();
        }
        // wrong command
        else if (menuOption != 'q') {
            cout << " *** Invalid command. ***" << endl;
            diplayHelp();
        }

    } while (menuOption != 'q');

    // exiting program,
    // save appliances that are alocated to the files
    appliances.saveAllToFile();

    cout << endl << "-------" << endl;
    cout << "Done." << endl;
    cout << "-------" << endl << endl;

    return 0;
}
