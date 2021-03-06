//Container Design - STEP 8 - Placement push_back
/*
Placement insert is about inserting an object without having to first create the object separately,
and then copy or move it into a container. This requires the ability to supply an arbitrary number
of constructor arguments to the placement insert operation, which is facilitated by variadic
templates and perfect forwarding, which is facilitated by std::forward().
*/
#include "Container.h"
#include "Tracer.h"
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

using Trace = Tracer<string>;

int main() {

    Trace::on();
    
    Container<Trace> c1; //Default initialized
    cout << "-- Default initialized -- " << endl;
    cout << "size: " << c1.size() << endl;
    cout << "max size: " << c1.max_size() << endl;
    cout << "capacity: " << c1.capacity() << endl;
    cout << "empty: " << c1.empty() << '\n' << endl;
    
    Container<Trace> c2{ 5 }; //5 default initialized objects
    cout << "\n\n-- 5 Default initialized -- " << endl;
    cout << "size: " << c2.size() << endl;
    cout << "max size: " << c2.max_size() << endl;
    cout << "capacity: " << c2.capacity() << endl;
    cout << "empty: " << c2.empty() << endl;
    
    //Copy constructor, c3 is initialized with c2
    Container<Trace> c3{ c2 };
    cout << "\n\n-- copy constructor -- " << endl;
    cout << "size: " << c3.size() << endl;
    cout << "max size: " << c3.max_size() << endl;
    cout << "capacity: " << c3.capacity() << endl;
    cout << "empty: " << c3.empty() << endl;
    
    //Copy assignment operator
    cout << "\n\n-- copy assignment operator -- " << endl;
    Container<Trace> c4 = c2;
    cout << "size: " << c4.size() << endl;
    cout << "max size: " << c4.max_size() << endl;
    cout << "capacity: " << c4.capacity() << endl;
    cout << "empty: " << c4.empty() << endl;
    
    //Move constructor
    Container<Trace> c5{ std::move(c2) };
    cout << "\n\n-- move constructor -- " << endl;
    cout << "size: " << c5.size() << endl;
    cout << "max size: " << c5.max_size() << endl;
    cout << "capacity: " << c5.capacity() << endl;
    cout << "empty: " << c5.empty() << endl;
    
    //Move assignment operator
    Container<Trace> c6 = std::move(c4);
    cout << "\n\n-- move assignment operator -- " << endl;
    cout << "size: " << c6.size() << endl;
    cout << "max size: " << c6.max_size() << endl;
    cout << "capacity: " << c6.capacity() << endl;
    cout << "empty: " << c6.empty() << endl;
    
    // c3.swap(c2);
    c3.swap(c2);
    cout << "\n\n-- c3.swap(c2) -- " << endl;
    cout << "size: " << c3.size() << endl;
    cout << "max size: " << c3.max_size() << endl;
    cout << "capacity: " << c3.capacity() << endl;
    cout << "empty: " << c3.empty() << endl;
    
    // swap(c5, c4);
    swap(c5, c4);
    cout << "\n\n-- swap(c5, c4) -- " << endl;
    cout << "size: " << c5.size() << endl;
    cout << "max size: " << c5.max_size() << endl;
    cout << "capacity: " << c5.capacity() << endl;
    cout << "empty: " << c5.empty() << endl;
    
    // pop back
    Container<Trace> c7{ 5 };
    Trace hi{ "hi" };
    c7.back();
    c7.push_back(hi);
    cout << "size: " << c7.size() << endl;
    c7.pop_back();
    cout << "size: " << c7.size() << endl;
    
    
    ////////////////////////////////////////////
    
    Container<Trace> t1;
    
    Trace one{ "one" };
    Trace two{ "two" };
    Trace three{ "three" };
    Trace four{ "four" };
    
    t1.push_back(one);
    t1.push_back(two);
    t1.push_back(three);
    t1.push_back(four);
    t1.push_back(Trace( "five" ));
    
    cout << "t1 size: " << t1.size() << endl;
    cout << "t1 max size: " << t1.max_size() << endl;
    cout << "t1 capacity: " << t1.capacity() << endl;
    cout << "t1 empty: " << t1.empty() << endl;
    
    cout << "List of Container t1:" << endl;
    for (auto &x : t1)
    {
        cout << x << endl;
    }
    
    const Container<Trace> ct1{ t1 };
    cout << "List of const Container ct1:" << endl;
    for (auto it = ct1.begin(); it != ct1.end(); ++it)
    {
        cout << *it << endl;
    }
    
    cout << "List of const Container ct1 in reverse:" << endl;
    for (auto it = ct1.crbegin(); it != ct1.crend(); ++it)
    {
        cout << *it << endl;
    }
    
    return 0;
}


