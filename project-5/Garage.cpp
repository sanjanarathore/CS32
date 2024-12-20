#include "Garage.h"

namespace cs32
{


Garage::Garage( size_t capacity ) // :       // TODO: CS 32 Students to complete code here
{
    // TODO: CS 32 Students to complete code here
    mCapacity = capacity;
}

// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    // TODO: CS 32 Students to complete code here
    if (size() < mCapacity) {
        mDeque.addToFront(s);
        return false;
    } else {
        mDeque.deleteRear();
        mDeque.addToFront(s);
        return true;
    }
}

bool Garage::tossOut( std::string s )
{
    // TODO: CS 32 Students to complete code here
    if (find(s)) {
        mDeque.deleteItem(s);
        return true;
    }
    return( false );
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    // TODO: CS 32 Students to complete code here
    if (find(s)) {
        mDeque.deleteItem(s);
        mDeque.addToFront(s);
        return true;
    }
    return( false );
}

// is it in the garage?
bool Garage::find( std::string s )
{
    // TODO: CS 32 Students to complete code here
    Deque<std::string> d = mDeque;
    while (d.size() != 0) {
        if (s == d.front()) {
            return true;
        }
        d.deleteFront();
    }
    return( false );
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    // TODO: CS 32 Students to complete code here
    
    return mCapacity;
    //return( 0 );
}
// how much is in this garage right now?
size_t Garage::size( )
{
    // TODO: CS 32 Students to complete code here
    return mDeque.size();
    //return( 0 );
}

std::string Garage::printItems( )
{
    // TODO: CS 32 Students to complete code here
    return mDeque.printItems();
    //return( "" );
}


}
