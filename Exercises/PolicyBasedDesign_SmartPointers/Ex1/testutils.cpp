// EXERCISE - POLICY BASED DESIGN FOR SMART POINTERS (SP)
//For testing smart_pointer.

#include <iostream>
#include <iomanip>
#include "smart_pointer.h"

using namespace std;


//Functions for tracing object construction and destruction.

void trace_constructed(const char* type, int n_constructed, int n_destructed)
{
   cout << "  " << type << " object constructed: "
	<< n_constructed << " constructed, "
	<< n_destructed  << " destructed, "
	<< n_constructed - n_destructed << " remaining.\n";
}

void trace_destructed(const char* type, int n_constructed, int n_destructed)
{
   cout << "  " << type << " object destructed.: "
	<< n_constructed << " constructed, "
	<< n_destructed  << " destructed, "
	<< n_constructed - n_destructed << " remaining.\n";
}

// A simple class for testing smart_pointer and tracing objects.

struct X
{
public:
   X(int i) : m{ i } { trace_constructed("X", ++n_constructed, n_destructed); }
   X(const X& rhs) : m{ rhs.m } { trace_constructed("X", ++n_constructed, n_destructed); }
   ~X() { trace_destructed("X", n_constructed, ++n_destructed); }

   X* clone() const { return new X{ *this }; }
      
   int m;
   int get_m() { return m; }
private:
   static int n_constructed;
   static int n_destructed;
};

int X::n_constructed{ 0 };
int X::n_destructed{ 0 };

// Two simple classes for testing smart_pointers referring
// to polymorphic classes and tracing objects.

struct Base
{
public:
   Base(int i) : b{ i } {
      trace_constructed("Base", ++n_constructed, n_destructed);
   }
   Base(const Base& rhs) : b{ rhs.b } {
      trace_constructed("Base", ++n_constructed, n_destructed);
   }
   virtual ~Base() {
      trace_destructed("Base", n_constructed, ++n_destructed);
   }
   int b;
private:
   static int n_constructed;
   static int n_destructed;
};

int Base::n_constructed = 0;
int Base::n_destructed  = 0;

struct Derived : Base
{
public:
   Derived(int i, int j) : Base{ i }, d{ j } { 
      trace_constructed("Derived", ++n_constructed, n_destructed);
   }
   Derived(const Derived& rhs) : Base{ rhs.b }, d{ rhs.d } { 
      trace_constructed("Derived", ++n_constructed, n_destructed);
   }
   virtual ~Derived() {
      trace_destructed("Derived", n_constructed, ++n_destructed);
   }
   int d;
private:
   static int n_constructed;
   static int n_destructed;
};

int Derived::n_constructed{};
int Derived::n_destructed{};


// Functions for testing passing smart_pointers as parameter and returning smart_pointers.


// Function taking a smart pointer as a value parameter (copy in).

template<typename T>
void fun1(smart_pointer<T> sp)
{
   cout << "  fun1: entering\n";
   smart_pointer<T> local{ sp };
   if (sp.operator->() == 0)
      cout << "  fun1: Parameter is a null pointer after initializing local.\n";
   else
      cout << "  fun1: Parameter is NOT a null pointer after initializing local.\n";
   if (local.operator->() != 0)
      cout << "  fun1: local->m: " << hex << local->m << endl;
   else
      cout << "  fun1: Local is a null pointer.\n";
   cout << "  fun1: Leaving, local object will be destructed (not visible if null):\n";
}


// Function taking a smart pointer as a reference parameter.

template<typename T>
void fun2(smart_pointer<T>& sp)
{
   cout << "  fun2: Entering\n";
   smart_pointer<T> local{ sp };
   if (sp.operator->() == 0)
      cout << "  fun2: Parameter is a null pointer after initializing local.\n";
   else
      cout << "  fun2: Parameter is NOT a null pointer after initializing local.\n";
   if (local.operator->() != 0)
      cout << "  fun2: local->m: " << hex << local->m << endl;
   else
      cout << "  fun2: Local is a null pointer.\n";
   cout << "  fun2: Leaving, local object will be destructed (not visible if null):\n";
}

/*
 * Function taking a smart pointer as a const reference parameter.
 * A const smart_pointer cannot be used to initialize a local smart_pointer,
 * since it will not allow destructive copy.
 */
template<typename T>
void fun3(const smart_pointer<T>& sp)
{
   cout << "  fun3: Entering\n";

   if (sp.operator->() == 0)
      cout << "  fun3: Parameter is a null pointer.\n";
   else
      cout << "  fun3: Parameter is NOT a null pointer.\n";

   cout << "  fun3: Leaving\n";
}

/*
 * Function returning a smart pointer. This will easily cause problems, since
 * a temporary, at least semantically, is used in returning the smart_pointer,
 * and one often in the callee would like to use this object to initialize
 * or assign another smart_pointer. Since the copy constructor and the copy
 * assignment operator must have a non-const parameter if the smart pointer
 * implements destructive copy, they can not be used, since a temporary only
 * can be bound to a reference, if the reference is const.
 */
template<typename T>
smart_pointer<T> fun4()
{
   cout << "  fun4: Entering, initializing local smart_pointer object\n";
   smart_pointer<T> local{ new T{ 0xF4 } };
   cout << "  fun4: Leaving, returning local smart pointer object.\n";
   return local;
}










