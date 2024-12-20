//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    // hand with at least one ace
    if (isSoft()) {
        // Ace pair
        if (isPair()) {
            return Choice::SPLIT;
        }
        // A with 8
        else if (mCard1.getValue() == 8 || mCard2.getValue() == 8) {
            return Choice::STAND;
        }
        // A with 7
        else if (mCard1.getValue() == 7 || mCard2.getValue() == 7) {
            if (dealerCard.getValue() == 2 || dealerCard.getValue() == 7 || dealerCard.getValue() == 8) {
                return Choice::STAND;
            } else if (dealerCard.getValue() >= 9 || dealerCard.getValue() == 1) {
                return Choice::HIT;
            } else {
                return Choice::DOUBLESTAND;
            }
        }
        // A with 6
        else if (mCard1.getValue() == 6 || mCard2.getValue() == 6) {
            if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
                return Choice::DOUBLEHIT;
            } else {
                return Choice::HIT;
            }
        }
        // A with 5 or 4
        else if (mCard1.getValue() == 5 || mCard2.getValue() == 5 || mCard1.getValue() == 4 || mCard2.getValue() == 4) {
            if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
                return Choice::DOUBLEHIT;
            } else {
                return Choice::HIT;
            }
        }
        // A with 3 or 2
        else if (mCard1.getValue() == 3 || mCard2.getValue() == 3 || mCard1.getValue() == 2 || mCard2.getValue() == 2) {
            if (dealerCard.getValue() == 5 || dealerCard.getValue() == 6) {
                return Choice::DOUBLEHIT;
            } else {
                return Choice::HIT;
            }
        }
    // the pairs
    } else if (isPair()) {
        // 10 pair
        if (mCard1.getValue() == 10) {
            return Choice::STAND;
        }
        // 9 pair
        else if (mCard1.getValue() == 9) {
            if (dealerCard.getValue() == 7 || dealerCard.getValue() == 10 || dealerCard.getValue() == 1) {
                return Choice::STAND;
            } else
                return Choice::SPLIT;
        }
        // 8 pair
        else if (mCard1.getValue() == 8) {
            return Choice::SPLIT;
        }
        // 7 pair
        else if (mCard1.getValue() == 7) {
            if (dealerCard.getValue() >= 8 || dealerCard.getValue() == 1) {
                return Choice::HIT;
            } else {
                return Choice::SPLIT;
            }
        }
        // 6 pair
        else if (mCard1.getValue() == 6) {
            if (dealerCard.getValue() == 2) {
                return Choice::SPLITHIT;
            } else if (dealerCard.getValue() >= 7 || dealerCard.getValue() == 1) {
                return Choice::HIT;
            } else {
                return Choice::SPLIT;
            }
        }
        // 5 pair
        else if (mCard1.getValue() == 5) {
            if (dealerCard.getValue() == 10 || dealerCard.getValue() == 1) {
                return Choice::HIT;
            } else {
                return Choice::DOUBLEHIT;
            }
        }
        // 4 pair
        else if (mCard1.getValue() == 4) {
            if (dealerCard.getValue() == 5 || dealerCard.getValue() == 6) {
                return Choice::SPLITHIT;
            } else {
                return Choice::HIT;
            }
        }
        // 2 pair or 3 pair
        else if (mCard1.getValue() == 2 || mCard1.getValue() == 3) {
            if (dealerCard.getValue() == 2 || dealerCard.getValue() == 3) {
                return Choice::SPLITHIT;
            } else if (dealerCard.getValue() == 1 || dealerCard.getValue() >= 8) {
                return Choice::HIT;
            } else {
                return Choice::SPLIT;
            }
        }
    } else {
        
        // sum of hands
        // sum = 17
        if (mCard1.getValue() + mCard2.getValue() == 17) {
            return Choice::STAND;
        }
        // sum = 16
        else if (mCard1.getValue() + mCard2.getValue() == 16) {
            if (dealerCard.getValue() == 1 || dealerCard.getValue() >= 9) {
                return Choice::SURRENDERHIT;
            } else if (dealerCard.getValue() == 7 || dealerCard.getValue() == 8) {
                return Choice::HIT;
            } else {
                return Choice::STAND;
            }
        }
        // sum = 15
        else if (mCard1.getValue() + mCard2.getValue() == 15) {
            if (dealerCard.getValue() == 10) {
                return Choice::SURRENDERHIT;
            } else if (dealerCard.getValue() <= 6 && dealerCard.getValue() >= 2) {
                return Choice::STAND;
            } else {
                return Choice::HIT;
            }
        }
        // sum = 14 or 13
        else if (mCard1.getValue() + mCard2.getValue() == 14 || mCard1.getValue() + mCard2.getValue() == 13) {
            if (dealerCard.getValue() == 1 || dealerCard.getValue() >= 7) {
                return Choice::HIT;
            } else {
                return Choice::STAND;
            }
        }
        // sum = 12
        else if (mCard1.getValue() + mCard2.getValue() == 12) {
            if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
                return Choice::STAND;
            } else {
                return Choice::HIT;
            }
        }
        // sum = 11
        else if (mCard1.getValue() + mCard2.getValue() == 11) {
            return Choice::DOUBLEHIT;
        }
        // sum = 10
        else if (mCard1.getValue() + mCard2.getValue() == 10) {
            if (dealerCard.getValue() == 1 || dealerCard.getValue() == 10) {
                return Choice::HIT;
            } else {
                return Choice::DOUBLEHIT;
            }
        }
        // sum = 9
        else if (mCard1.getValue() + mCard2.getValue() == 9) {
            if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
                return Choice::DOUBLEHIT;
            } else {
                return Choice::HIT;
            }
        }
        // sum = 8
        else if (mCard1.getValue() + mCard2.getValue() == 8) {
            return Choice::HIT;
        }
    }
    // by default STAND
    Choice c = Choice::STAND;
    return( c );
}

// TODO CS 32 students need to complete this operation
// done
bool Hand::isPair() const
{
    if(getCard1().getFace() == getCard2().getFace())
        return(true);
    return( false );
}

// TODO CS 32 students need to complete this operation
// done
bool Hand::isSoft() const
{
    if(mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE)
        return(true);
    return( false );
}


}
