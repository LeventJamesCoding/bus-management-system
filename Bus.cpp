#include "Bus.h"
#include <sstream>
#include <iomanip>

int Bus::totalBusCount = 0;

Bus::Bus(int no, const string& plate, const string& driver, 
         const string& depTime, const string& arrTime,
         int fr, const string& dep, const string& arr, int dist)
    : busNumber(no), licensePlate(plate), driverName(driver),
    routeInfo(dep, arr, dist), departureTime(depTime), arrivalTime(arrTime), fare(fr) {
    
    seats.resize(capacity, "EMPTY");
    
    totalBusCount++;
}

Bus::Bus(const Bus& other)
    : busNumber(other.busNumber), licensePlate(other.licensePlate), 
      driverName(other.driverName), capacity(other.capacity),
      routeInfo(other.routeInfo), departureTime(other.departureTime), 
      arrivalTime(other.arrivalTime), fare(other.fare), seats(other.seats) {
    totalBusCount++;
}

Bus::~Bus() {
    totalBusCount--;
}

void Bus::displayBusInfo() const {
    cout << left << setw(8) << busNumber
        << setw(15) << licensePlate
        << setw(20) << driverName
        << setw(15) << routeInfo.getDeparture() 
        << setw(15) << routeInfo.getArrival()   
        << setw(10) << departureTime            
        << setw(10) << arrivalTime
        << setw(10) << getFare()
        << countEmptySeats() << "/" << capacity << endl;
}

void Bus::displaySeatLayout() const {
    cout << "\n--- Seat Status (Bus No: " << busNumber << ") ---" << endl;
    for (size_t i = 0; i < seats.size(); ++i) {
        cout << "Seat " << (i + 1) << ": " << seats[i] << "\n";
    }
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
    ss << busNumber << "|" << licensePlate << "|" << driverName << "|"
       << departureTime << "|" << arrivalTime << "|" << fare << "|" 
       << routeInfo.getDeparture() << "|" << routeInfo.getArrival() << "|" << routeInfo.getDistance();
       
    for (const auto& seat : seats) { ss << "|" << seat; }
    return ss.str();
}

bool Bus::operator==(const Bus& other) const {
    return this->licensePlate == other.licensePlate;
}

ostream& operator<<(ostream& os, const Bus& bus) {
    os << "------------------------------------------\n"
       << " [BUS CARD] \n"
       << " Bus No:   " << bus.busNumber << "\n"
       << " Plate:    " << bus.licensePlate << "\n"
       << " Driver:   " << bus.driverName << "\n"
       << " Route:    " << bus.routeInfo.getDeparture() << " -> " << bus.routeInfo.getArrival() << "\n"
       << " Schedule: " << bus.departureTime << " - " << bus.arrivalTime << "\n"
       << " Seats:    " << bus.countEmptySeats() << " empty / " << bus.capacity << " total\n"
       << "------------------------------------------";
    return os;
}