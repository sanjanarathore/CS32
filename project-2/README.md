In this assignment, I implemented 4 different recursive functions in C++.

*int modulo( unsigned int m, unsigned int n )*
- Returns the remainder of two positive integers, m and n.  The scorer will never send your code an n value of zero but you maybe sent an m value of zero.

*int occurrences( int number, int d )*
- Returns the number of occurrences of the value d found in the parameter number.  You can safely assume that the value of d will be single digit number.  For occurrences, either parameter may be 0.  Be careful not to / or % by zero as that won't work.  Instead, a zero value should be one of your base cases that stops the recursive function calls.  You can assume both parameters will be zero or more.  As for occurrences(0, 0), the scorer will accept the value either zero or one as the answer.

*string lucky7s( string s )*
- Returns a string where repeated matching characters in the value s get separated by the string "77".  You can assume that the input string s will not have any 7's in it.

*bool combinations( int array[ ], int size, int target )*
- Returns true if the total of any combination of elements in the array parameter equals the target value.  In determining combinations, each element value should only be used once.  For array of {2, 3, 4}, you could build target values of only 2, 3, 4, 5 (2+3), 6 (2+4), 7 (3+4) or 9 (2+3+4) only and not 12 (3+3+3+3) or 16 (4+4+4+4).

