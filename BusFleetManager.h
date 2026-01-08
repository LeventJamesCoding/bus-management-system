#pragma once
#include "BaseManager.h"
#include <string>
#include <vector>

struct Trip {
    std::string tripId;
    std::string startLocation;
    std::string endLocation;
    std::string departureTime;
    std::string busPlate;
    int maxCapacity;
};

class BusFleetManager : public BaseManager {
    std::vector<Trip> allTrips;
public:
    BusFleetManager(vector<Bus>& busList);
    BusFleetManager();

    bool addNewBus(int no, std::string plate, std::string driver);
    bool removeBusByNumber(int no);
    const std::vector<Bus>& getAllBuses() const;
    bool isBusExists(int no) const;

    //operational functions for I/O.
    void saveToFile(const string& fileName);
    void loadFromFile(const string& fileName);
    
    void generateDailySchedule();
    Trip* getTripById(const std::string& id);

    void addTrip(const Trip& trip);
};