#include "smart_pointer.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Smart_Pointer;

int main()
{
    cout << "Exercise 2" << endl;
    
    smart_pointer p0{ new int{ 11 } };
    smart_pointer p1{ new int{ 22 } };

    //Comparing two smart pointers using ==, !=
    cout << "\n1. Comparing two smart pointers" << endl;
    //expected false
    if (p0 == p1) cout << "p0 == p1: true" << endl;
    else cout << "p0 == p1: false" << endl;
    
    //expected true
    if (p1 == p1) cout << "p1 == p1: true" << endl;
    else cout << "p1 == p1: false" << endl;
    
    //expected true
    if (p0 != p1) cout << "p0 != p1: true" << endl;
    else cout << "p0 != p1: false" << endl;
    
    //expected false
    if (p1 != p1) cout << "p1 != p1: true" << endl;
    else cout << "p1 != p1: false" << endl;
    
    
    
    //Comparing one smartpointer with one raw pointer
    int *p3 = new int{ 33 };
    
    cout << "\n2. Comparing one smartpointer with one raw pointer" << endl;
    //expected false
    if (p0 == p3) cout << "p0 == p3: true" << endl;
    else cout << "p0 == p3: false" << endl;
    
    //expected true
    if (p3 == p3) cout << "p3 == p3: true" << endl;
    else cout << "p3 == p3: false" << endl;
    
    //expected true
    if (p0 != p3) cout << "p0 != p3: true" << endl;
    else cout << "p0 != p3: false" << endl;
    
    //expected false
    if (p3 != p3) cout << "p3 != p3: true" << endl;
    else cout << "p3 != p3: false" << endl;

    
    //Comparing with empty pointer p4
    smart_pointer p4;
    
    cout << "\n3. Comparing one smartpointer with empty pointer" << endl;
    //expected true
    if (p4 == nullptr) cout << "p4 == nullptr: true" << endl;
    else cout << "p0 == nullptr: false" << endl;
    
    //expected true
    if (nullptr == p4) cout << "nullptr == p4: true" << endl;
    else cout << "nullptr == p4: false" << endl;
    
    //expected false
    if (p1 == nullptr) cout << "p4 == nullptr: true" << endl;
    else cout << "p1 == nullptr: false" << endl;
    
    //expected false
    if (nullptr == p1) cout << "nullptr == p1: true" << endl;
    else cout << "nullptr == p1: false" << endl;
    
    
    
    //expected false
    if (p4 != nullptr) cout << "p4 =! nullptr: true" << endl;
    else cout << "p0 =! nullptr: false" << endl;
    
    //expected false
    if (nullptr != p4) cout << "nullptr != p4: true" << endl;
    else cout << "nullptr != p4: false" << endl;
    
    //expected true
    if (p1 != nullptr) cout << "p4 != nullptr: true" << endl;
    else cout << "p1 != nullptr: false" << endl;
    
    //expected true
    if (nullptr != p1) cout << "nullptr != p1: true" << endl;
    else cout << "nullptr != p1: false" << endl;
    
    
    //expected false
    if (!p1) cout << "!p1: true" << endl;
    else cout << "!p1: false" << endl;
    
    //expected true
    if (!p4) cout << "!p4: true" << endl;
    else cout << "!p4: false" << endl;

    
    return 0;
}
