//
//  main.cpp
//  project2
//
//  Created by Sanjana Rathore on 10/19/23.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int modulo( unsigned int m, unsigned int n ) {
    if (m < n) {
        return m;
    }
    return modulo(m-n, n);
}

int occurrences (int number, int d) {
    if (number == 0 && d == 0) {
        return 1;
    }
    if (number == d) {
        return 1;
    }
    else if (number < 10) {
        return 0;
    }
    if (number%10 == d) {
        return 1 + occurrences(number/10,d);
    }
    else {
        return occurrences(number/10, d);
    }
    
}

string lucky7s( string s ) {
    if (s.size() <= 1) {
        return s;
    } else if (s.at(0) == 7){
        return s.at(0) + lucky7s(s.substr(1));
    } else if (s.at(0) == s.at(1)) {
        return s.substr(0,1) + "77" + lucky7s(s.substr(1));
    } else {
        return s.at(0) + lucky7s(s.substr(1));
    }
    
}
    
bool combinations( int array[], int size, int target ) {
        if (target == 0) {
            return true;
        }
        if (target != 0 && size == 0) {
            return false;
        }
        return combinations(array,size-1,target-array[size-1]) || combinations(array,size-1,target);
}
    
int main() {
        
        // test code
    
        // test modulo
        assert( modulo( 100, 10 ) == 0 );
        assert( modulo( 1, 13 ) == 1 );
        assert( modulo( 12, 5 ) == 2 );
        assert( modulo( 33, 6 ) == 3 );
    
        assert(modulo(10, 3) == 1);
        assert(modulo(1000000, 7) == 1);
        assert(modulo(0, 5) == 0);
        assert(modulo(15, 15) == 0);
        assert(modulo(3, 10) == 3);
        assert(modulo(42, 1) == 0);
        assert(modulo(11, 1000000) == 11);
        assert(modulo(1, 9999999) == 1);
        
        // test occuruences
        assert(occurrences(0, 0) == 1);
        assert(occurrences(1000, 0) == 3);
        assert( occurrences( 567, 2 ) ==  0 );
        assert( occurrences( 128874, 2 ) == 1 );
        assert( occurrences( 212121, 2 ) == 3 );
    
        assert(occurrences(12345, 3) == 1);   // The digit 3 occurs once
        assert(occurrences(101010, 0) == 3);  // The digit 0 occurs three times
        assert(occurrences(5555, 7) == 0);    // The digit 7 does not occur
        assert(occurrences(12345, 5) == 1);   // The digit 5 occurs once
        assert(occurrences(11111111, 1) == 8); // The digit 1 occurs eight times
        assert(occurrences(987654321, 0) == 0); // The digit 0 does not occur
        assert(occurrences(987654321, 9) == 1); // The digit 9 occurs once
        assert(occurrences(10001, 1) == 2);    // The digit 1 occurs two times
        
    // test lucky7s
        assert( lucky7s( "cs32" ) == "cs32" );
        assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
        assert( lucky7s( "abbba" ) == "ab77b77ba" );
        assert(lucky7s("hello") == "hel77lo");           // One pair of repeated characters
        assert(lucky7s("programming") == "program77ming"); // Two pairs of repeated characters
        assert(lucky7s("mississippi") == "mis77sis77sip77pi"); // Multiple pairs of repeated characters
        assert(lucky7s("abcdefg") == "abcdefg");          // No repeated characters
        assert(lucky7s("") == "");                        // Empty string
        
    // test combinations
        int array[ 5 ] = { 2, 4, 6, 8, 10 };
        assert( combinations( array, 5, 10 ) == true );
        assert( combinations( array, 5, 18 ) == true );
        assert( combinations( array, 5, 15 ) == false );
    
        int other[ 5 ] = { 10, 8, 2, 6, 4 };
        assert( combinations( other, 5, 10 ) == true );
        assert( combinations( other, 5, 18 ) == true );
        assert( combinations( other, 5, 15 ) == false );
    
    int arr1[] = {2, 3, 4};
    int size1 = 3;
    // assert(combinations(arr1, size1, 0) == false);  // edge case target = 0
    assert(combinations(arr1, size1, 2) == true);   // 2 is present in the array
    assert(combinations(arr1, size1, 3) == true);   // 3 is present in the array
    assert(combinations(arr1, size1, 4) == true);   // 4 is present in the array
    assert(combinations(arr1, size1, 5) == true);   // 2 + 3 = 5
    assert(combinations(arr1, size1, 6) == true);   // 2 + 4 = 6
    assert(combinations(arr1, size1, 7) == true);   // 3 + 4 = 7
    assert(combinations(arr1, size1, 9) == true);   // 2 + 3 + 4 = 9
    assert(combinations(arr1, size1, 12) == false); // No combination adds up to 12
    assert(combinations(arr1, size1, 16) == false); // No combination adds up to 16

    int arr2[] = {5, 5, 5, 5, 5};
    int size2 = 5;
    assert(combinations(arr2, size2, 10) == true);   // 5 + 5 = 10
    assert(combinations(arr2, size2, 20) == true);   // 5 + 5 + 5 + 5 = 20
    assert(combinations(arr2, size2, 15) == true);   // 5 + 5 + 5 = 15
    assert(combinations(arr2, size2, 17) == false);  // No combination adds up to 17

    int arr3[] = {1, 2, 3, 4, 5, 6};
    int size3 = 6;
    assert(combinations(arr3, size3, 12) == true);   // 6 + 4 + 2 = 12
    assert(combinations(arr3, size3, 9) == true);    // 6 + 3 = 9
    assert(combinations(arr3, size3, 15) == true);   // 6 + 5 + 4 = 15
    assert(combinations(arr3, size3, 14) == true);   // 6 + 4 + 3 + 1 = 14
    assert(combinations(arr3, size3, 23) == false);   // No combination adds up to 23
    
    int arr4[] = {3};
    assert(combinations(arr4,1,3) == true);
        
        cout << "all tests passed!" << endl;
        return( 0 );
}

