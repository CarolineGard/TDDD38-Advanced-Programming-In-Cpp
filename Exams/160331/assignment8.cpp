#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main()
{
    //1. Read the two integers N and T using standard formatted input.
    int N, T;
    cin >> N >> T;
    
    //2. Create a vector, called input_values to store the range A.
    vector<int> input_values(N);
    
    //3. Read the N integers and store them in input_values.
    copy_n(istream_iterator<int>{cin}, N, begin(input_values));
    
    //4. Create a new vector sums.
    vector<int> sums(N);
    
    //5. Calculate the accumulated sums from input_values so that index i in sums contains the sum of all values of input_values in the index range [0, i].
    partial_sum(begin(input_values), end(input_values), begin(sums));
    
    //6. For each of the T remaining integers (it’s okay to read to end of input), print index t-1 from sums to cout.
    for_each(istream_iterator<int>{cin}, istream_iterator<int>{},
             [=](int t)
             {
                 cout << sums[t-1] << endl;
             });
    
    return 0;
}
