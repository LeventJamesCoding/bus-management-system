#include "BusFleetManager.h"
#include <algorithm>
#include "Utilities.h"

BusFleetManager::BusFleetManager(vector<Bus>& busList) : BaseManager(busList) {}

void BusFleetManager::addNewBus() {
    int no, fare, dist;
    string plate, driver, depTime, dep, arr;

    displayHeader("Add New Bus");
    cout << "Bus Number: "; cin >> no;

    if (getBusByNumber(no) != nullptr) {
        displayError("Bus number " + to_string(no) + " already exists.");
        return;
    }

    cout << "License Plate (e.g., TR34): "; cin >> plate;
    cout << "Driver Name: "; cin.ignore(); getline(cin, driver);

    Bus newBus(no, plate, driver, "10:00", 50, "IST", "ANK", 450);
    buses.emplace_back(newBus);
    cout << "Bus " << no << " successfully added to the fleet." << endl;
}

void BusFleetManager::removeBusByNumber(int no) {
    displayHeader("Remove Bus");
    Bus* busToRemove = getBusByNumber(no);

    if (busToRemove == nullptr) {
        displayError("Bus " + to_string(no) + " not found.");
        return;
    }

    auto it = std::remove_if(buses.begin(), buses.end(),
        [no](const Bus& b) { return b.getBusNumber() == no; });
    buses.erase(it, buses.end());
    cout << "Bus " << no << " removed from the fleet." << endl;
}

void BusFleetManager::updateBusDetails(int no) {  }
void BusFleetManager::checkBusExists(int no) const {  }

void BusFleetManager::displayAllData() const {
    displayHeader("BUS FLEET MANAGER VIEW");
    BaseManager::displayAllData(); 
}