//
/*
 Define a string type, sv_string, for char which will work properly for
 lexicographical comparison also if strings contain Swedish letters.
 Do this by defining a character traits sv_char_traits and specialize
 basic_string for char and sv_char_traits.
 
 Write a test program to test ci_string and, indirectly or explicitly,
 ci_char_traits. It shall also be possible to read ci_string values from
 istreams using operator >>, and to write ci_string values to ostreams
 using operator <<.
 
 Of course, you may do this for some other language than Swedish, if you
 prefer. Note: The Swedish alphabet comprise the letters a-z and å, ä, ö,
 in that order.
 */

#include "sv_string.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    sv_string s1 = "Åsa";
    sv_string s2 = "Åka";
    sv_string s3 = "Häjsan";
    sv_string s4 = "Göran";
    
    cout << s1 << " < " << s2  << " : " << (s1 < s2) << endl;
    cout << s2 << " < " << s1  << " : " << (s2 < s1) << endl;
    cout << s1 << " < " << s3  << " : " << (s1 < s3) << endl;
    cout << s3 << " < " << s1  << " : " << (s3 < s1) << endl;
    
    cout << s3 << " == " << s1  << " : " << (s3 < s1) << endl;
    cout << s1 << " == " << s1  << " : " << (s1 < s1) << endl;
    
    
    cout << "A : " << static_cast<int>( static_cast<unsigned char>('A') ) << " < "
         << "a : " << static_cast<int>( static_cast<unsigned char>('a') ) << "\n";
    
    cout << "A : " << static_cast<int>( static_cast<unsigned char>('A') ) << endl;
    
    cout << "A : " << static_cast<int>('A') << endl;
    cout << "a : " << static_cast<int>('a') << endl;
    //cout << "Å : " << static_cast<int>(static_cast<unsigned char>('Å')) << endl;
    //cout << "å : " << static_cast<int>('ä') << endl;
    //cout << "ö < å :" << sv_char_traits::lt('ö', 'å') << endl;
    
    return 0;
}





































