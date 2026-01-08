#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Route.h"

using namespace std;

class Bus {
private:
    int busNumber;
    string licensePlate;
    string driverName;
    int capacity = 32;

    Route routeInfo; 
    string departureTime;
    int fare;
    vector<string> seats;

public:
    Bus(int no = 0, const string& plate = "N/A", const string& driver = "N/A",
        const string& depTime = "N/A", int fr = 0,
        const string& dep = "", const string& arr = "", int dist = 0);

    // Getters
    int getBusNumber() const { return busNumber; }
    string getLicensePlate() const { return licensePlate; }
    string getDriverName() const { return driverName; }
    int getCapacity() const { return capacity; }
    int getFare() const { return fare; }
    const Route& getRouteInfo() const { return routeInfo; }
    const vector<string>& getSeats() const { return seats; }

    void displayBusInfo() const;
    void displaySeatLayout() const;
    int countEmptySeats() const;

    bool reserveSeat(int seatNumber);

    bool reserveSeat(int seatNumber, const string& passengerName);

    string toSaveString() const;
};