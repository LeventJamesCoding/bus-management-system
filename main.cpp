// #include <iostream>
// #include <vector>
// #include <string>
// #include "BusFleetManager.h"
// #include "ReservationManager.h"
// #include  "Bus.h"

// void printHeader(const std::string& title) {
//     std::cout << "\n";
//     std::cout << "======================================================\n";
//     std::cout << "   " << title << "\n";
//     std::cout << "======================================================\n";
// }

// int main() {
//     BusFleetManager fleetMgr;
//     ReservationManager resMgr;

//     printHeader("BUS MANAGEMENT SYSTEM");

//     printHeader("STEP 1: Running Scheduling Algorithm");
    
//     std::cout << "[System] Generating daily trips based on 30-min intervals...\n\n";
//     fleetMgr.generateDailySchedule(); 

//     printHeader("STEP 2: Integrating Schedule with Reservation System");

//     std::cout << "[System] Converting generated schedule to reservable trips...\n";

//     Trip autoTrip1;
//     autoTrip1.tripId = "TRIP_0700_CK"; 
//     autoTrip1.startLocation = "Corlu";
//     autoTrip1.endLocation = "Kadikoy";
//     autoTrip1.departureTime = "07:00";
//     autoTrip1.busPlate = "34 CK 101"; 
//     autoTrip1.maxCapacity = 40;

//     Trip autoTrip2;
//     autoTrip2.tripId = "TRIP_0730_CB"; 
//     autoTrip2.startLocation = "Corlu";
//     autoTrip2.endLocation = "Beylikduzu";
//     autoTrip2.departureTime = "07:30";
//     autoTrip2.busPlate = "34 CB 102"; 
//     autoTrip2.maxCapacity = 30;

//     fleetMgr.addTrip(autoTrip1);
//     fleetMgr.addTrip(autoTrip2);

//     std::cout << "[Info] Auto-generated trip registered: " << autoTrip1.tripId << " (" << autoTrip1.departureTime << ")\n";
//     std::cout << "[Info] Auto-generated trip registered: " << autoTrip2.tripId << " (" << autoTrip2.departureTime << ")\n";

//     printHeader("STEP 3: Live Reservation Test");

//     std::cout << ">>> Test A: Reserving seat on Auto-Generated Trip (07:00)\n";
//     Trip* targetTrip = fleetMgr.getTripById("TRIP_0700_CK");
    
//     if (targetTrip) {
//         resMgr.createReservation(500, targetTrip, 1);
//         resMgr.createReservation(501, targetTrip, 2);
//     }

//     std::cout << "\n>>> Test B: Capacity Check on Auto-Generated Trip\n";
//     resMgr.createReservation(999, targetTrip, 45);

//     printHeader("STEP 4: Final System State");
//     resMgr.displayAllReservations(fleetMgr);

//     std::cout << "\n[System] Demo completed. System shutting down...\n";

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include "BusFleetManager.h"
#include "ReservationManager.h"
#include "Bus.h" 
void printHeader(const std::string& title) {
    std::cout << "\n";
    std::cout << "======================================================\n";
    std::cout << "   " << title << "\n";
    std::cout << "======================================================\n";
}

int main() {
    BusFleetManager fleetMgr;
    ReservationManager resMgr;

    printHeader("BUS MANAGEMENT SYSTEM");

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

    printHeader("Live Reservation Test");

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

    printHeader("STEP 5: Technical Requirements Demo");

    // according to scheduling algorithm static variable totalBusCount calculated.
    std::cout << "[Static] Total Active Bus Objects in Memory: " << Bus::totalBusCount << "\n";
    
    // << operator overloaded
    std::cout << "\n[Operator<<] Printing a Bus object using overloaded operator:\n";
    const std::vector<Bus>& allBuses = fleetMgr.getAllBuses();
    if (!allBuses.empty()) {
        std::cout << allBuses[0] << "\n";
    }

    std::cout << "\n[Operator==] Comparing two temporary buses:\n";
    Bus b1(990, "34 TEST 1", "Ali", "10:00", "11:00", 100, "A", "B", 50);
    Bus b2(991, "34 TEST 1", "Veli", "12:00", "13:00", 100, "C", "D", 60); // same plates 
    Bus b3(992, "06 FARK 2", "Can",  "14:00", "15:00", 200, "X", "Y", 100); // different plates

    if (b1 == b2) std::cout << "-> b1 and b2 are equal (Same Plate).\n";
    else          std::cout << "-> b1 and b2 are different.\n";

    if (b1 == b3) std::cout << "-> b1 and b3 are equal.\n";
    else          std::cout << "-> b1 and b3 are different (Different Plate).\n";

    std::cout << "\n[Static] Updated Total Bus Count (after temp buses): " << Bus::totalBusCount << "\n";

    std::cout << "\n[System] Demo completed. System shutting down...\n";

    return 0;
}