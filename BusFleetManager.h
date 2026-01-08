#pragma once
#include "BaseManager.h"
#include <string>
#include <vector>

class BusFleetManager : public BaseManager {
public:
    BusFleetManager(vector<Bus>& busList);

    bool addNewBus(int no, std::string plate, std::string driver);
    bool removeBusByNumber(int no);
    const std::vector<Bus>& getAllBuses() const;
    bool isBusExists(int no) const;

    //operational functions for I/O.
    void saveToFile(const string& fileName);
    void loadFromFile(const string& fileName);
};