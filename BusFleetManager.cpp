#include "BusFleetManager.h"
#include "Utilities.h" 
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>

struct SimBus {
    int id;
    int readyAtMinute; 
    string currentLocation; 
};

struct RouteDef {
    string origin;
    string dest;
    int duration;
    int fare;
    int dist;
};

BusFleetManager::BusFleetManager(vector<Bus>& busList) : BaseManager(busList) {
    
}

BusFleetManager::BusFleetManager(){

}

bool BusFleetManager::addNewBus(int no, std::string plate, std::string driver) {
    if (isBusExists(no)) return false;
    Bus newBus(no, plate, driver, "00:00", "00:00", 100, "Unknown", "Unknown", 0);
    buses.emplace_back(newBus);
    return true;
}

bool BusFleetManager::removeBusByNumber(int no) {
    if (!isBusExists(no)) return false;
    auto it = std::remove_if(buses.begin(), buses.end(),
        [no](const Bus& b) { return b.getBusNumber() == no; });
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
    for (const auto& bus : buses) {
        if (bus.getBusNumber() == no) return true;
    }
    return false;
}

void BusFleetManager::generateDailySchedule() {
    if (!buses.empty()) return;

    cout << "Initializing System: Simulating Daily Schedule (07:00 - 00:00)...\n";
    cout << "Routes: Corlu-Kadikoy (150m), Corlu-Beylikduzu (70m), Silivri-Kadikoy (90m)\n";

    RouteDef routes[] = {
        {"Corlu", "Kadikoy", 150, 200, 120},
        {"Corlu", "Beylikduzu", 70, 120, 80},
        {"Silivri", "Kadikoy", 90, 150, 90}
    };

    int routeBusCounts[3] = {0, 0, 0};

    map<string, queue<SimBus>> busPools;
    static vector<pair<int, pair<string, int>>> transitList;

    int currentMins = timeToMinutes("07:00");
    int endMins = timeToMinutes("23:59");
    int nextBusId = 100;

    while (currentMins <= endMins) {
        
        // Gelenleri havuza aktar
        for (auto it = transitList.begin(); it != transitList.end(); ) {
            if (it->first <= currentMins) {
                busPools[it->second.first].push({it->second.second, it->first, ""});
                it = transitList.erase(it);
            } else {
                ++it;
            }
        }

        // Seferleri Başlat
        for (int r = 0; r < 3; r++) {
            RouteDef& rt = routes[r];
            string routeId = to_string(r);
            string ways[2][2] = { {rt.origin, rt.dest}, {rt.dest, rt.origin} };

            for (int w = 0; w < 2; w++) {
                string from = ways[w][0];
                string to = ways[w][1];
                string poolKey = routeId + "_" + from;
                string targetPoolKey = routeId + "_" + to;

                int busIDToUse;
                string busDriver;

                if (busPools[poolKey].empty()) {
                    busIDToUse = nextBusId++;
                    busDriver = "Driver " + to_string(busIDToUse);
                    routeBusCounts[r]++; 
                } else {
                    SimBus sb = busPools[poolKey].front();
                    busPools[poolKey].pop();
                    busIDToUse = sb.id;
                    busDriver = "Driver " + to_string(sb.id);
                }

                string depTimeStr = minutesToTime(currentMins);
                string arrTimeStr = addMinutesToTime(depTimeStr, rt.duration);
                int arrivalMins = currentMins + rt.duration;
                int readyMins = arrivalMins + 30; // Mola

                transitList.push_back({readyMins, {targetPoolKey, busIDToUse}});

                string platePrefix = (r==0 ? "34CK" : (r==1 ? "34CB" : "34SK"));
                Bus b(busIDToUse, platePrefix + to_string(busIDToUse), busDriver,
                      depTimeStr, arrTimeStr, rt.fare, from, to, rt.dist);
                buses.push_back(b);
            }
        }
        currentMins += 30;
    }

    cout << "Daily schedule generated. Total Trips: " << buses.size() << "\n";
    cout << "Total Physical Buses Used: " << (nextBusId - 100) << "\n";
    
    cout << "---------------------------------------------\n";
    cout << "Bus Breakdown by Route:\n";
    cout << "1. Corlu-Kadikoy (150m): " << routeBusCounts[0] << " buses\n";
    cout << "2. Corlu-Beylikduzu (70m): " << routeBusCounts[1] << " buses\n";
    cout << "3. Silivri-Kadikoy (90m): " << routeBusCounts[2] << " buses\n";
    cout << "---------------------------------------------\n";
    
    saveToFile("buses.txt");
}

void BusFleetManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& bus : buses) {
        file << bus.toSaveString() << "\n";
    }
    file.close();
    std::cout << "Data saved to " << filename << "\n";
}

void BusFleetManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) {
        generateDailySchedule();
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

        if (parts.size() >= 9) { 
            int id = std::stoi(parts[0]);
            string plate = parts[1];
            string driver = parts[2];
            string depTime = parts[3];
            string arrTime = parts[4]; 
            int fare = std::stoi(parts[5]);
            string start = parts[6];
            string end = parts[7];
            int dist = std::stoi(parts[8]);

            Bus b(id, plate, driver, depTime, arrTime, fare, start, end, dist);

            for (size_t i = 9; i < parts.size(); ++i) {
                if (parts[i] != "EMPTY") {
                    b.reserveSeat(i - 8, parts[i]);
                }
            }
            buses.push_back(b);
        }
    }
    file.close();
    std::cout << "Data loaded from " << filename << "\n";
}

Trip* BusFleetManager::getTripById(const std::string& id) {
    for (size_t i = 0; i < allTrips.size(); i++) {
        if (allTrips[i].tripId == id) {
            return &allTrips[i]; 
        }
    }
    return nullptr;
}

void BusFleetManager::addTrip(const Trip& trip){
    allTrips.push_back(trip);
}