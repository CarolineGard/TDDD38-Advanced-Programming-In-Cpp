
#include <iostream>

#include <string>

using namespace std;

// Ex 4
using unsigned_char                  = unsigned char;         // unsigned char
using const_unsigned_char            = const unsigned_char;   // const unsigned char;
using ptr_to_int                     = int*;                  // pointer to int
using ptr_to_ptr_to_char             = char**;                // pointer to pointer to char
using ptr_to_arr_of_char             = char*;                 // pointer to array with element of type char
using arr_of_10_ptr_to_int           = ptr_to_int[10];        // array with 10 pointer to int
using ptr_to_arr_of_10_ptr_to_int    = arr_of_10_ptr_to_int*; // pointer to an array with 10 pointer to int
using arr_of_20_of_arr_of_ptr_to_int = ptr_to_int[20][10];    // array 20 of array 10 with pointer to int

int main() {
    
    // ********** EXERCISE 3 **********
    
    // Pointer to char
    char ca = 'A';
    char *pa1 = &ca;
    char *pa2{ new char('C') };
    
    // Array with 10 ints
    int a[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    // Reference to array with 10 ints
    int &r1 = a[10];
    int (&r2)[10]{ a };
    
    // Pointer to array with 10 elements of type string
    std::string s[10] { "ss", "ss", "ss", "ss", "ss", "ss", "ss", "ss", "ss", "ss" };
    std::string *ps1 = &s[10];
    std:string (*ps2)[10]{ &s };
    
    // Pointer to a pointer to a char
    char cb = 'B';
    char *pb = &cb;
    char **pp1 = &pb;
    char **pp2{ &pa2 };
    
    // Constant int
    const int i1 = 1;
    const int i2{ 2 };
    
    // Pointer to constant int
    const int i3 = 3;
    const int *p1 = &i3;
    const int *p2{ &i3 };
    
    // Constant pointer to int
    int i4 = 3;
    int* const p3 = &i4;
    int* const p4{ &i4 };
    
    
    // ********** EXERCISE 4 **********
    
    unsigned_char uc{ 'a' }; // unsigned char
    
    const_unsigned_char cuc{ 'A' }; // const unsigned char
    
    ptr_to_int ptr1{ new int( 1 ) }; // pointer to int
    
    // pointer to pointer to char
    char *ptr2{ new char( 'b' ) };
    ptr_to_ptr_to_char ptr3{ &ptr2 };
    
    ptr_to_arr_of_char ptr_arr{ new char[10] }; // pointer to array with element of type char
    
    arr_of_10_ptr_to_int arr_ptr_int{ ptr1 }; //array with 10 pointer to int
    
    ptr_to_arr_of_10_ptr_to_int ptr_arr_ptr_int{ &arr_ptr_int }; // pointer to an array with 10 pointer to int
    
    //array 20 of array 10 with pointer to int
    arr_of_20_of_arr_of_ptr_to_int ptr_20_arr_ptr_int{ ptr1 };
    
    return 0;
    
}


















