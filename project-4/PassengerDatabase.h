//
//  PassengerDatabase.hpp
//  Titanic
//
//  Created by Sanjana Rathore on 11/16/23.
//

#ifndef PassengerDatabase_h
#define PassengerDatabase_h

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include "DataCollectorCallback.h"
#include "Passenger.h"
#include "CSVFile.h"

namespace cs32 {

class PassengerDatabase : public DataCollectorCallback {
public:
    PassengerDatabase();
    ~PassengerDatabase();
    
    int load(std::string filePath);
    
    void clearAllPassengers();
    bool loaded();
    Passenger* getPassenger_byName(std::string name);
    std::vector<Passenger*> getPassengers();
    std::vector<Passenger*> getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
    std::vector<Passenger*> getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare);
    
    virtual void csvData(std::map<std::string, std::string> row);
    // go through the map and create passenger objects and add to passengers

private:
    std::vector<Passenger*> passengers;
    bool isLoaded;
    
};
}

#endif /* PassengerDatabase_hpp */
