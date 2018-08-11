// EX 3 - Character Traits

/*
 Define a string type, sv_string, for char which will work properly for
 lexicographical comparison also if strings contain Swedish letters.
 Do this by defining a character traits sv_char_traits and specialize
 basic_string for char and sv_char_traits.
 
 Write a test program to test ci_string and, indirectly or explicitly,
 ci_char_traits. It shall also be possible to read ci_string values from
 istreams using operator >>, and to write ci_string values to ostreams
 using operator <<.
 
 Of course, you may do this for some other language than Swedish, if you
 prefer. Note: The Swedish alphabet comprise the letters a-z and å, ä, ö,
 in that order.
*/

#ifndef sv_char_traits_h
#define sv_char_traits_h

#include <string>
#include <cstring>


struct sv_char_traits : public std::char_traits<char>
{
    
    static bool lt(const char_type &c1, const char_type &c2)
    {
        if (std::strchr("ÄÅäå", c1) && std::strchr("ÄÅäå", c2))
            return std::strchr("ÅÄåä", c1) < std::strchr("ÅÄåä", c2);
        
        return ( static_cast<unsigned char>(c1) < static_cast<unsigned char>(c2) );
    }
    
    static int compare(const char_type* c1, const char_type* c2, size_t n)
    {
        for (size_t i = 0; i < n; ++i)
        {
            if (!eq(c1[i], c2[i]))
                return lt (c1[i], c2[i]) ? -1 : 1;
        }
        
        return 0;
    }

};





#endif /* sv_char_traits_h */




























