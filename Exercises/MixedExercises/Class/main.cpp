// EXERCISE CLASS

#include <iostream>

using namespace std;

class Integer
{
public:
    Integer() = default;
    Integer(int i) : i_{ i } {}
    Integer(const Integer &integ) : i_( integ.i_ ) {}
    
    //~Integer() = default;
    
    // Binary
    friend Integer operator+(const Integer il, const Integer ir);
    friend Integer operator-(const Integer il, const Integer ir);
    friend Integer operator*(const Integer il, const Integer ir);
    friend Integer operator/(const Integer il, const Integer ir);
    friend Integer operator%(const Integer il, const Integer ir);
    
    // Unary - changes signs for of its arguments
    Integer operator+();
    Integer operator-();
    
    Integer operator++(); //prefix increment
    Integer operator++(int); //postfix increment
    Integer operator--(); //prefix decrement
    Integer operator--(int); //postfix decrement
    
    friend ostream& operator<<(ostream &os, const Integer i );
    friend istream& operator>>(istream &is, Integer i );
    
private:
    int i_;
};

Integer operator+(const Integer il, const Integer ir)
{
    return Integer(il.i_ + ir.i_);
}

Integer operator-(const Integer il, const Integer ir)
{
    return Integer(il.i_ - ir.i_);
}

Integer operator*(const Integer il, const Integer ir)
{
    return Integer(il.i_ * ir.i_);
}

Integer operator/(const Integer il, const Integer ir)
{
    return Integer(il.i_ / ir.i_);
}

Integer operator%(const Integer il, const Integer ir)
{
    return Integer(il.i_ % ir.i_);
}

Integer Integer::operator+()
{
    return Integer(i_);
}

Integer Integer::operator-()
{
    return Integer(-i_);
}

// prefix
Integer Integer::operator++()
{
    ++i_;
    return *this;
}

// postfix
Integer Integer::operator++(int)
{
    Integer temp(i_);
    ++i_;
    return temp;
}

// prefix
Integer Integer::operator--()
{
    --i_;
    return *this;
}

// postfix
Integer Integer::operator--(int)
{
    Integer temp(i_);
    ++i_;
    return temp;
}

ostream& operator<<(ostream &os, const Integer i)
{
    return os << i.i_;
}

istream& operator>>(istream &is, Integer i)
{
    return is >> i.i_;
}


int main() {

    Integer int_1{ 32 };
    Integer int_2{ 3 };
    
    cout << "int_1 = " << int_1 << endl;
    cout << "int_2 = " << int_2 << endl;
    cout << "++int_1 = " << ++int_1 << endl;
    cout << "int_1++ = " << int_1++ << endl;
    cout << "int_1 + 4 = " << int_1 + 4 << endl;
    cout << "int_1 + int_2 = " << int_1 + int_2 << endl;
    
    cout << "\nint_1 = " << int_1 << endl;
    cout << "int_2 = " << int_2 << endl;
    cout << "--int_1 = " << --int_1 << endl;
    cout << "int_1-- = " << int_1-- << endl;
    cout << "int_1 - 20 = " << int_1 - 20 << endl;
    cout << "int_1 - int_2 = " << int_1 - int_2 << endl;
    
    cout << "\nint_1 * 4 = " << int_1 * 4 << endl;
    cout << "int_1 * int_2 = " << int_1 * int_2 << endl;
    
    cout << "\nint_1 / 3 = " << int_1 / 2 << endl;
    cout << "int_1 / int_2 = " << int_1 / int_2 << endl;
    
    cout << "\nint_1 % 3 = " << int_1 % 2 << endl;
    cout << "int_1 % int_2 = " << int_1 % int_2 << endl;
    
    cout << "\nint_1 + 'A' = " << int_1 + 'A' << endl;
    cout << "\nint_1 - 'c' = " << int_1 - 'c' << endl;
    
    return 0;
}









