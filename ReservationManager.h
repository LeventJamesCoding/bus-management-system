#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "BaseManager.h"

class ReservationManager : public BaseManager { 
public:
    ReservationManager(vector<Bus>& busList);

    void makeReservation();
    void displaySeatDetails();
    void showAvailableRoutes() const;

    Bus* findBus(int no);

    vector<Bus*> findBus(const string& dep, const string& arr);

    ReservationManager() = default;
};

#endif 