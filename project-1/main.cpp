//
//  main.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    Card c;

    Card c1;
    Card c2;
    Hand h( c1, c2);
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::CLUBS, Face::THREE );
    Card four( Suit::CLUBS, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::CLUBS, Face::SIX );
    Card seven( Suit::CLUBS, Face::SEVEN );
    Card eight( Suit::CLUBS, Face::EIGHT );
    Card nine( Suit::CLUBS, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::CLUBS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::CLUBS, Face::KING );
    // two aces...
    assert( h.evaluateHand(two) == Choice::SPLIT );

    // Pair Hands
    // two As
    Hand h1( ace, ace);
    assert( h1.evaluateHand(two) == Choice::SPLIT );
    assert( h1.evaluateHand(three) == Choice::SPLIT );
    assert( h1.evaluateHand(four) == Choice::SPLIT );
    assert( h1.evaluateHand(five) == Choice::SPLIT );
    assert( h1.evaluateHand(six) == Choice::SPLIT );
    assert( h1.evaluateHand(seven) == Choice::SPLIT );
    assert( h1.evaluateHand(eight) == Choice::SPLIT );
    assert( h1.evaluateHand(nine) == Choice::SPLIT );
    assert( h1.evaluateHand(ten) == Choice::SPLIT );
    assert( h1.evaluateHand(jack) == Choice::SPLIT );
    assert( h1.evaluateHand(queen) == Choice::SPLIT );
    assert( h1.evaluateHand(king) == Choice::SPLIT );
    assert( h1.evaluateHand(ace) == Choice::SPLIT );

    // two 2s
    Hand h2( two, two );
    assert( h2.evaluateHand(two) == Choice::SPLITHIT );
    assert( h2.evaluateHand(three) == Choice::SPLITHIT );
    assert( h2.evaluateHand(four) == Choice::SPLIT );
    assert( h2.evaluateHand(five) == Choice::SPLIT );
    assert( h2.evaluateHand(six) == Choice::SPLIT );
    assert( h2.evaluateHand(seven) == Choice::SPLIT );
    assert( h2.evaluateHand(eight) == Choice::HIT );
    assert( h2.evaluateHand(nine) == Choice::HIT );
    assert( h2.evaluateHand(ten) == Choice::HIT );
    assert( h2.evaluateHand(jack) == Choice::HIT );
    assert( h2.evaluateHand(queen) == Choice::HIT );
    assert( h2.evaluateHand(king) == Choice::HIT );
    assert( h2.evaluateHand(ace) == Choice::HIT );

    // two 3s
    Hand h3( three, three );
    assert( h2.evaluateHand(two) == Choice::SPLITHIT );
    assert( h2.evaluateHand(three) == Choice::SPLITHIT );
    assert( h2.evaluateHand(four) == Choice::SPLIT );
    assert( h2.evaluateHand(five) == Choice::SPLIT );
    assert( h2.evaluateHand(six) == Choice::SPLIT );
    assert( h2.evaluateHand(seven) == Choice::SPLIT );
    assert( h2.evaluateHand(eight) == Choice::HIT );
    assert( h2.evaluateHand(nine) == Choice::HIT );
    assert( h2.evaluateHand(ten) == Choice::HIT );
    assert( h2.evaluateHand(jack) == Choice::HIT );
    assert( h2.evaluateHand(queen) == Choice::HIT );
    assert( h2.evaluateHand(king) == Choice::HIT );
    assert( h2.evaluateHand(ace) == Choice::HIT );

    // two 4s
    Hand h4( four, four );
    assert( h4.evaluateHand(two) == Choice::HIT );
    assert( h4.evaluateHand(three) == Choice::HIT );
    assert( h4.evaluateHand(four) == Choice::HIT );
    assert( h4.evaluateHand(five) == Choice::SPLITHIT );
    assert( h4.evaluateHand(six) == Choice::SPLITHIT );
    assert( h4.evaluateHand(seven) == Choice::HIT );
    assert( h4.evaluateHand(eight) == Choice::HIT );
    assert( h4.evaluateHand(nine) == Choice::HIT );
    assert( h4.evaluateHand(ten) == Choice::HIT );
    assert( h4.evaluateHand(jack) == Choice::HIT );
    assert( h4.evaluateHand(queen) == Choice::HIT );
    assert( h4.evaluateHand(king) == Choice::HIT );
    assert( h4.evaluateHand(ace) == Choice::HIT );

    // two 5s
    Hand h5( five, five );
    assert( h5.evaluateHand(two) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(seven) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(eight) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(nine) == Choice::DOUBLEHIT );
    assert( h5.evaluateHand(ten) == Choice::HIT );
    assert( h5.evaluateHand(jack) == Choice::HIT );
    assert( h5.evaluateHand(queen) == Choice::HIT );
    assert( h5.evaluateHand(king) == Choice::HIT );
    assert( h5.evaluateHand(ace) == Choice::HIT );

    // two 6s
    Hand h6( six, six );
    assert( h6.evaluateHand(two) == Choice::SPLITHIT );
    assert( h6.evaluateHand(three) == Choice::SPLIT );
    assert( h6.evaluateHand(four) == Choice::SPLIT );
    assert( h6.evaluateHand(five) == Choice::SPLIT );
    assert( h6.evaluateHand(six) == Choice::SPLIT );
    assert( h6.evaluateHand(seven) == Choice::HIT  );
    assert( h6.evaluateHand(eight) == Choice::HIT  );
    assert( h6.evaluateHand(nine) == Choice::HIT  );
    assert( h6.evaluateHand(ten) == Choice::HIT );
    assert( h6.evaluateHand(jack) == Choice::HIT );
    assert( h6.evaluateHand(queen) == Choice::HIT );
    assert( h6.evaluateHand(king) == Choice::HIT );
    assert( h6.evaluateHand(ace) == Choice::HIT );

    // two 7s
    Hand h7( seven, seven );
    assert( h7.evaluateHand(two) == Choice::SPLIT );
    assert( h7.evaluateHand(three) == Choice::SPLIT );
    assert( h7.evaluateHand(four) == Choice::SPLIT );
    assert( h7.evaluateHand(five) == Choice::SPLIT );
    assert( h7.evaluateHand(six) == Choice::SPLIT );
    assert( h7.evaluateHand(seven) == Choice::SPLIT );
    assert( h7.evaluateHand(eight) == Choice::HIT  );
    assert( h7.evaluateHand(nine) == Choice::HIT  );
    assert( h7.evaluateHand(ten) == Choice::HIT );
    assert( h7.evaluateHand(jack) == Choice::HIT );
    assert( h7.evaluateHand(queen) == Choice::HIT );
    assert( h7.evaluateHand(king) == Choice::HIT );
    assert( h7.evaluateHand(ace) == Choice::HIT );

    // two 8s
    Hand h8( eight, eight);
    assert( h8.evaluateHand(two) == Choice::SPLIT );
    assert( h8.evaluateHand(three) == Choice::SPLIT );
    assert( h8.evaluateHand(four) == Choice::SPLIT );
    assert( h8.evaluateHand(five) == Choice::SPLIT );
    assert( h8.evaluateHand(six) == Choice::SPLIT );
    assert( h8.evaluateHand(seven) == Choice::SPLIT );
    assert( h8.evaluateHand(eight) == Choice::SPLIT );
    assert( h8.evaluateHand(nine) == Choice::SPLIT );
    assert( h8.evaluateHand(ten) == Choice::SPLIT );
    assert( h8.evaluateHand(jack) == Choice::SPLIT );
    assert( h8.evaluateHand(queen) == Choice::SPLIT );
    assert( h8.evaluateHand(king) == Choice::SPLIT );
    assert( h8.evaluateHand(ace) == Choice::SPLIT );

    // two 9s
    Hand h9( nine, nine);
    assert( h9.evaluateHand(two) == Choice::SPLIT );
    assert( h9.evaluateHand(three) == Choice::SPLIT );
    assert( h9.evaluateHand(four) == Choice::SPLIT );
    assert( h9.evaluateHand(five) == Choice::SPLIT );
    assert( h9.evaluateHand(six) == Choice::SPLIT );
    assert( h9.evaluateHand(seven) == Choice::STAND );
    assert( h9.evaluateHand(eight) == Choice::SPLIT );
    assert( h9.evaluateHand(nine) == Choice::SPLIT );
    assert( h9.evaluateHand(ten) == Choice::STAND );
    assert( h9.evaluateHand(jack) == Choice::STAND );
    assert( h9.evaluateHand(queen) == Choice::STAND );
    assert( h9.evaluateHand(king) == Choice::STAND );
    assert( h9.evaluateHand(ace) == Choice::STAND );

    // two 10s
    Hand h10( ten, ten);
    assert( h10.evaluateHand(two) == Choice::STAND );
    assert( h10.evaluateHand(three) == Choice::STAND );
    assert( h10.evaluateHand(four) == Choice::STAND );
    assert( h10.evaluateHand(five) == Choice::STAND );
    assert( h10.evaluateHand(six) == Choice::STAND );
    assert( h10.evaluateHand(seven) == Choice::STAND );
    assert( h10.evaluateHand(eight) == Choice::STAND );
    assert( h10.evaluateHand(nine) == Choice::STAND );
    assert( h10.evaluateHand(ten) == Choice::STAND );
    assert( h10.evaluateHand(jack) == Choice::STAND );
    assert( h10.evaluateHand(queen) == Choice::STAND );
    assert( h10.evaluateHand(king) == Choice::STAND );
    assert( h10.evaluateHand(ace) == Choice::STAND );

    // Soft Hands
    // A,2
    Hand h11( ace, two);
    assert( h11.evaluateHand(two) == Choice::HIT );
    assert( h11.evaluateHand(three) == Choice::HIT );
    assert( h11.evaluateHand(four) == Choice::HIT );
    assert( h11.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h11.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h11.evaluateHand(seven) == Choice::HIT );
    assert( h11.evaluateHand(eight) == Choice::HIT );
    assert( h11.evaluateHand(nine) == Choice::HIT );
    assert( h11.evaluateHand(ten) == Choice::HIT );
    assert( h11.evaluateHand(jack) == Choice::HIT );
    assert( h11.evaluateHand(queen) == Choice::HIT );
    assert( h11.evaluateHand(king) == Choice::HIT );
    assert( h11.evaluateHand(ace) == Choice::HIT );
    
    // A,3
    Hand h12( ace, three);
    assert( h12.evaluateHand(two) == Choice::HIT );
    assert( h12.evaluateHand(three) == Choice::HIT );
    assert( h12.evaluateHand(four) == Choice::HIT );
    assert( h12.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h12.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h12.evaluateHand(seven) == Choice::HIT );
    assert( h12.evaluateHand(eight) == Choice::HIT );
    assert( h12.evaluateHand(nine) == Choice::HIT );
    assert( h12.evaluateHand(ten) == Choice::HIT );
    assert( h12.evaluateHand(jack) == Choice::HIT );
    assert( h12.evaluateHand(queen) == Choice::HIT );
    assert( h12.evaluateHand(king) == Choice::HIT );
    assert( h12.evaluateHand(ace) == Choice::HIT );
    
    // A,4
    Hand h13( ace, four);
    assert( h13.evaluateHand(two) == Choice::HIT );
    assert( h13.evaluateHand(three) == Choice::HIT );
    assert( h13.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h13.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h13.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h13.evaluateHand(seven) == Choice::HIT );
    assert( h13.evaluateHand(eight) == Choice::HIT );
    assert( h13.evaluateHand(nine) == Choice::HIT );
    assert( h13.evaluateHand(ten) == Choice::HIT );
    assert( h13.evaluateHand(jack) == Choice::HIT );
    assert( h13.evaluateHand(queen) == Choice::HIT );
    assert( h13.evaluateHand(king) == Choice::HIT );
    assert( h13.evaluateHand(ace) == Choice::HIT );
    
    // A,5
    Hand h14( ace, five);
    assert( h14.evaluateHand(two) == Choice::HIT );
    assert( h14.evaluateHand(three) == Choice::HIT );
    assert( h14.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h14.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h14.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h14.evaluateHand(seven) == Choice::HIT );
    assert( h14.evaluateHand(eight) == Choice::HIT );
    assert( h14.evaluateHand(nine) == Choice::HIT );
    assert( h14.evaluateHand(ten) == Choice::HIT );
    assert( h14.evaluateHand(jack) == Choice::HIT );
    assert( h14.evaluateHand(queen) == Choice::HIT );
    assert( h14.evaluateHand(king) == Choice::HIT );
    assert( h14.evaluateHand(ace) == Choice::HIT );
    
    // A,6
    Hand h15( ace, six);
    assert( h15.evaluateHand(two) == Choice::HIT );
    assert( h15.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h15.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h15.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h15.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h15.evaluateHand(seven) == Choice::HIT );
    assert( h15.evaluateHand(eight) == Choice::HIT );
    assert( h15.evaluateHand(nine) == Choice::HIT );
    assert( h15.evaluateHand(ten) == Choice::HIT );
    assert( h15.evaluateHand(jack) == Choice::HIT );
    assert( h15.evaluateHand(queen) == Choice::HIT );
    assert( h15.evaluateHand(king) == Choice::HIT );
    assert( h15.evaluateHand(ace) == Choice::HIT );
    
    // A,7
    Hand h16( ace, seven);
    assert( h16.evaluateHand(two) == Choice::STAND );
    assert( h16.evaluateHand(three) == Choice::DOUBLESTAND );
    assert( h16.evaluateHand(four) == Choice::DOUBLESTAND );
    assert( h16.evaluateHand(five) == Choice::DOUBLESTAND );
    assert( h16.evaluateHand(six) == Choice::DOUBLESTAND );
    assert( h16.evaluateHand(seven) == Choice::STAND );
    assert( h16.evaluateHand(eight) == Choice::STAND );
    assert( h16.evaluateHand(nine) == Choice::HIT );
    assert( h16.evaluateHand(ten) == Choice::HIT );
    assert( h16.evaluateHand(jack) == Choice::HIT );
    assert( h16.evaluateHand(queen) == Choice::HIT );
    assert( h16.evaluateHand(king) == Choice::HIT );
    assert( h16.evaluateHand(ace) == Choice::HIT );
    
    // A,8
    Hand h17( ace, eight);
    assert( h17.evaluateHand(two) == Choice::STAND );
    assert( h17.evaluateHand(three) == Choice::STAND );
    assert( h17.evaluateHand(four) == Choice::STAND );
    assert( h17.evaluateHand(five) == Choice::STAND );
    assert( h17.evaluateHand(six) == Choice::STAND );
    assert( h17.evaluateHand(seven) == Choice::STAND );
    assert( h17.evaluateHand(eight) == Choice::STAND );
    assert( h17.evaluateHand(nine) == Choice::STAND );
    assert( h17.evaluateHand(ten) == Choice::STAND );
    assert( h17.evaluateHand(jack) == Choice::STAND );
    assert( h17.evaluateHand(queen) == Choice::STAND );
    assert( h17.evaluateHand(king) == Choice::STAND );
    assert( h17.evaluateHand(ace) == Choice::STAND );
    
    // Sum Hands
    // check sum of 8
    Hand h18( two, six);
    assert( h18.evaluateHand(two) == Choice::HIT );
    assert( h18.evaluateHand(three) == Choice::HIT );
    assert( h18.evaluateHand(four) == Choice::HIT );
    assert( h18.evaluateHand(five) == Choice::HIT );
    assert( h18.evaluateHand(six) == Choice::HIT );
    assert( h18.evaluateHand(seven) == Choice::HIT );
    assert( h18.evaluateHand(eight) == Choice::HIT );
    assert( h18.evaluateHand(nine) == Choice::HIT );
    assert( h18.evaluateHand(ten) == Choice::HIT );
    assert( h18.evaluateHand(jack) == Choice::HIT );
    assert( h18.evaluateHand(queen) == Choice::HIT );
    assert( h18.evaluateHand(king) == Choice::HIT );
    assert( h18.evaluateHand(ace) == Choice::HIT );

    // check sum of 9
    Hand h19( three, six);
    assert( h19.evaluateHand(two) == Choice::HIT );
    assert( h19.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h19.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h19.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h19.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h19.evaluateHand(seven) == Choice::HIT );
    assert( h19.evaluateHand(eight) == Choice::HIT );
    assert( h19.evaluateHand(nine) == Choice::HIT );
    assert( h19.evaluateHand(ten) == Choice::HIT );
    assert( h19.evaluateHand(jack) == Choice::HIT );
    assert( h19.evaluateHand(queen) == Choice::HIT );
    assert( h19.evaluateHand(king) == Choice::HIT );
    assert( h19.evaluateHand(ace) == Choice::HIT );

    // check sum of 10
    Hand h20( four, six);
    assert( h20.evaluateHand(two) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(seven) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(eight) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(nine) == Choice::DOUBLEHIT );
    assert( h20.evaluateHand(ten) == Choice::HIT );
    assert( h20.evaluateHand(jack) == Choice::HIT );
    assert( h20.evaluateHand(queen) == Choice::HIT );
    assert( h20.evaluateHand(king) == Choice::HIT );
    assert( h20.evaluateHand(ace) == Choice::HIT );

    // check sum of 11
    Hand h21( four, seven);
    assert( h21.evaluateHand(two) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(seven) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(eight) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(nine) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(ten) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(jack) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(queen) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(king) == Choice::DOUBLEHIT );
    assert( h21.evaluateHand(ace) == Choice::DOUBLEHIT );

    // check sum of 12
    Hand h22( four, eight);
    assert( h22.evaluateHand(two) == Choice::HIT );
    assert( h22.evaluateHand(three) == Choice::HIT );
    assert( h22.evaluateHand(four) == Choice::STAND );
    assert( h22.evaluateHand(five) == Choice::STAND );
    assert( h22.evaluateHand(six) == Choice::STAND );
    assert( h22.evaluateHand(seven) == Choice::HIT );
    assert( h22.evaluateHand(eight) == Choice::HIT );
    assert( h22.evaluateHand(nine) == Choice::HIT );
    assert( h22.evaluateHand(ten) == Choice::HIT );
    assert( h22.evaluateHand(jack) == Choice::HIT );
    assert( h22.evaluateHand(queen) == Choice::HIT );
    assert( h22.evaluateHand(king) == Choice::HIT );
    assert( h22.evaluateHand(ace) == Choice::HIT );

    // check sum of 13
    Hand h23( five, eight);
    assert( h23.evaluateHand(two) == Choice::STAND );
    assert( h23.evaluateHand(three) == Choice::STAND );
    assert( h23.evaluateHand(four) == Choice::STAND );
    assert( h23.evaluateHand(five) == Choice::STAND );
    assert( h23.evaluateHand(six) == Choice::STAND );
    assert( h23.evaluateHand(seven) == Choice::HIT );
    assert( h23.evaluateHand(eight) == Choice::HIT );
    assert( h23.evaluateHand(nine) == Choice::HIT );
    assert( h23.evaluateHand(ten) == Choice::HIT );
    assert( h23.evaluateHand(jack) == Choice::HIT );
    assert( h23.evaluateHand(queen) == Choice::HIT );
    assert( h23.evaluateHand(king) == Choice::HIT );
    assert( h23.evaluateHand(ace) == Choice::HIT );

    // check sum of 14
    Hand h24( six, eight);
    assert( h24.evaluateHand(two) == Choice::STAND );
    assert( h24.evaluateHand(three) == Choice::STAND );
    assert( h24.evaluateHand(four) == Choice::STAND );
    assert( h24.evaluateHand(five) == Choice::STAND );
    assert( h24.evaluateHand(six) == Choice::STAND );
    assert( h24.evaluateHand(seven) == Choice::HIT );
    assert( h24.evaluateHand(eight) == Choice::HIT );
    assert( h24.evaluateHand(nine) == Choice::HIT );
    assert( h24.evaluateHand(ten) == Choice::HIT );
    assert( h24.evaluateHand(jack) == Choice::HIT );
    assert( h24.evaluateHand(queen) == Choice::HIT );
    assert( h24.evaluateHand(king) == Choice::HIT );
    assert( h24.evaluateHand(ace) == Choice::HIT );

    // check sum of 15
    Hand h25( seven, eight);
    assert( h25.evaluateHand(two) == Choice::STAND );
    assert( h25.evaluateHand(three) == Choice::STAND );
    assert( h25.evaluateHand(four) == Choice::STAND );
    assert( h25.evaluateHand(five) == Choice::STAND );
    assert( h25.evaluateHand(six) == Choice::STAND );
    assert( h25.evaluateHand(seven) == Choice::HIT );
    assert( h25.evaluateHand(eight) == Choice::HIT );
    assert( h25.evaluateHand(nine) == Choice::HIT );
    assert( h25.evaluateHand(ten) == Choice::SURRENDERHIT );
    assert( h25.evaluateHand(jack) == Choice::SURRENDERHIT );
    assert( h25.evaluateHand(queen) == Choice::SURRENDERHIT );
    assert( h25.evaluateHand(king) == Choice::SURRENDERHIT );
    assert( h25.evaluateHand(ace) == Choice::HIT );

    // check sum of 16
    Hand h26( seven, nine);
    assert( h26.evaluateHand(two) == Choice::STAND );
    assert( h26.evaluateHand(three) == Choice::STAND );
    assert( h26.evaluateHand(four) == Choice::STAND );
    assert( h26.evaluateHand(five) == Choice::STAND );
    assert( h26.evaluateHand(six) == Choice::STAND );
    assert( h26.evaluateHand(seven) == Choice::HIT );
    assert( h26.evaluateHand(eight) == Choice::HIT );
    assert( h26.evaluateHand(nine) == Choice::SURRENDERHIT );
    assert( h26.evaluateHand(ten) == Choice::SURRENDERHIT );
    assert( h26.evaluateHand(jack) == Choice::SURRENDERHIT );
    assert( h26.evaluateHand(queen) == Choice::SURRENDERHIT );
    assert( h26.evaluateHand(king) == Choice::SURRENDERHIT );
    assert( h26.evaluateHand(ace) == Choice::SURRENDERHIT );

    // check sum of 17
    Hand h27( seven, ten);
    assert( h27.evaluateHand(two) == Choice::STAND );
    assert( h27.evaluateHand(three) == Choice::STAND );
    assert( h27.evaluateHand(four) == Choice::STAND );
    assert( h27.evaluateHand(five) == Choice::STAND );
    assert( h27.evaluateHand(six) == Choice::STAND );
    assert( h27.evaluateHand(seven) == Choice::STAND );
    assert( h27.evaluateHand(eight) == Choice::STAND );
    assert( h27.evaluateHand(nine) == Choice::STAND );
    assert( h27.evaluateHand(ten) == Choice::STAND );
    assert( h27.evaluateHand(jack) == Choice::STAND );
    assert( h27.evaluateHand(queen) == Choice::STAND );
    assert( h27.evaluateHand(king) == Choice::STAND );
    assert( h27.evaluateHand(ace) == Choice::STAND );


    return( 0 );
}

