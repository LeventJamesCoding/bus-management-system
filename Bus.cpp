#include "Bus.h"
#include <sstream>
#include <iomanip>

// Constructor güncellendi
Bus::Bus(int no, const string& plate, const string& driver, 
         const string& depTime, const string& arrTime,
         int fr, const string& dep, const string& arr, int dist)
    : busNumber(no), licensePlate(plate), driverName(driver),
    routeInfo(dep, arr, dist), departureTime(depTime), arrivalTime(arrTime), fare(fr) {
    seats.resize(capacity, "EMPTY");
}

void Bus::displayBusInfo() const {
    cout << left << setw(8) << busNumber
        << setw(15) << licensePlate
        << setw(20) << driverName
        << setw(15) << routeInfo.getDeparture() 
        << setw(15) << routeInfo.getArrival()   
        << setw(10) << departureTime            
        << setw(10) << arrivalTime              // YENİ SÜTUN
        << setw(10) << getFare()
        << countEmptySeats() << "/" << capacity << endl;
}

void Bus::displaySeatLayout() const {
    cout << "\n--- Seat Status (Bus No: " << busNumber << ") ---" << endl;
}

int Bus::countEmptySeats() const {
    return std::count(seats.begin(), seats.end(), "EMPTY");
}

bool Bus::reserveSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > capacity) return false;
    return seats[seatNumber - 1] == "EMPTY";
}

bool Bus::reserveSeat(int seatNumber, const string& passengerName) {
    if (!reserveSeat(seatNumber)) {
        return false;
    }
    seats[seatNumber - 1] = passengerName;
    return true;
}

string Bus::toSaveString() const {
    stringstream ss;
    // Format: ID|Plate|Driver|DepTime|ArrTime|Fare|Origin|Dest|Dist|Seats...
    ss << busNumber << "|" << licensePlate << "|" << driverName << "|"
       << departureTime << "|" << arrivalTime << "|" << fare << "|" 
       << routeInfo.getDeparture() << "|" << routeInfo.getArrival() << "|" << routeInfo.getDistance();
       
    for (const auto& seat : seats) { ss << "|" << seat; }
    return ss.str();
}