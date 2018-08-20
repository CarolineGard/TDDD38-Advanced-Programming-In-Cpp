#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

struct format_container
{
    format_container(char delim = '[')
    {
        if (delim == '{')
        {
            start_ = '{';
            end_ = '}';
        }
    }
    
    mutable ostream* os_ptr{};
    char start_{'['};
    char end_{']'};
};

format_container const &operator<<(ostream &os, format_container const &fc )
{
    fc.os_ptr = &os;
    return fc;
}

template<typename T>
ostream &operator<<(format_container const & fc, T const &values)
{
    *fc.os_ptr << fc.start_;
    bool start{true};
    for ( auto x : values )
    {
        if (start)
        {
            *fc.os_ptr << x;
            start = false;
        }
        else
            *fc.os_ptr << ", " << x;
    }
    *fc.os_ptr << fc.end_; // OBS CHANGE
    return *fc.os_ptr;
}


int main()
{
    // Part a
    vector<int> vec {2, 5, 1, 7, 10};
    cout << format_container() << vec << endl;
    cout << format_container('{') << vec << endl;

    // part b
    list<string> lst{"hi", "does", "this", "work?"};
    forward_list<int> fl{3,65,1,8};
    cout << format_container() << lst << "\n"
         << format_container() << fl << endl;
    
}
