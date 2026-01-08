#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Bus.h"

using namespace std;

class BaseManager {
protected:
    vector<Bus>& buses;
    const string FILE_NAME = "bus_data.txt";

    void saveBusData();
    void loadBusData();

public:
    BaseManager(vector<Bus>& busList);
    virtual ~BaseManager();

    virtual void displayAllData() const;
    virtual void showSystemStatus() const;

    Bus* getBusByNumber(int no);
};