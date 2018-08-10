// EXERCISE - POLICY BASED DESIGN FOR SMART POINTERS (SP)

#include <iostream>
#include "smart_pointer.h"
#include "testutils.cpp"

using namespace std;

#ifdef ALLOW_CONVERSION
    typedef smart_pointer<X, allow_conversion> Smart_Pointer;
#else
    typedef smart_pointer<X, disallow_conversion> Smart_Pointer;
#endif

int main()
{
   smart_pointer<X> sp1;

   smart_pointer<X> sp2{ new X{ 1 } };  // One X is created here.

   smart_pointer<X> sp3{ sp2 };       // An X is copied here (we now have two X).

   cout << "sp2->get_m(): " << sp2->get_m() << endl;
   cout << "sp3->get_m(): " << sp3->get_m() << endl;

   sp1 = sp3;                       // An X is copied here (we now have three X).

   cout << "sp3->get_m(): " << sp3->get_m() << endl;
   cout << "sp1->get_m(): " << sp1->get_m() << endl;
   cout << "sp2->get_m(): " << sp2->get_m() << endl;

   return 0;                       // Three X are now to be destructed.
}
