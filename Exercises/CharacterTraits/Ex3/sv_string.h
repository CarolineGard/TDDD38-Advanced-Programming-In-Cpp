
#ifndef sv_string_h
#define sv_string_h

#include <iostream>
#include <string>
#include "sv_char_traits.h"

typedef std::basic_string<char, sv_char_traits> sv_string;

std::ostream &operator<<(std::ostream &os, const sv_string &s)
{
    return os << s.c_str();
}

std::istream &operator>>(std::istream &is, sv_string &s)
{
    std::string t;
    is >> t;
    s = t.c_str();
    return is;
}


#endif /* sv_string_h */
