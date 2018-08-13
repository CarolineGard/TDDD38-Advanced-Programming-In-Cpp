
#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstdlib>

using namespace std;

template<typename T>
class Container
{
public:
    
    //dealing with size implies the need for a suitable size type, which std::size_t (<cstdlib>) is:
    // define a nested type size_type to make it available as a Container related type
    using size_type = std::size_t;
    
    Container() noexcept = default; // default constructor to create an empty Container
    
    explicit Container(const size_type n); // constructor to create a Container with size n
    
    ~Container(); // destructor to do clean up
    
    size_type size() const noexcept; // returning current nr of elements
    size_type max_size() const noexcept; // returning max size((max value of size_type) / sizeof(T) )
    size_type capacity() const noexcept; // returning current capacity
    bool empty() const noexcept; // returns true if container is empty
    
    T* allocate_(size_type); // Allocate memory
    void deallocate_(T*); // Deallocate memory
    
private:
    T* start_         { nullptr };
    T* finish_        { nullptr };
    T* end_of_storage_{ nullptr };
};

#include "Container.tcc"

#endif












