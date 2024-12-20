//
//  PassengerOutputTable.hpp
//  Titanic
//
//  Created by Sanjana Rathore on 11/26/23.
//

#ifndef PassengerOutputTable_h
#define PassengerOutputTable_h

#include <stdio.h>
#include <string>
#include "PassengerDatabase.h"
#include "OutputTableRow.h"
#include "Enums.h"

namespace cs32 {

class PassengerOutputTable {
public:
    PassengerOutputTable(std::vector<Passenger*> passengers);
    
    void setOutputField(Field f);
    void setDescription(std::string description);
    Field getOutputField();
    std::string getDescription();
    
    void display();
    
    size_t rowCount();
    OutputTableRow getRow(int index);

private:
    std::vector<Passenger*> mPassengerList;
    std::vector<OutputTableRow> mRows;
    Field mField;
    std::string mDescription;
};

}

#endif /* PassengerOutputTable_hpp */
