//Container Design - STEP 5 - Types

#include "Container.h"
#include "Tracer.h"
#include <iostream>
#include <string>

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
    cout << "size: " << c7.size() << endl;
    c7.pop_back();
    cout << "size: " << c7.size() << endl;

    
    return 0;
}
