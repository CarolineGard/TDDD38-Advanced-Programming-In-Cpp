#include <stdexcept>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

template<typename T, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()>
class Modular
{
public:
    Modular(T val) : value_{val}
    {
        if (value_ > max || value_ < min)
            value_ = min;
    }
    
    operator T() const
    {
        return value_;
    }
    
    template<T other_min, T other_max>
    Modular<T, min, max> &operator+(Modular<T, other_min, other_max> const &t)
    {
        value_ += t;
        
        if (value_ > max)
            value_ = value_ - max + min;
        
        if (value_ < min)
            value_ = max - abs(value_ - min + 1);
        
        return *this;
    }
    
    Modular<T, min, max> &operator++()
    {
        if ( value_ == max )
            value_ = min;
        
        else
            ++value_;
        
        return *this;
    }
    
    Modular<T, min, max> &operator++(int)
    {
        auto temp = *this;
        ++*this;
        return temp;
    }
    
    Modular<T, min, max> &operator=(T const & t)
    {
        if (t < min || t > max)
            throw domain_error("Value out of range!");
            
        value_ = t;
        return *this;
    }
    
private:
    T value_;
};

int main()
{
    Modular<int, 2, 10> m{3};
    cout << m << endl;
    try
    {
        m = 1;
    }
    catch ( std::domain_error const & e)
    {
        cout << e.what() << endl;
    }
    cout << m << endl;
    Modular<int, 2,10> m2 {5};
    m = m + m2;
    cout << "Should be 8: " << m << endl;
    m = m + Modular<int,-11,-2>{-10};
    cout << "Should be 7: " << m << endl;
    cout << "Should print 7 9: " << m++ << " ";
    cout << ++m;
    Modular<char,'a','c'> mc{'b'};
    ++mc;
    cout << "\nShould print a: " << ++mc << endl;
}
