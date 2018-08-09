// EXERCISE - DERIVED CLASSES
/*
 4) Copy the program from step 3. Replace the typid expression and call to name() with a call to demangle_name(),
 which can be found from the course exercises home page.
 */
#include "demangle.h"

#include <iostream>

using namespace std;

//Polymorphic class hierarchy
struct Base
{
    virtual ~Base() = default;
    virtual void id() const
    {
        cout << demangle_name(typeid(*this)) << endl;
    }
};

// Subclass
struct Derived final : public Base { };


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
    
    return 0;
}
