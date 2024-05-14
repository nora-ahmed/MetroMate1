#include "Train.h"
#include"Station.h"
#include <chrono>
#include <thread>
#include "Admin.h"

Train::Train(int id, int cap, vector<Station*> route)
    : trainID(id), capacity(cap), route(route) {}


void Train::setBreakdown(bool isBroken) {
    isBreakdown = isBroken;
    if (isBroken) {
        cout << "Train " << trainID << " has broken down!" << endl;
    }

}

//void Train::displayETA(Station& chosenStation, vector<Station*>& route1, vector<Station*>& route2, vector<Station*>& route3) {
//    // Flag to indicate if the station is found in any route
//    bool stationFound = false;
//
//    // Loop through each route to search for the chosen station
//    for (auto& route : { route1, route2, route3 }) {
//        auto it = std::find_if(route.begin(), route.end(), [&chosenStation](Station* stationPtr) {
//            return stationPtr->getName() == chosenStation.getName();
//            });
//
//        if (it != route.end()) {
//            // Station found in this route, calculate ETA
//            size_t chosenStationIndex = std::distance(route.begin(), it);
//            int timeToReachStation = chosenStationIndex * 2; // Each station takes 2 minutes
//            int timeToStart = (trainID - 1) * 5; // 5 minutes interval between trains
//
//            int timeRemaining = timeToReachStation + timeToStart;
//            if (isBreakdown) {
//                timeRemaining += breakdownDelay; // Add breakdown delay
//            }
//
//            std::cout << "Train ID: " << trainID << ", ETA to " << chosenStation.stationName << ": " << timeRemaining << " minutes (on Route " << (route == route1 ? 1 : (route == route2 ? 2 : 3)) << ")" << std::endl;
//            stationFound = true;
//            break; // Exit the loop after finding the station in a route
//        }
//    }
//
//    if (!stationFound) {
//        std::cout << "Chosen station not found in any routes." << std::endl;
//    }
//}
//
//
//void Train::scheduleTrain(int startTime) {
//
//
//}
//
//
//
//void Train::setBreakdown(bool isBroken) {
//    isBreakdown = isBroken;
//    if (isBroken) {
//        cout << "Train " << trainID << " has broken down!" << endl;
//    }
//
//}