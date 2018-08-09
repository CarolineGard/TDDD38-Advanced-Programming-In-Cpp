// EXERCISE - DERIVED CLASSES
/*
 3) Copy the program from step 2. Remove id() from Derived, leaving Derived empty. Modify Base::id() to print the
 “name” of the class by applying typeid to the object in question and calling member function name() for the
 type_info object the typeid expression creates. Run same test as prevously.
 */

#include <iostream>

using namespace std;

//Polymorphic class hierarchy
struct Base
{
    virtual ~Base() = default;
    virtual void id() const
    {
        cout << typeid(*this).name() << endl;
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












