
/*
 EX 1.
 
 Start with the helper function copy(), which shall implement the copy semantics. Use copy to implement
 other member functions which are to create copies.
 
 • copy() shall copy of the object the parameter refers to and assign ptr_ in the current object a pointer to the copy.
   copy() shall return nothing. The parameter can be a null smart pointer.
 • the constructor taking a raw pointer of type int* shall initialize the smart pointer object with the raw pointer.
 • the copy constructor shall implement copy on create/assign.
 • the move constructor shall implement move semantics.
 • the destructor shall deallocate the memory for the referred object, if there is such.
 • the copy assignment operator shall perform assignment, according to the semantics for copy on create/ assign.
 • the move assignment operator shall implement move semantics.
 • operator*() shall return a reference to the referred object.
 • operator->() shall return the pointer ptr_.
 
 */

#ifndef smart_pointer_h
#define smart_pointer_h
#include <iostream>


#endif /* smart_pointer_h */

namespace Smart_Pointer {
    
    class smart_pointer {

    public:
        smart_pointer() = default;
        
        smart_pointer(int *p) : ptr_{ p } {}
        
        smart_pointer(const smart_pointer &p1)
        {
            copy(p1);
        }
        
        smart_pointer(smart_pointer&& p1) noexcept
        {
            swap(p1);
        }
        
        ~smart_pointer()
        {
            delete ptr_;
        }
        
        smart_pointer& operator=(const smart_pointer& p)
        {
            smart_pointer{ p }.swap(*this);
            return *this;
        }
        
        
        smart_pointer& operator=(smart_pointer&& p) noexcept
        {
            if (this != &p)
            {
                clear();
                swap(p);
            }
            return *this;
        }
        
        smart_pointer& operator=(int *value)
        {
            smart_pointer{ value }.swap(*this);
            return *this;
        }
        
        int& operator*()
        {
            return *ptr_;
        }
        
        int* operator->()
        {
            return ptr_;
        }
        
        void swap(smart_pointer &p1)
        {
            std::swap(ptr_, p1.ptr_);
        }
        

    private:
        int* ptr_;
        
        void copy(const smart_pointer& p)
        {
            //simple if/else logic, ex: string finalgrade = (grade < 60) ? "fail" : "pass";
            ptr_ = (p.ptr_ != nullptr) ? new int{ *p.ptr_ } : nullptr;
        }
        
        void clear()
        {
            delete ptr_;
            ptr_ = nullptr;
        }

    };

}















