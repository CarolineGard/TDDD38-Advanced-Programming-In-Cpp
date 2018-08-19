#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T, class Policy>
class Wrapper
{
public:
    Wrapper(const T &t) : value_{ t } {}
	
    void set(const T & t)
    {
        value_ = t;
    }
	
    T get() const
    {
        return value_;
    }
    
	std::string str() const;
    
private:
	T value_;
};

template<typename T, class Policy>
std::string Wrapper<T, Policy>::str() const
{
    return Policy::convert(value_);
}


// Policy classes
struct Hexadecimal
{
    template<typename T>
    static std::string convert(T const &val)
    {
        ostringstream os;
        os << "0x" << hex << val;
        return os.str();
    }
};

struct Quoted
{
    template<typename T>
    static std::string convert(T const &val)
    {
        ostringstream os;
        os << '"' << val << '"';
        return os.str();
    }
    
};


int main()
{
    Wrapper<int, Hexadecimal> h1{4711};
    cout << h1.str() << endl;
    
    Wrapper<int, Quoted> q1{4711};
    cout << q1.str() << endl;
    
    Wrapper<string, Hexadecimal> s1{"foobar"};
    cout << s1.str() << endl;
    
    Wrapper<string, Quoted> s2{"foobar"};
    cout << s2.str() << endl;
    
    return 0;
}


