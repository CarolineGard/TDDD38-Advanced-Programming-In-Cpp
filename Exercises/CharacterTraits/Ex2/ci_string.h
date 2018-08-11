
#ifndef ci_string_h
#define ci_string_h

#include "ci_char_traits.h"
#include <iostream>
#include <string>
#include <iomanip>

typedef std::basic_string<char, ci_char_traits> ci_string;

std::ostream &operator<<(std::ostream &os, const ci_string &c)
{
    return os << c.c_str();
}

std::istream &operator>>(std::istream &is, ci_string &c)
{
    char buf[256];
    is >> std::setw(255) >> buf;
    c = buf;
    return is;
}


#endif /* ci_string_h */
