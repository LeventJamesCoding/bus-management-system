// #include <iostream>
// #include "BusFleetManager.h"
// #include "ReservationManager.h"

// int main() {
    // BusFleetManager fleetMgr;
    // ReservationManager resMgr;

    // //mock data
    // Trip testTrip;
    // testTrip.tripId = "TRIP_34";
    // testTrip.startLocation = "Istanbul";
    // testTrip.endLocation = "Ankara";
    // testTrip.maxCapacity = 30; 
    
    // fleetMgr.addTrip(testTrip);
    // std::cout << ">> Test Seferi Eklendi: TRIP_34 (Kapasite: 30)\n\n";
    
    // // rezervation success
    // std::cout << "SC1\n";
    // Trip* trip = fleetMgr.getTripById("TRIP_34");
    
    // bool s1 = resMgr.createReservation(101, trip, 5); 
    // if(s1) std::cout << "Result: success as expected\n";
    // else   std::cout << "Result: unsuccessfull (error)\n";
    // std::cout << "\n";

    // // trying to reserve full seat
    // std::cout << "SC2 ---\n";
    // bool s2 = resMgr.createReservation(102, trip, 5);
    // if(!s2) std::cout << "Sonuc: ENGELLENDI (Beklenen: Dolu hatasi)\n";
    // else    std::cout << "Sonuc: BASARILI (Hata! Cakismanin engellenmesi lazimdi)\n";
    // std::cout << "\n";


    // // CAPACITY FULL
    // std::cout << "SC3\n";
    // // bus has a capacity of 30 but i want 35...
    // bool s3 = resMgr.createReservation(103, trip, 35);
    // if(!s3) std::cout << "Sonuc: ENGELLENDI (Beklenen: Kapasite hatasi)\n";
    // else    std::cout << "Sonuc: BASARILI (Hata! Kapasite asimina izin verildi)\n";
    // std::cout << "\n";


    // // INVALID TRIP ID
    // std::cout << "SC4\n";
    // Trip* invalidTrip = fleetMgr.getTripById("TRIP_9999");
    
    // bool s4 = resMgr.createReservation(104, invalidTrip, 10);
    // if(!s4) std::cout << "Result: BLOCKED (Expected trip could not found)\n";
    // else    std::cout << "Result: SUCCESS (Hata! Olmayan sefere rezervasyon yapildi)\n";
    // std::cout << "\n";



    // resMgr.displayAllReservations();

    // return 0;

#include <iostream>
#include "BusFleetManager.h"
#include "ReservationManager.h"

int main() {
    BusFleetManager fleetMgr;
    ReservationManager resMgr;

    Trip trip1;
    trip1.tripId = "TRIP_34";
    trip1.startLocation = "Istanbul";
    trip1.endLocation = "Ankara";
    trip1.maxCapacity = 30;
    
    Trip trip2;
    trip2.tripId = "TRIP_06";
    trip2.startLocation = "Ankara";
    trip2.endLocation = "Izmir";
    trip2.maxCapacity = 40;

    fleetMgr.addTrip(trip1);
    fleetMgr.addTrip(trip2);


    Trip* t1 = fleetMgr.getTripById("TRIP_34");
    resMgr.createReservation(101, t1, 5);

    Trip* t2 = fleetMgr.getTripById("TRIP_06");
    resMgr.createReservation(102, t2, 12);

    std::cout << "\n>>> Ayse (103) dolu koltuga (Trip_34, Seat 5) rezervasyon deniyor...\n";
    resMgr.createReservation(103, t1, 5);

    resMgr.displayAllReservations(fleetMgr);

    return 0;
}