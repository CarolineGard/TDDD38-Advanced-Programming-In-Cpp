// Ex- Case-insensitive string type

/*
 Define a string type, ci_string, for char which is not case-sensitive.
 Do this by defining a character traits class ci_char_traits and specialize
 basic_string for char and ci_char_traits.
 
 Write a test program to test ci_string and, indirectly or explicitly,
 ci_char_traits. It shall also be possible to read ci_string values from
 istreams using operator >>, and to write ci_string values to ostreams using
 operator <<.
 
 Hint: Most of the functions defined in std::char_traits<char> are case-insensitive ...
 */

#include "ci_string.h"
#include <iostream>

using namespace std;

int main() {

    ci_string s1 = "HELLO";
    ci_string s2 = "hello";
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    
    if (s1 == s2)
        cout << "Equality case insensitive" << endl;
    else
        cout << "Equality case sensitive" << endl;  
    
    
    ci_string s3;
    cout << "\nWrite something: ";
    cin >> s3;
    cout << s3 << endl;
    
    
    return 0;
}



















