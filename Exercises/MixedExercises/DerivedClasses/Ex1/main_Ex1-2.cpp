// EXERCISE - DERIVED CLASSES
/*
 1) Derive a direct subclasses to Base called Derived and declare a member function id() also in Derived,
    to print out "Derived". Write a program which declares ordinary object of Base and Derived and also declare
    Base and Derived pointers and let then point to dynamically allo- cates objects of type Base and Derived.
    Call id() for the different cases and especially note the printout for the case when a derived object is
    referred to by a base* pointer.
 2) Copy the program from step 1. Declare id() to be virtual in both Base and Derived and add a virtual destructor
    to Base, since this is now a polymorphic class hierarchy. Run the same test suite as in step 1. There should
    be at least some difference.
*/

#include <iostream>

using namespace std;

//Polymorphic class hierarchy
struct Base
{
    virtual ~Base() = default;
    virtual void id() const
    {
        cout << "Base" << endl;
    }
};

// Subclass
struct Derived final : public Base
{
    virtual void id() const
    {
        cout << "Derived" << endl;
    }
};


int main() {
    
    Base b1;
    b1.id();
    
    Derived d1;
    d1.id();
    
    Base *b2{ new Base{} };
    b2->id();
    delete b2;
    
    Derived *d2 { new Derived{} };
    d2->id();
    delete d2;
    
    Derived *d3 = new Derived{};
    d3->id();
    delete d3;
    
    /* // ex1, before virtual
    Base *b2;
    b2->id();
    delete b2;
    */
    
    /* ex1, before virtual
    Derived *d2;
    d2->id();
    delete d2;
    */
    
    
    return 0;
}











