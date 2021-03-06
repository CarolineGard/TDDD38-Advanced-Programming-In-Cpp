
#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstdlib>

using namespace std;

template<typename T>
class Container
{
public:
    
    // dealing with size implies the need for a suitable size type, which std::size_t (<cstdlib>) is:
    // define a nested type size_type to make it available as a Container related type
    using size_type       = std::size_t;
    using value_type      = T;
    using pointer         = value_type*;
    using const_pointer   = const value_type*;
    using reference       = value_type&;
    using const_reference = const value_type&;
    
    Container() noexcept = default;         // default constructor to create an empty Container
    explicit Container(const size_type n);  // constructor to create a Container with size n
    Container(const Container &);           // Copy Constructor
    Container(Container &&) noexcept;       // Move Constructor
    
    ~Container();                           // destructor to do clean up
    
    Container &operator=(const Container &) &;       //Copy Assignment operator
    Container &operator=(Container &&) & noexcept;   //Move Assignment operator
    
    size_type size() const noexcept;        //  current nr of elements
    size_type max_size() const noexcept;    //  max size((max value of size_type) / sizeof(T) )
    size_type capacity() const noexcept;    //  current capacity
    bool empty() const noexcept;            // returns true if container is empty
    
    void clear() noexcept; // clears the container, reset it to an empty container
    void swap(Container &c) noexcept;  // exchange the contents of two containers
    void swap(Container<T> &c1, Container<T> &c2) noexcept;
    
    void  push_back(const_reference);
    reference back();
    const_reference back() const;
    void  pop_back() noexcept;
    
 private:
    pointer start_{ nullptr };
    pointer finish_{ nullptr };
    pointer end_of_storage_{ nullptr };
    
    size_type compute_capacity_() const;
    
    T* allocate_(size_type);               // Allocate memory
    void deallocate_(pointer);             // Deallocate memory
    T* allocate_and_copy(const Container &c); // Allocate memory and copy
    
    void resize_(const_reference);
};

#include "Container.tcc"

#endif












