//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Sanjana Rathore on 11/26/23.
//

#include "PassengerOutputTable.h"

namespace cs32 {

PassengerOutputTable::PassengerOutputTable(std::vector<Passenger*> passengers) {
    mPassengerList = passengers;
}

void PassengerOutputTable::setOutputField(Field f) {
    mField = f;
}

void PassengerOutputTable::setDescription(std::string description) {
    mDescription = description;
}

Field PassengerOutputTable::getOutputField() {
    return mField;
}

std::string PassengerOutputTable::getDescription() {
    return mDescription;
}


void PassengerOutputTable::display() {
    mRows.clear();    // printz extra rows when you dont clear it every time
    
    // when mField = NOVALUE print nothing by returning immediately
    if(mField == Field::NOVALUE ) {
        return;
    }
    
    std::cout << mDescription << std::endl;
    // format Survived/Total % line to line up with the OutputTableRows
    printf("%30s %4s \n","Survived/Total", "%");

    // switch statemnt to handle the different Field options
    switch (getOutputField()) {
        case Field::BYCLASS: {
            // create 4 OutputTableRows for each class/notknown
            for(int i = 0; i < 4; i++) {
                OutputTableRow row;
                mRows.push_back(row);
            }
            mRows[0].setDescription("First Class");
            mRows[1].setDescription("Second Class");
            mRows[2].setDescription("Third Class");
            mRows[3].setDescription("Not Known");
            
            // iterate through the list of passengers and add the data to the respective OutputTableRow
            std::vector<Passenger*>::iterator iterC = mPassengerList.begin();
            int indexC;
            while(iterC != mPassengerList.end()) {
                //std::cout << (*iter)->getName() << std::endl;
                if ((*iterC)->getClass() == Class::FIRST) {
                    indexC = 0;
                } else if ((*iterC)->getClass() == Class::SECOND) {
                    indexC = 1;
                } else if ((*iterC)->getClass() == Class::THIRD) {
                    indexC = 2;
                } else {
                    indexC = 3;
                }
                mRows[indexC].setTotal(mRows[indexC].getTotal() + 1);
                if ((*iterC)->getSurvived()) {
                   mRows[indexC].setSurvived(mRows[indexC].getSurvived() + 1);
                }
                iterC++;
            }
            break;
        }
        case Field::BYEMBARCATION: {
            // create 4 OutputTableRows for each embarcation location/notknown
            for(int i = 0; i < 4; i++) {
                OutputTableRow row;
                mRows.push_back(row);
            }
            mRows[0].setDescription("Cherbourg");
            mRows[1].setDescription("Queenstown");
            mRows[2].setDescription("Southhampton");
            mRows[3].setDescription("Not Known");
            
            // iterate through the list of passengers and add the data to the respective OutputTableRow
            std::vector<Passenger*>::iterator iterE = mPassengerList.begin();
            int indexE;
            while(iterE != mPassengerList.end()) {
                if ((*iterE)->getEmbarcation() == Embarcation::CHERBOURG) {
                    indexE = 0;
                } else if ((*iterE)->getEmbarcation() == Embarcation::QUEENSTOWN) {
                    indexE = 1;
                } else if ((*iterE)->getEmbarcation() == Embarcation::SOUTHHAMPTON) {
                    indexE = 2;
                } else {
                    indexE = 3;
                }
                mRows[indexE].setTotal(mRows[indexE].getTotal() + 1);
                if ((*iterE)->getSurvived()) {
                   mRows[indexE].setSurvived(mRows[indexE].getSurvived() + 1);
                }
                iterE++;
            }
            break;
        }
        case Field::BYFARE: {
            // create 5 OutputTableRows for each fare range
            for(int i = 0; i < 5; i++) {
                OutputTableRow row;
                mRows.push_back(row);
            }
            mRows[0].setDescription("Not Known");
            mRows[1].setDescription(" $1-$10");
            mRows[2].setDescription("$10-$25");
            mRows[3].setDescription("$25-$50");
            mRows[4].setDescription("   >$50");
            
            // iterate through the list of passengers and add the data to the respective OutputTableRow
            std::vector<Passenger*>::iterator iterF = mPassengerList.begin();
            int indexF;
            while(iterF != mPassengerList.end()) {
                if ((*iterF)->getFare() > 50) {
                    indexF = 4;
                } else if ((*iterF)->getFare() > 25) {
                    indexF = 3;
                } else if ((*iterF)->getFare() > 10) {
                    indexF = 2;
                } else if ((*iterF)->getFare() > 0) {
                    indexF = 1;
                } else {
                    indexF = 0;
                }
                mRows[indexF].setTotal(mRows[indexF].getTotal() + 1);
                if ((*iterF)->getSurvived()) {
                   mRows[indexF].setSurvived(mRows[indexF].getSurvived() + 1);
                }
                iterF++;
            }
            break;
        }
        case Field::NOVALUE: {
            return;
        }
    }
    
    // print each OutputTableRow
    std::vector<OutputTableRow>::iterator rowIter = mRows.begin();
    while(rowIter != mRows.end()) {
        rowIter->display();
        rowIter++;
    }
    
    
}

size_t PassengerOutputTable::rowCount() {
    return mRows.size();
}

OutputTableRow PassengerOutputTable::getRow(int index) {
    return mRows.at(index);
}

}
