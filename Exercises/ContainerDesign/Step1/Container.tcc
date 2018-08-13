// member functions

#ifndef CONTAINER_TCC
#define CONTAINER_TCC

#include "Container.h"
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
Container<T>::~Container()
{
	deallocate_(start_);
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














