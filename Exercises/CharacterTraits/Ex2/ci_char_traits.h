// Ex- Case-insensitive string type

/*
 Define a string type, ci_string, for char which is not case-sensitive.
 Do this by defining a character traits class ci_char_traits and specialize
 basic_string for char and ci_char_traits.
 
 Write a test program to test ci_string and, indirectly or explicitly,
 ci_char_traits. It shall also be possible to read ci_string values from
 istreams using operator >>, and to write ci_string values to ostreams using
 operator <<.
 
 Hint: Most of the functions defined in std::char_traits<char> are case-insensitive ...
 */

#ifndef ci_char_traits_h
#define ci_char_traits_h

#include <string>
#include <cstring>

//template<typename charS> ci_char_traits;


//Case insensitive traits for char
struct ci_char_traits : public std::char_traits<char>
{
    //not depending on upper or lower case
    static bool eq(char &c1, char &c2)
    {
        return tolower(c1) == tolower(c2);
    }
    
    static bool lt(char &c1, char &c2)
    {
        return tolower(c1) < tolower(c2);
    }
    
    static int compare(const char *s1, const char *s2, const size_t n)
    {
        return strncasecmp(s1, s2, n);
    }
    
    static const char *find(char *s, char &c, int n)
    {
        while (n-- > 0 && tolower(*s) != tolower(c))
            ++s;
        
        return s;
    }
};


#endif /* ci_char_traits_h */
