#pragma once
#include "BaseManager.h" 

class BusFleetManager : public BaseManager { 
public:
    BusFleetManager(vector<Bus>& busList);

    void addNewBus();
    void removeBusByNumber(int no);
    void updateBusDetails(int no);
    void checkBusExists(int no) const;
    void displayAllData() const override; 
};