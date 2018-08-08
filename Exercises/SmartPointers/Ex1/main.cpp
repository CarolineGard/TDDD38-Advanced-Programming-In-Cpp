//
//  main.cpp
//  Exc_SmartPointers_1
//
//  Created by Caroline Gard on 2018-08-06.
//  Copyright © 2018 Caroline Gard. All rights reserved.
//

#include "smart_pointer.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Smart_Pointer;

int main(int argc, const char * argv[]) {

    cout << "Excercise 1" << endl;
    
    cout << "\n1. * and &" << endl;
    smart_pointer p0{ new int{ 5 } };
    cout << "Pointer p0: " << *p0 << endl;
    cout << "Address p0: " << &p0 << endl;
    
    //copy constructor
    cout << "\n2. Copy assignment operator" << endl;
    smart_pointer p1(p0);
    cout << "Pointer p1: " << *p1 << endl;
    
    //move constructor
    cout << "\n3. Move assignment operator" << endl;
    smart_pointer p2{ std::move(p0) };
    cout << "Pointer p2: " << *p2 << endl;
    
    // = operatoror
    cout << "\n4. = operator" << endl;
    cout << "p3 = p4" << endl;
    smart_pointer p3{ new int{2}};
    smart_pointer p4{ new int{7}};
    cout << "Pointer p3 and p4 before = , p3: " << *p3 << " p4: " << *p4 << endl;
    p3 = p4;
    cout << "Pointer p3 after = : " << *p3 << endl;
    
    cout << "\np = int" << endl;
    *p3 = 1024;
    cout << "Pointer p3: " << *p3 << endl;
    
    //Const smart pointer
    const smart_pointer p6{ new int{ 0xC1 } };
    //Not possible
    //cout << "Const pointer p6: " << *p6 << endl;
    p3 = p6;
    cout << "\nConst pointer p3: " << *p3 << endl;
    
    //operator ->()
    cout << "\n5. Using operator->()" << endl;
    cout << "p1: " << p1.operator->() <<  endl;
    
    //operator *()
    cout << "\n6. Using operator*()" << endl;
    cout << "p1: " << p1.operator*() <<  endl;
    
    
    
    return 0;
}









