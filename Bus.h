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
    string arrivalTime;
    int fare;
    vector<string> seats;

public:
    // STATIC VARIABLE: Toplam otobüs sayısını takip eder
    static int totalBusCount;

    Bus(int no = 0, const string& plate = "N/A", const string& driver = "N/A",
        const string& depTime = "N/A", const string& arrTime = "N/A", 
        int fr = 0, const string& dep = "", const string& arr = "", int dist = 0);
    
    Bus(const Bus& other);
    // DESTRUCTOR: Otobüs silinince sayacı azaltmak için gerekli
    ~Bus();

    //getters
    int getBusNumber() const { return busNumber; }
    string getLicensePlate() const { return licensePlate; }
    string getDriverName() const { return driverName; }
    int getCapacity() const { return capacity; }
    int getFare() const { return fare; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    const Route& getRouteInfo() const { return routeInfo; }
    const vector<string>& getSeats() const { return seats; }

    void displayBusInfo() const;
    void displaySeatLayout() const;
    int countEmptySeats() const;

    bool reserveSeat(int seatNumber);
    bool reserveSeat(int seatNumber, const string& passengerName);

    string toSaveString() const;
    bool operator==(const Bus& other) const;
    friend ostream& operator<<(ostream& os, const Bus& bus);
};