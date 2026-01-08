#include "Route.h"

Route::Route(const string& dep, const string& arr, int dist)
    : departure(dep), arrival(arr), distanceKm(dist) {
}

void Route::setDeparture(const string& dep) { departure = dep; }
void Route::setArrival(const string& arr) { arrival = arr; }
string Route::getDeparture() const { return departure; }
string Route::getArrival() const { return arrival; }
int Route::getDistance() const { return distanceKm; }

double Route::calculateEstimatedTime(int avgSpeedKmH) const {
    if (distanceKm <= 0 || avgSpeedKmH <= 0) return 0.0;
    return (double)distanceKm / avgSpeedKmH;
}