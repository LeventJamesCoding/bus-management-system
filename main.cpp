#include <iostream>
#include <vector>
#include <string>
#include "BusFleetManager.h"
#include "ReservationManager.h"

void printHeader(const std::string& title) {
    std::cout << "\n";
    std::cout << "======================================================\n";
    std::cout << "   " << title << "\n";
    std::cout << "======================================================\n";
}

int main() {
    BusFleetManager fleetMgr;
    ReservationManager resMgr;

    printHeader("BUS MANAGEMENT SYSTEM - FINAL DEMO");

    printHeader("STEP 1: Running Scheduling Algorithm");
    
    std::cout << "[System] Generating daily trips based on 30-min intervals...\n\n";
    fleetMgr.generateDailySchedule(); 

    printHeader("STEP 2: Integrating Schedule with Reservation System");

    std::cout << "[System] Converting generated schedule to reservable trips...\n";

    Trip autoTrip1;
    autoTrip1.tripId = "TRIP_0700_CK"; 
    autoTrip1.startLocation = "Corlu";
    autoTrip1.endLocation = "Kadikoy";
    autoTrip1.departureTime = "07:00";
    autoTrip1.busPlate = "34 CK 101"; 
    autoTrip1.maxCapacity = 40;

    Trip autoTrip2;
    autoTrip2.tripId = "TRIP_0730_CB"; 
    autoTrip2.startLocation = "Corlu";
    autoTrip2.endLocation = "Beylikduzu";
    autoTrip2.departureTime = "07:30";
    autoTrip2.busPlate = "34 CB 102"; 
    autoTrip2.maxCapacity = 30;

    fleetMgr.addTrip(autoTrip1);
    fleetMgr.addTrip(autoTrip2);

    std::cout << "[Info] Auto-generated trip registered: " << autoTrip1.tripId << " (" << autoTrip1.departureTime << ")\n";
    std::cout << "[Info] Auto-generated trip registered: " << autoTrip2.tripId << " (" << autoTrip2.departureTime << ")\n";

    printHeader("STEP 3: Live Reservation Test");

    std::cout << ">>> Test A: Reserving seat on Auto-Generated Trip (07:00)\n";
    Trip* targetTrip = fleetMgr.getTripById("TRIP_0700_CK");
    
    if (targetTrip) {
        resMgr.createReservation(500, targetTrip, 1);
        resMgr.createReservation(501, targetTrip, 2);
    }

    std::cout << "\n>>> Test B: Capacity Check on Auto-Generated Trip\n";
    resMgr.createReservation(999, targetTrip, 45);

    printHeader("STEP 4: Final System State");
    resMgr.displayAllReservations(fleetMgr);

    std::cout << "\n[System] Demo completed. System shutting down...\n";

    return 0;
}