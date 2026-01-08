#include "ReservationManager.h"
#include <limits> // for cin.ignore
#include "Utilities.h"

ReservationManager::ReservationManager(vector<Bus>& busList) : BaseManager(busList) {}

void ReservationManager::makeReservation() {
    int no, seat;
    string name;

    BaseManager::displayAllData(); 
    displayHeader("Make Reservation");
    cout << "Enter Bus Number: ";
    if (!(cin >> no)) { displayError("Invalid Bus Number input."); return; }

    Bus* bus = getBusByNumber(no); 
    if (bus == nullptr) {
        displayError("Bus " + to_string(no) + " not found.");
        return;
    }

    bus->displaySeatLayout();
    cout << "Passenger Name: "; cin.ignore(); getline(cin, name);
    cout << "Seat Number (1-" << bus->getCapacity() << "): ";
    if (!(cin >> seat)) { displayError("Invalid Seat input."); return; }

    if (bus->reserveSeat(seat, name)) {
        cout << "Success: Reservation confirmed for " << name << " on seat " << seat << "." << endl;
    }
    else {
        displayError("Seat " + to_string(seat) + " is already taken or invalid.");
    }
}

void ReservationManager::displaySeatDetails() {
    int no;
    displayHeader("Display Seat Details");
    cout << "Enter Bus Number: ";
    if (!(cin >> no)) { displayError("Invalid Bus Number input."); return; }

    Bus* bus = findBus(no); 

    if (bus) {
        bus->displaySeatLayout();
    }
    else {
        displayError("Bus " + to_string(no) + " not found.");
    }
}

Bus* ReservationManager::findBus(int no) {
    return getBusByNumber(no); 
}

vector<Bus*> ReservationManager::findBus(const string& dep, const string& arr) {
    vector<Bus*> results;
    for (auto& bus : buses) {
        if (bus.getRouteInfo().getDeparture() == dep &&
            bus.getRouteInfo().getArrival() == arr) {
            results.push_back(&bus);
        }
    }
    return results;
}

void ReservationManager::showAvailableRoutes() const {  }