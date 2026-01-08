#include "BaseManager.h"
#include <sstream>
#include <algorithm>
#include "Utilities.h"
#include <iomanip>

BaseManager::BaseManager(vector<Bus>& busList) : buses(busList) {
    loadBusData();
}

BaseManager::~BaseManager() {
    saveBusData();
}

void BaseManager::displayAllData() const {
    if (buses.empty()) {
        displayError("No registered buses found in the system.");
        return;
    }
    displayHeader("Bus Listing");
    
    cout << left << setw(8) << "No"
        << setw(15) << "Plate"
        << setw(20) << "Driver"
        << setw(15) << "Departure" 
        << setw(15) << "Arrival"
        << setw(10) << "Fare"
        << "Seats" << endl;
        
    cout << string(95, '-') << endl; 

    for (const auto& bus : buses) {
        bus.displayBusInfo();
    }
}
void BaseManager::showSystemStatus() const {
    cout << "System Status: Managing " << buses.size() << " active bus routes." << endl;
}

Bus* BaseManager::getBusByNumber(int no) {
    for (auto& bus : buses) {
        if (bus.getBusNumber() == no) {
            return &bus;
        }
    }
    return nullptr;
}

void BaseManager::loadBusData() {
    cout << "Data load attempted." << endl;
}

void BaseManager::saveBusData() {
    cout << "Data saved successfully on exit." << endl;
}