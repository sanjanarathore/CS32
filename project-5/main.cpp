// Menu.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"




int main()
{
    using namespace std;
    using namespace cs32;
    
    // TODO: CS 32 students should add testing code here
//    DequeNode< int > sampleNode( 5 );
//    Deque< string > sampleDeque;
//    Deque< int > otherDeque;
//    Garage g;
//    Garage otherg( 12 );
//    
//    cout << "all tests passed!" << endl;
    // Deque Tests

           Deque< int > dInt;
           int x;
           Deque< std::string > dString;
           std::string s;

           dInt.deleteFront( );
           dInt.deleteRear( );
           x = 12;
           assert( dInt.deleteItem( x ) == false );
           assert( dInt.size( ) == 0 );
           assert( dInt.get( -10, x ) == false );
           assert( dInt.isEmpty( )  );
           s = "Hello";
           dString.addToFront( s );
           s = "World!";
           dString.addToRear( s );
    cout << dString.printItems();
           s = "Howard";
           assert( dString.deleteItem( s ) == false );
    cout << dString.printItems();
           assert( dString.size( ) == 2 );
           assert( dString.get( -10, s ) == false );
           assert( dString.isEmpty( ) == false );
           assert( dString.get( 0, s ) && s == "Hello" );
           assert( dString.get( 1, s ) && s == "World!" );
           dString.deleteFront( );
    cout << dString.printItems();
    cout << dString.printItems();
           s = "Hello";
           assert( dString.deleteItem( s ) == false );
    cout << dString.printItems();
           assert( dString.size( ) == 1 );
           assert( dString.get( 0, s ) && s == "World!" );
           assert( dString.isEmpty( ) == false );
           dString.deleteRear( );
    cout << dString.printItems();
           s = "World!";
           assert( dString.deleteItem( s ) == false );
    cout << dString.printItems();
    cout<<dString.front();
    assert(dString.isEmpty());
           assert( dString.size( ) == 0 );
           assert( dString.get( 0, s ) == false );
           assert( dString.isEmpty( ) );
    
    // my test cases for the Deque classes
    Deque<std::string> t1;
    // delete item in empty deque
    assert(t1.deleteItem("0") == false);
    t1.deleteFront();
    t1.deleteRear();
    assert(t1.front() == "");
    assert(t1.rear() == "");
    assert(t1.size() == 0);
    
    t1.addToFront("1");
    assert(t1.front() == "1");
    assert(t1.rear() == "1");
    t1.addToRear("2");
    t1.addToRear("3");
    t1.addToRear("4");
    t1.addToFront("0");
    
    assert(t1.size() == 5);
    cout << t1.printItems();
    assert(t1.front() == "0");
    assert(t1.rear() == "4");
    
    // delete smthg from the middle
    t1.deleteItem("2");
    cout << t1.printItems(); // 1 3 4
    
    // delete head
    t1.deleteItem("1"); // 3 4
    cout << t1.printItems();
    
    // delete tail
    t1.deleteItem("4"); // 3
    cout << t1.printItems();
    
    // try to delete item that does not exist
    t1.deleteItem("5");
    cout<< t1.printItems();
    assert(t1.size() == 2);
    
    // test get function
    string s1;
    assert(t1.get(0, s1) == true);
    assert(s1 == "0");
    assert(t1.get(2, s1) == false);
    


//           // Garage Tests
           Garage g;
           Garage gSix( 6 );

           assert( g.size( ) == 0 );
           assert( g.capacity( ) == 10 );

           assert( gSix.size( ) == 0 );
           assert( gSix.capacity( ) == 6 );
           gSix.tossIn( "shoes" );
           gSix.tossIn( "shirts" );
           gSix.tossIn( "books" );
           assert( gSix.size( ) == 3 );
           assert( gSix.capacity( ) == 6 );
           gSix.tossIn( "suitcases" );
           assert( gSix.tossIn( "tables" ) == false );  // nothing thrown away
           assert( gSix.tossIn( "chairs" ) == false );  // nothing thrown away
           assert( gSix.size( ) == 6 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "shoes" ) );
           assert( gSix.find( "shirts" ) );
           assert( gSix.find( "books" ) );
           assert( gSix.find( "suitcases" ) );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "chairs" ) );

           assert( gSix.tossIn( "boxes" ) );  // shoes thrown away...
           assert( gSix.size( ) == 6 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "boxes" ) );
           assert( gSix.find( "shoes" )  == false );
           assert( gSix.find( "shirts" ) );
           assert( gSix.find( "books" ) );
           assert( gSix.find( "suitcases" ) );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "chairs" ) );

           assert( gSix.tossOut( "shoes" ) == false );   // shoes not found...
           assert( gSix.use( "shoes" ) == false );       // shoes not found...
           assert( gSix.use( "tables" ) );

           assert( gSix.tossIn( "records" ) );     // shirts thrown away...
           assert( gSix.size( ) == 6 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "records" ) );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "boxes" ) );
           assert( gSix.find( "shoes" ) == false );
           assert( gSix.find( "shirts" ) == false );
           assert( gSix.find( "books" ) );
           assert( gSix.find( "suitcases" ) );

           assert( gSix.tossOut( "books" ) );
           assert( gSix.tossOut( "records" ) );
           assert( gSix.tossOut( "shoes" ) == false);
           assert( gSix.size( ) == 4 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "records" ) == false );
           assert( gSix.find( "tables" ) );
           assert( gSix.find( "chairs" ) );
           assert( gSix.find( "boxes" ) );
           assert( gSix.find( "shoes" ) == false );
           assert( gSix.find( "shirts" ) == false );
           assert( gSix.find( "books" ) == false );
           assert( gSix.find( "suitcases" ) );

           assert( gSix.tossOut( "tables" ) );
           assert( gSix.tossOut( "boxes" ) );
           assert( gSix.tossOut( "suitcases" ) );
           assert( gSix.size( ) == 1 );
           assert( gSix.capacity( ) == 6 );
           assert( gSix.find( "records" ) == false );
           assert( gSix.find( "tables" ) == false );
           assert( gSix.find( "boxes" ) == false );
           assert( gSix.find( "shoes" ) == false );
           assert( gSix.find( "shirts" ) == false );
           assert( gSix.find( "books" ) == false );
           assert( gSix.find( "suitcases" ) == false );
           assert( gSix.find( "chairs" ) );
    
    // my garage test cases to supplement given driver code
    Garage g3(3);
    
    // test functions on empty garage
    assert(g3.use("0") == false);
    assert(g3.find("5") == false);
    assert( g3.size( ) == 0 );
    assert( g3.capacity( ) == 3 );
    
    // tossIn until it is full
    // then tossIn item when size=capacity to see if correct item is booted
    assert(g3.tossIn("1") == false);
    assert(g3.tossIn("2") == false);
    assert(g3.tossIn("3") == false);
    cout << g3.printItems();
    assert(g3.tossIn("4") == true);
    cout << g3.printItems();
    
    assert(g3.tossOut("3") == true);
    cout << g3.printItems();
    assert( g3.size( ) == 2 );
    
    
    assert(g3.use("2") == true);
    assert(g3.use("5") == false);
    cout << g3.printItems();
    assert( g3.capacity( ) == 3 );
    

           cout << "all tests passed!" << endl;
           return( 0 );
    
    
    //return( 0 );
}
