#include "Utilities.h"
#include <iomanip>

void displayMenu() {
    displayHeader("Bus Management System (Phase 1)");
    cout << "1. Add New Bus (Fleet Manager)" << endl;
    cout << "2. Make Reservation (Reservation Manager)" << endl;
    cout << "3. List All Buses (Fleet Manager View)" << endl;
    cout << "4. Display Seat Details (Reservation Manager)" << endl;
    cout << "5. Remove Bus (Fleet Manager)" << endl;
    cout << "0. Exit and Save" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void displayHeader(const string& title) {
    cout << "\n=============================================" << endl;
    cout << title << endl;
    cout << "=============================================" << endl;
}

void displayError(const string& message) {
    cerr << "--- ERROR: " << message << " ---" << endl;
}