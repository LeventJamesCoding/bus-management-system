#include "BusFleetManager.h"
#include <algorithm>

BusFleetManager::BusFleetManager(vector<Bus>& busList) : BaseManager(busList) {}

bool BusFleetManager::addNewBus(int no, std::string plate, std::string driver) {
    if (isBusExists(no)) {
        return false; 
    }
    Bus newBus(no, plate, driver, "10:00", 50, "IST", "ANK", 450);
    buses.emplace_back(newBus);
    
    return true; 
}

bool BusFleetManager::removeBusByNumber(int no) {
    if (!isBusExists(no)) {
        return false; 
    }
    auto it = remove_if(buses.begin(), buses.end(),
        [no](const Bus& b) { return b.getBusNumber() == no;});

    if (it != buses.end()) {
        buses.erase(it, buses.end());
        return true;
    }
    
    return false;
}

const std::vector<Bus>& BusFleetManager::getAllBuses() const {
    return buses; 
}

bool BusFleetManager::isBusExists(int no) const {
    for(const auto& bus : buses){
        if (bus.getBusNumber() == no){
            return true;
        }
    }
    return false;
}

void BusFleetManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename); 
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for saving.\n";
        return;
    }

    for (const auto& bus : buses) {
        file << bus.getBusNumber() << "|" 
             << bus.getPlateNumber() << "|" 
             << bus.getDriverName() << "\n";
    }
    
    file.close();
    std::cout << "Data saved to " << filename << "\n";
}

void BusFleetManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename); 
    if (!file.is_open()) {
        return;
    }
    buses.clear(); 
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> parts;

        while (std::getline(ss, segment, '|')) {
            parts.push_back(segment);
        }

        if (parts.size() >= 3) {
            int id = std::stoi(parts[0]);
            std::string plate = parts[1];
            std::string driver = parts[2];

            Bus b(id, plate, driver, "10:00", 50, "IST", "ANK", 450);
            buses.push_back(b);
        }
    }
    file.close();
    std::cout << "Data loaded from " << filename << "\n";
}