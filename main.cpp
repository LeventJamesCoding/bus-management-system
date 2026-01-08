#include <limits> 
#include <vector>
#include "Bus.h"
#include "BusFleetManager.h"
#include "ReservationManager.h"
#include "Utilities.h"

int main() {
    // vector<Bus> centralBusData;

    // BusFleetManager fleetManager(centralBusData);
    // ReservationManager reservationManager(centralBusData);
    // fleetManager.loadFromFile("buses.txt");

    // int choice;
    // do {
    //     displayMenu();

    //     if (!(cin >> choice)) {
    //         displayError("Invalid input! Please enter a number.");
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         choice = -1;
    //         continue;
    //     }

    //     switch (choice) {
    //     case 1: {
    //         int no;
    //         string plate, driver;
    //         cout << "Enter Bus Number: "; cin >> no;
    //         cout << "Enter Plate: "; cin >> plate;
    //         cout << "Enter Driver: "; cin >> driver;
    //         bool success = fleetManager.addNewBus(no, plate, driver);

    //         if(success){
    //             cout << "Bus added successfully";
    //             fleetManager.saveToFile("buses.txt");
    //         }
    //         else{
    //             cout << "Bus number already exists";
    //         }
    //         break;
    //     }
    //     case 2: reservationManager.makeReservation(); break;
    //     case 3: fleetManager.displayAllData(); break;
    //     case 4: reservationManager.displaySeatDetails(); break;
    //     case 5: {
    //         int no;
    //         cout << "Enter Bus No to remove: "; cin >> no;
    //         fleetManager.removeBusByNumber(no);
    //         fleetManager.saveToFile("buses.txt");
    //         break;
    //     }
    //     case 0:
    //         displayHeader("Exiting system and saving data...");
    //         break;
    //     default:
    //         displayError("Invalid selection.");
    //     }
    // } while (choice != 0);

    // return 0;
    ReservationManager resManager;
    resManager.createReservation(101, "TRIP_A", 5);
    resManager.createReservation(102, "TRIP_A", 5);

    resManager.createReservation(102, "TRIP_A", 6);
    resManager.displayAllReservations();

    //resManager.cancelReservation(1000);
    resManager.displayAllReservations();

    return 0;
}