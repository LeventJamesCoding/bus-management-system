#include "ReservationManager.h"
#include <iomanip> // For std::setw (formatting)

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

bool ReservationManager::createReservation(int passengerId, const Trip* trip, int seatNumber) {
    
    if (trip == nullptr) {
        std::cout << "[Error] Trip not found! Cannot make reservation.\n";
        return false;
    }
    if (seatNumber < 1 || seatNumber > trip->maxCapacity) {
        std::cout << "[Error] Invalid seat number! This bus only has " 
                  << trip->maxCapacity << " seats.\n";
        return false;
    }
    if (isSeatOccupied(trip->tripId, seatNumber)) {
        std::cout << "[Error] Seat " << seatNumber << " is already occupied for Trip " << trip->tripId << ".\n";
        return false;
    }
    Reservation newRes;
    newRes.reservationId = nextReservationId++;
    newRes.passengerId = passengerId;
    newRes.tripId = trip->tripId;
    newRes.seatNumber = seatNumber;
    newRes.isActive = true;

    reservations.push_back(newRes);
    
    std::cout << "[Success] Reservation created for Trip " << trip->tripId 
              << " at Seat " << seatNumber << ".\n";
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

void ReservationManager::displayAllReservations(BusFleetManager& fleetMgr) const {
    std::cout << "\n================= RESERVATION LIST =================\n";
    std::cout << std::left 
              << std::setw(10) << "Res. ID" 
              << std::setw(12) << "Pass. ID" 
              << std::setw(10) << "Trip ID" 
              << std::setw(30) << "Route (Start -> End)"
              << std::setw(8)  << "Seat" << "\n";
    
    std::cout << "---------------------------------------------------------------------\n";
    
    for (const auto& res : reservations) {
        if (res.isActive) {
            Trip* tripInfo = fleetMgr.getTripById(res.tripId);
            std::string routeInfo = "Unknown Route";
            
            if (tripInfo != nullptr) {
                routeInfo = tripInfo->startLocation + " -> " + tripInfo->endLocation;
            }

            std::cout << std::left 
                      << std::setw(10) << res.reservationId 
                      << std::setw(12) << res.passengerId 
                      << std::setw(10) << res.tripId 
                      << std::setw(30) << routeInfo
                      << std::setw(8)  << res.seatNumber << "\n";
        }
    }
    std::cout << "=======================================================\n\n";
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