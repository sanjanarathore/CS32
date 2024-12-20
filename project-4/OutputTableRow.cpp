//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Sanjana Rathore on 11/26/23.
//

#include "OutputTableRow.h"

namespace cs32 {

OutputTableRow::OutputTableRow() {
    mDescription = "";
    mSurvived = 0;
    mTotal = 0;
}

void OutputTableRow::setDescription(std::string description) {
    mDescription = description;
}

void OutputTableRow::setSurvived(int survived) {
    mSurvived = survived;
}

void OutputTableRow::setTotal(int total) {
    mTotal = total;
}

std::string OutputTableRow::getDescription() {
    return mDescription;
}

int OutputTableRow::getSurvived() {
    return mSurvived;
}

int OutputTableRow::getTotal() {
    return mTotal;
}

double OutputTableRow::getPercentage() {
    if (mTotal == 0) {
        return 0;
    }
    double percentage = 1.0 * mSurvived/mTotal;
    return percentage;
}

void OutputTableRow::display() {
    //std::cout << mDescription << "-" << '\t' << '\t' << mSurvived << '\t' << "/" << '\t' << mTotal << '\t' << padToThreeCharacters((int)100*getPercentage()) << std::endl;
    printf("%-13s - %7d / %-5d %-21f\n", mDescription.c_str(), mSurvived, mTotal, 100*getPercentage());
}

//std::string OutputTableRow::padToThreeCharacters(int value) {
//    if (value < 10) {
//        return "  " + std::to_string(value);
//    } else if (value < 99) {
//        return " " + std::to_string(value);
//    }
//    return std::to_string(value);
//}

}
