#include <iostream>
#include <vector>
#include <iterator>
#include <list>

using namespace std;

// Policy classes

// sort in ascending order, as in the sort function
struct Ascending
{
    template<typename T>
    static bool less(T const &lhs, T const &rhs)
    {
        return lhs < rhs;
    }
    
};

// Descending order, baklänges
struct Descending
{
    template<typename T>
    static bool less(T const &lhs, T const &rhs)
    {
        return lhs > rhs;
    }
};

// Sort
template<typename T, class Policy = Ascending>
struct Sort
{
    template<typename Iter>
    static void sort(Iter begin, Iter end)
    {
        for(; next(begin) != end; ++begin)
        {
            Iter value = begin;
            for (Iter pos = begin; pos != end; ++pos)
            {
                if (Policy::less(*pos, *begin))
                    value = pos;
                
                std::iter_swap(begin, value);
            }
        }
    }
};

template<typename Content>
void print(Content &c)
{
    for (auto x : c)
        cout << x << ' ';
    cout << endl;
}

int main()
{
    int arr[] = { 2,3,5,1,6,8 };
    Sort<int, Ascending>::sort(begin(arr), end(arr));
    print(arr);
    
    vector<int> values { 2, 3, 6, 8, 3};
    Sort<int, Ascending>::sort(begin(values), end(values));
    print(values);
    
    list<string> words {"hi", "hello", "all", "students"};
    Sort<string, Descending>::sort(begin(words), end(words));
    print(words);
}
