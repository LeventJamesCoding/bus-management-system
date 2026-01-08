#include "Utilities.h"
#include <iomanip>
#include <sstream>

using namespace std;

void displayHeader(const string& title) {
    cout << "\n=============================================\n";
    cout << title << "\n";
    cout << "=============================================\n";
}

void displayError(const string& message) {
    cout << "\n--- ERROR: " << message << " ---\n";
}

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

int timeToMinutes(const string& timeStr) {
    int h, m;
    char colon;
    stringstream ss(timeStr);
    ss >> h >> colon >> m;
    return h * 60 + m;
}

string minutesToTime(int totalMinutes) {
    int h = (totalMinutes / 60) % 24;
    int m = totalMinutes % 60;
    stringstream ss;
    ss << setfill('0') << setw(2) << h << ":" 
       << setfill('0') << setw(2) << m;
    return ss.str();
}

string addMinutesToTime(const string& timeStr, int minutesToAdd) {
    int currentMins = timeToMinutes(timeStr);
    return minutesToTime(currentMins + minutesToAdd);
}