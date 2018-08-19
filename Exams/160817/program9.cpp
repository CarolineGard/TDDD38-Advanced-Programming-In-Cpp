#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>

using namespace std;

// Utility class
template<typename T, typename Container = vector<T>>
class Cycler
{
public:
    Cycler(Container &c) : container_{ c }, current_{ c.begin() } {}
    
    T & next()
    {
        T & val = *current_;
        
        ++current_;
        if (current_ == container_.end())
            current_ = container_.begin();
        
        return val;
    }
    
    void reset ()
    {
        current_ = container_.begin();
    }
    
    size_t size() const
    {
        return container_.size();
    }
    
private:
    Container &container_;
    decltype(container_.begin()) current_;
};



int main()
{
    vector<int> numbers{ 1, 2, 3, 4, 5 };
    Cycler<int> cycler_nr{ numbers };
    
    vector<string> strings{"once", "upon", "a", "time"};
    Cycler<string> cycler_str{ strings };
    
    for (int i = 0; i < 14; i++)
        cout << cycler_nr.next() << ' ';
    
    for (int i = 0; i < 19; i++)
        cout << cycler_str.next() << ' ';
    
    
    return 0;
}
