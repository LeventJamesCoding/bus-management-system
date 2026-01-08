#pragma once
#include <string>
#include <iostream>

using namespace std;

class Route {
private:
    string departure;
    string arrival;
    int distanceKm;

public:
    Route(const string& dep = "Unknown", const string& arr = "Unknown", int dist = 0);

    void setDeparture(const string& dep);
    void setArrival(const string& arr);
    void setDistance(int dist) { distanceKm = dist; } 
    string getDeparture() const;
    string getArrival() const;
    int getDistance() const;

    double calculateEstimatedTime(int avgSpeedKmH = 80) const;
};