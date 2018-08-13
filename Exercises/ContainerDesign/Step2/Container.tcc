// member functions

#ifndef CONTAINER_TCC
#define CONTAINER_TCC

#include "Container.h"
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <new>
using namespace std;


//allocate_(n) shall allocate memory for n objects of type T,
//using array new; throw std::bad_alloc if n > max_size()
template <typename T>
T* Container<T>::allocate_(size_type n)
{
   if (n > max_size())
      throw std::bad_alloc();

   if (n > 0)
      return new T[n];
   
   else
      return nullptr;
}

// deallocate_(p) shall deallocating memory pointed to by p, 
//consistent with how allocation is done
template<typename T>
void Container<T>::deallocate_(T* start)
{
	delete[] start;
}

template <typename T>
Container<T>::Container(const size_type n)
{
	if (n > 0)
	{
		start_ = allocate_(n);
		finish_ = start_ + n;
    	end_of_storage_ = finish_;
	}
}

template<typename T>
T* Container<T>::allocate_and_copy(const Container &c)
{
	if (c.size() == 0)
		return nullptr;

	auto start_new = allocate_(c.size());

	try
	{
		std::copy(c.start_, c.finish_, start_new);
	}
	catch(...)
	{
		deallocate_(start_new);
		throw;
	}

	return start_new;
}

//Copy Constructor
template<typename T>
Container<T>::Container(const Container &c)
{
	if (c.size() > 0)
	{
		start_ = allocate_and_copy(c);
		finish_ = start_ + c.size();
		end_of_storage_ = finish_;
	}
}

// Move constructor
// Destination container is initialized to empty, content of c is moved to
// *this, other is set to empty.
template<typename T>
Container<T>::Container(Container && c) noexcept 
: start_{ c.start_ }, finish_{ c.finish_ }, end_of_storage_{ c.end_of_storage_ } 
{
	c.start_ = nullptr;
	c.finish_ = nullptr;
	c.end_of_storage_ = nullptr;
}

template<typename T>
Container<T>::~Container()
{
	deallocate_(start_);
}

// Copy assignment operator 
// Makes a deep copy of other container.
template<typename T>
Container<T> &Container<T>::operator=(const Container &c) & 
{
	if (*this != c)
	{
		if (c.size() > 0)
		{
			auto start_new = allocate_and_copy(c);
			deallocate_(start_);
			start_ = start_new;
			finish_ = start_ + c.size();
			end_of_storage_ = finish_;
		}
		else 
		{
			deallocate_(start_);
			start_ = nullptr;
			finish_ = nullptr;
			end_of_storage_ = nullptr;
		}
	}
	return *this; // safe, no copy involved
}

// Move assignment operator
// Deallocates memory for *this, copies the pointers from other to *this, and sets other to empty.
template<typename T>
Container<T> &Container<T>::operator=(Container &&c) & noexcept
{
	if (*this != &c)
	{
		deallocate_(start_);
		start_ = c.start_;
		finish_ = c.finish_;
		end_of_storage_ = c.end_of_storage_;
		c.start_ = nullptr;
		c.finish_ = nullptr;
		c.end_of_storage_ = nullptr;
	}
	return *this;
}


template<typename T>
typename Container<T>::size_type Container<T>::size() const noexcept
{
	return size_type(finish_ - start_);
}

//returns the maximum size 
//(max value of size_type) / sizeof(T)
template<typename T>
typename Container<T>::size_type Container<T>::max_size() const noexcept
{
	return size_type(-1) / sizeof(T);
}

// returns the current capacity, 
// i.e. the largest number of elements possible to store without increasing the current capacity
template<typename T>
typename Container<T>::size_type Container<T>::capacity() const noexcept
{
	return size_type( end_of_storage_ - start_ );
}


template<typename T>
bool Container<T>::empty() const noexcept
{
	return start_ == finish_;
}



#endif














