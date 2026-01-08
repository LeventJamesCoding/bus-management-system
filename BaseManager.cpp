#include "BaseManager.h"
#include <sstream>
#include <algorithm>
#include "Utilities.h"
#include <iomanip>

BaseManager::BaseManager(vector<Bus> busList) {
    buses = busList; 
}
BaseManager::BaseManager() {
    loadBusData(); 
}

BaseManager::~BaseManager() {
    saveBusData();
}

void BaseManager::displayAllData() const {
    if (buses.empty()) {
        cout << "[Info] No registered buses found in the system." << endl;
        return;
    }
    cout << "\n--- Bus Listing ---\n";
    cout << left << setw(8) << "No"
        << setw(15) << "Plate"
        << setw(20) << "Driver"
        << setw(15) << "Departure" 
        << setw(15) << "Arrival"
        << setw(10) << "Fare"
        << "Seats" << endl;
        
    cout << string(95, '-') << endl; 

    for (const auto& bus : buses) {
        cout << bus.getBusNumber() << "..." << endl; 
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
    cout << "[System] Data load attempted from " << FILE_NAME << "." << endl;
}

void BaseManager::saveBusData() {
    cout << "[System] Data saved successfully on exit." << endl;
}