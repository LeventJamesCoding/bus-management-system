#include "ReservationManager.h"
#include <iomanip>

ReservationManager::ReservationManager() {
    nextReservationId = 1000; 
}

bool ReservationManager::isSeatOccupied(const std::string& tripId, int seatNumber) {
    for (const auto& res : reservations) {
        if (res.tripId == tripId && res.seatNumber == seatNumber && res.isActive) {
            return true;
        }
    }
    return false;
}

bool ReservationManager::createReservation(int passengerId, const std::string& tripId, int seatNumber) {
    if (isSeatOccupied(tripId, seatNumber)) {
        std::cout << "[Error] Seat " << seatNumber << " is already occupied for Trip " << tripId << ".\n";
        return false;
    }

    Reservation newRes;
    newRes.reservationId = nextReservationId++;
    newRes.passengerId = passengerId;
    newRes.tripId = tripId;
    newRes.seatNumber = seatNumber;
    newRes.isActive = true;

    reservations.push_back(newRes);
    
    std::cout << "[Success] Reservation created. ID: " << newRes.reservationId << "\n";
    return true;
}

bool ReservationManager::cancelReservation(int reservationId) {
    for (auto& res : reservations) {
        if (res.reservationId == reservationId) {
            if (!res.isActive) {
                std::cout << "[Info] Reservation is already cancelled.\n";
                return false;
            }
            res.isActive = false;
            std::cout << "[Success] Reservation " << reservationId << " cancelled.\n";
            return true;
        }
    }
    std::cout << "[Error] Reservation ID not found.\n";
    return false;
}

void ReservationManager::displayAllReservations() const {
    std::cout << "\n--- All Active Reservations ---\n";
    std::cout << "ID      | Passenger ID | Trip ID | Seat \n";
    std::cout << "----------------------------------------\n";
    
    for (const auto& res : reservations) {
        if (res.isActive) {
            std::cout << std::left << std::setw(8) << res.reservationId 
                      << " | " << std::setw(12) << res.passengerId 
                      << " | " << std::setw(7) << res.tripId 
                      << " | " << res.seatNumber << "\n";
        }
    }
    std::cout << "----------------------------------------\n";
}

std::vector<Reservation> ReservationManager::getReservationsByTrip(const std::string& tripId) {
    std::vector<Reservation> tripReservations;
    for (const auto& res : reservations) {
        if (res.tripId == tripId && res.isActive) {
            tripReservations.push_back(res);
        }
    }
    return tripReservations;
}