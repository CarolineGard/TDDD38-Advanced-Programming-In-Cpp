// member functions

#ifndef CONTAINER_TCC
#define CONTAINER_TCC

#include "Container.h"

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <new>

using namespace std;


// computes a new, larger capacity, allocate new storage, insert x at its proper place, 
// copy the already stored elements to the new storage, and, if all goes well, delete 
// the old memory and set start_, finish_, and end_of_storage_ to proper values.
template<typename T>
typename Container<T>::size_type Container<T>::compute_capacity_() const
{
	if (capacity() == size_type(-1))
		throw std::length_error{ "Container capacity is exhausted!" };

	else if (capacity() >= (size_type(-1) / 2))
		return size_type(-1);

	return capacity() == 0 ? 1 : 2 * capacity();
}

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
void Container<T>::deallocate_(pointer start)
{
	delete[] start;
}

template<typename T>
T* Container<T>::allocate_and_copy(const Container &c)
{
	if (c.size() == 0)
		return nullptr;

	T *start_new = allocate_(c.size());

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


template<typename T>
void Container<T>::resize_(const_reference t)
{
	size_type size_old = capacity();
	size_type size_new = compute_capacity_();
	T *start = allocate_(size_new);	

	try 
	{
		*(start + size_old) = t;
		std::copy(start_, finish_, start);
	}
	catch(...)
	{
		deallocate_(start);
		throw;
	}

	delete[] start_;
	start_  = start;
	finish_ = start_ + size_old;
	end_of_storage_ = start_ + size_new;
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
Container<T>::Container(Container &&c) noexcept 
{
	swap(c);
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
	if (this != &c)
	{
		Container{ c }.swap(*this);
		//auto start_new = allocate_and_copy(c);
		//deallocate_(start_);
		//start_ = start_new;
		//finish_ = start_ + c.size();
		//end_of_storage_ = finish_;
	}
	return *this; // safe, no copy involved
}

// Move assignment operator
// Deallocates memory for *this, copies the pointers from other to *this, and sets other to empty.
template<typename T>
Container<T> &Container<T>::operator=(Container &&c) & noexcept
{
	if (this != &c)
	{
		clear();
		swap(c);
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


// Destroys all elements
template<typename T>
void Container<T>::clear() noexcept
{
	deallocate_(start_);
	start_ = nullptr;
	finish_ = nullptr;
	end_of_storage_ = nullptr;
}

// exchange the contents of two containers, both member and non-member version.
template<typename T>
void Container<T>::swap(Container &c) noexcept
{
	std::swap(start_, c.start_);
	std::swap(finish_, c.finish_);
	std::swap(end_of_storage_, c.end_of_storage_);
}

template<typename T>
void Container<T>::swap(Container<T> &c1, Container<T> &c2) noexcept
{
	c1.swap(c2);
}

// push_back(x) shall insert x at the end of the container, after increasing capacity 
// when required. push_back() should be overloaded for both copy and move semantics, 
// but skip the latter, for now at least.
template<typename T>
void Container<T>::push_back(const_reference t)
{
	if (size() == capacity())
		resize_(t);

	else 
		*finish_ = t;

	++finish_;
}

// back() shall return the last element in the container, 
// without removing it. If the container is empty no exception is to be thrown, a
// ccording to standard container semantics..
// For non- const container:
template<typename T>
typename Container<T>::reference Container<T>::back()
{
	auto tmp = finish_;
	--tmp;
	return *tmp;
}

// For const container:
template<typename T>
typename Container<T>::const_reference Container<T>::back() const
{
	auto tmp = finish_;
	--tmp;
	return *tmp;
}

// pop() shall remove the last object in the container. If the container is empty no 
// exception is to be thrown, according to standard container semantics.
template<typename T>
void Container<T>::pop_back() noexcept
{
	--finish_;
	finish_->~T();
}

template<typename T>
typename Container<T>::iterator Container<T>::begin() noexcept
{
	return iterator(start_);
}

template<typename T>
typename Container<T>::const_iterator Container<T>::begin() const noexcept
{
	return const_iterator(start_);
}

template<typename T>
typename Container<T>::iterator Container<T>::end() noexcept
{
	return iterator(finish_);
}

template<typename T>
typename Container<T>::const_iterator Container<T>::end() const noexcept
{
	return const_iterator(finish_);
}

template<typename T>
typename Container<T>::const_iterator Container<T>::cbegin() const noexcept
{
	return const_iterator(start_);
}

template<typename T>
typename Container<T>::const_iterator Container<T>::cend() const noexcept
{
	return const_iterator(finish_);
}

template<typename T>
typename Container<T>::reverse_iterator Container<T>::rbegin() noexcept
{
	return reverse_iterator(end());
}

template<typename T>
typename Container<T>::const_reverse_iterator Container<T>::rbegin() const noexcept
{
	return const_reverse_iterator(end());
}

template<typename T>
typename Container<T>::reverse_iterator Container<T>::rend() noexcept
{
	return reverse_iterator(begin());
}

template<typename T>
typename Container<T>::const_reverse_iterator Container<T>::rend() const noexcept
{
	return const_reverse_iterator(begin());
}


// TODO : solve error
template <typename T>
typename Container<T>::const_reverse_iterator Container<T>::crbegin() const noexcept
{
   return const_reverse_iterator(end());
}

// TODO : solve error
template <typename T>
typename Container<T>::const_reverse_iterator Container<T>::crend() const noexcept
{
   return const_reverse_iterator(begin());
}


#endif
























