//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Sanjana Rathore on 11/16/23.
//

#include "PassengerDatabase.h"


namespace cs32 {

PassengerDatabase::PassengerDatabase() {
    isLoaded = false;
}
    
PassengerDatabase::~PassengerDatabase() {
    clearAllPassengers();
}

int PassengerDatabase::load(std::string filePath) {
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    isLoaded = true;                // set isLoaded to true now that database is loaded
    return( recordCount );
}

void PassengerDatabase::clearAllPassengers() {
    // delete the news
    std::vector<Passenger*>::iterator iter = passengers.begin();
    while(iter != passengers.end()) {
        delete *iter;
        iter++;
    }
    // clears dead ptrs
    passengers.clear();
}

bool PassengerDatabase::loaded() {
    return isLoaded;
}


Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
    std::vector<Passenger*>::iterator iter = passengers.begin();
    while(iter != passengers.end()) {
        if((*iter)->getName() == name) {
            return *iter;
        }
        iter++;
    }
    return nullptr;
}

std::vector<Passenger*> PassengerDatabase::getPassengers() {
    return passengers;
}

std::vector<Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
    std::vector<Passenger*> passengersInClass;
    std::vector<Passenger*>::iterator iter = passengers.begin();
    while(iter != passengers.end()) {
        if (paidClass == (*iter)->getClass() && survived == (*iter)->getSurvived() && (*iter)->getFare() > minimumFare) {
            passengersInClass.push_back(*iter);
        }
        iter++;
    }
    return passengersInClass;
}

std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare) {
    std::vector<Passenger*> passengersInEmbarcation;
    std::vector<Passenger*>::iterator iter = passengers.begin();
    while(iter != passengers.end()) {
        if (embarked == (*iter)->getEmbarcation() && survived == (*iter)->getSurvived() && (*iter)->getFare() > minimumFare) {
            passengersInEmbarcation.push_back(*iter);
        }
        iter++;
    }
    return passengersInEmbarcation;
}

void PassengerDatabase::csvData(std::map<std::string, std::string> row) {
    // create passenger object
    Passenger* p = new Passenger();
    
    // pull values from map and set members vavriables in passenger
    p->setClass(row["pclass"]);
    p->setEmbarcation(row["embarked"]);
    p->setName(row["name"]);
    p->setSurvived(row["survived"]);
    p->setFare(row["fare"]);
    
    // add object to passengers vector
    passengers.push_back(p);
}


}
