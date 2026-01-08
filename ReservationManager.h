#pragma once
#include <string>
#include <vector>
#include <iostream>

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

    bool createReservation(int passengerId, const std::string& tripId, int seatNumber);
    bool cancelReservation(int reservationId);
    void displayAllReservations() const;
    
    std::vector<Reservation> getReservationsByTrip(const std::string& tripId);
};