/*
 * program8.cc
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Add and modify stuff according to given specifications. 

template<typename argument_type, typename return_type>
struct Round_Up
{
    static return_type round(argument_type val)
    {
        return ceil(val);
    }
};

template<typename argument_type, typename return_type>
struct Round_Down
{
    static return_type round(argument_type val)
    {
        return floor(val);
    }
};

template<typename argument_type, typename return_type>
struct Round_Towards_Zero
{
    static return_type round(argument_type val)
    {
        return val < 0 ? ceil(val) : floor(val);
    }
};

template<typename value_type, typename floating_type,
         template<typename, typename> class Rounding_Policy = Round_Towards_Zero>
class Number
{
public:
    Number(floating_type value = 0) : value_{ round(value) }{}

    value_type get_value() const { return value_; }
    void set_value(floating_type value)
    {
        value_ = round(value);
    }

private:
    value_type value_;
    value_type round(floating_type val)
    {
        return Rounding_Policy<floating_type, value_type>::round(val);
    }
};

void test_rounding(double value)
{
    // One object for each of the three rounding policies:
    static Number<int, double> n1;
    static Number<int, double, Round_Up> n2;
    static Number<int, double, Round_Down> n3;
    
    n1.set_value(value);
    n2.set_value(value);
    n3.set_value(value);

    cout << setw(11) << left << value 
         << setw(11) << n1.get_value()
         << setw(11) << n2.get_value() 
         << setw(11) << n3.get_value()
         << '\n';
}

int main()
{
    cout << fixed << setprecision(2) << showpos;
    cout << setw(11) << left << "Value"
         << setw(11) << "Down"
         << setw(11) << "Up"
         << setw(11) << "Towards 0"
         << "\n\n";
    
    test_rounding(9.67);
    test_rounding(9.5);
    test_rounding(9.35);
    test_rounding(9.0);
    test_rounding(0.0);
    test_rounding(-9.0);
    test_rounding(-9.25);
    test_rounding(-9.5);
    test_rounding(-9.67);

    return 0;
} 
