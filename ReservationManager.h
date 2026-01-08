#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "BusFleetManager.h"

struct Reservation {
    int reservationId;
    int passengerId;
    std::string tripId; 
    int seatNumber;
    bool isActive;
};

class ReservationManager {
private:
    std::vector<Reservation> reservations;
    int nextReservationId;

    bool isSeatOccupied(const std::string& tripId, int seatNumber);

public:
    ReservationManager();

    bool createReservation(int passengerId, const Trip* trip, int seatNumber);
    bool cancelReservation(int reservationId);
    void displayAllReservations(BusFleetManager& fleetMgr) const;
    
    std::vector<Reservation> getReservationsByTrip(const std::string& tripId);
};