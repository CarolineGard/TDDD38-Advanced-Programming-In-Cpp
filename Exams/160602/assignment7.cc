#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>
#include <sstream>
#include <ostream>

using namespace std;

using num_type = unsigned long long;

bool is_prime(num_type val, num_type divisor=2)
{
    if ( divisor*divisor > val )
    {
        return true;
    }
    if ( val % divisor == 0 )
    {
        return false;
    }
    return is_prime(val, ++divisor);
}


int main()
{
    vector<num_type> v(10);
    random_device rand;
    uniform_int_distribution<> dist{ 2, 75 };
    generate(begin(v), end(v), bind(dist, ref(rand)));
    v.erase(remove_if(begin(v), end(v),
                      [](auto value)
                      {
                          return !is_prime(value);
                      }));
    sort(begin(v), end(v));
    copy(begin(v), end(v), ostream_iterator<num_type>{cout, " " });
    
    cout << accumulate(begin(v), end(v), 1, multiplies<>{}) << endl;
    
    return 0;
}
