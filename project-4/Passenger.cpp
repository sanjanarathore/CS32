//
//  Passenger.cpp
//  Titanic
//
//  Created by Sanjana Rathore on 11/15/23.
//

#include "Passenger.h"

namespace cs32 {

// DC
Passenger::Passenger() {
}

void Passenger::setName(std::string name) {
    mName = name;
}

std::string Passenger::getName() {
    return mName;
}

void Passenger::setEmbarcation(std::string embarked) {
    if (embarked == "C") {
        mEmbarked = Embarcation::CHERBOURG;
    } else if (embarked == "Q") {
        mEmbarked = Embarcation::QUEENSTOWN;
    } else if (embarked == "S") {
        mEmbarked = Embarcation::SOUTHHAMPTON;
    } else {
        mEmbarked = Embarcation::NOTKNOWN;
    }
}

void Passenger::setClass(std::string classofFare) {
    if (classofFare == "1") {
        mClass = Class::FIRST;
    } else if (classofFare == "2") {
        mClass = Class::SECOND;
    } else if (classofFare == "3") {
        mClass = Class::THIRD;
    } else {
        mClass = Class::NOTKNOWN;
    }
}

void Passenger::setSurvived(std::string survived) {
    if (survived == "1") {
        mSurvived = true;
    } else {
        mSurvived = false;
    }
}

void Passenger::setFare(std::string fare) {
    // handle case if fare data does not exist/is an empty string
    if (fare == "") {
        mFare = 0;
    }
    else {
        mFare = std::stof( fare );
    }
}

Embarcation Passenger::getEmbarcation() {
    return mEmbarked;
}

Class Passenger::getClass() {
    return mClass;
}

bool Passenger::getSurvived() {
    return mSurvived;
}

double Passenger::getFare() {
    return mFare;
}

}
