//Container Design - STEP 1 - Initialization and Destroying

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
    cout << "-- 5 Default initialized -- " << endl;
    cout << "size: " << c1.size() << endl;
    cout << "max size: " << c1.max_size() << endl;
    cout << "capacity: " << c1.capacity() << endl;
    cout << "empty: " << c1.empty() << endl;
    
    
    return 0;
}
