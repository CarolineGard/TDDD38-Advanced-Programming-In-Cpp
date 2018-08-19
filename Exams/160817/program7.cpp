#include <iomanip>
#include <vector>
#include <iterator>
#include <sstream>
#include <istream>
#include <ostream>
#include <iostream>

#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric> // accumulate


using namespace std;


int main()
{
    cout << "Enter values: ";
    vector<int> vals{istream_iterator<int>{cin}, istream_iterator<int>{}};
    size_t nr_elements{ vals.size() };
    size_t middle{ nr_elements / 2 };
    nth_element(begin(vals), begin(vals) + middle, end(vals));
    auto mean = accumulate(begin(vals), end(vals), 0.0) / nr_elements;
    auto median = static_cast<double>(vals.at(middle));
    if (nr_elements % 2 == 0 )
    {
        nth_element(begin(vals), begin(vals) + (middle - 1), end(vals));
        median = ( median + vals.at(middle - 1 )) / 2;
    }
    
    double diff{};
    for_each(begin(vals), end(vals),
             [&diff, mean](auto value)
             {
                 diff += pow(mean - value, 2.0);
             });
    
    auto sum = sqrt(diff / nr_elements);
    auto minmax = minmax_element(begin(vals), end(vals));
    
    cout << setfill('.') << setw(18) << left << "min value" << ": " << *minmax.first << "\n"
                         << setw(18) << "max value" << ": " << *minmax.second << "\n"
                         << setw(18) << "mean" << ": " << mean<< "\n"
                         << setw(18) << "median" << ": " << median << "\n"
                         << setw(18) << "standard deviation" << ": " << sum << "\n";
    return 0;
}
