// EXERCISE - INDEXABLE SET
/*
 Design an indexable set container, indexable_set, with the same functionality as std::set,
 but also with the possibility to access elements by index (position). If we declare
 indexable_set<int> ixs{ 3, 8, 2, 5, 1, 4, 7, 6, 9 };
 ixs will contain nine element, ordered from 1 to 9. Index expressions as the following are to be allowed:
 cout << ixs[0]; // 1 cout << ixs.at(8); // 9
 If an illegal index is given, both operator[] and at() shall throw std::out_of_range, with the message
 “indexable_set::operator[] out of range”.
 cout << ixs[9]; // throws out_of_range cout << ixs.at(-1); // throws out_of_range
 indexable_set shall be derived from std::set, be a template with the same template parameters,
 the same nested types, and the same operations as std::set.
 */

#ifndef indexable_set_h
#define indexable_set_h

#include <iostream>
#include <set>

using namespace std;

template<typename Key,
         typename Compare = std::less<Key>,
         typename Allocate = std::allocator<Key> >
struct indexable_set : public std::set<Key, Compare, Allocate>
{
    // Types
    using type_size = std::size_t; // Nested type_size to make it available in indexable_set
    using type_set  = std::set<Key, Compare, Allocate>;
    
    // Inherit some constructors
    // construct / copy / destroy /
    using std::set<Key, Compare>::set;
    
    const Key &operator[](type_size n) const
    {
        return at(n);
    }
    
    const Key &at(type_size n) const
    {
        if (n > type_set::size())
            throw std::out_of_range("indexable_set::operator[] out of range!");
        
        auto it = type_set::begin();
        std::advance(it, n);
        return *it;
    }
};

#endif /* indexable_set_h */
