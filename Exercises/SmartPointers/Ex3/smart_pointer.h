
/*
 EX 2.
 
 Implement operators:
 ==, !=, !, 
 
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
        
        //Declaring friendly functions
        friend bool operator==(const smart_pointer &p_left, const smart_pointer &p_right);
        friend bool operator==(const smart_pointer &p_left, const int *value);
        friend bool operator==(const int *value, const smart_pointer &p_right);
        friend bool operator!=(const smart_pointer &p_left, const smart_pointer &p_right);
        friend bool operator!=(const smart_pointer &p_left, const int *value);
        friend bool operator!=(const int *value, const smart_pointer &p_right);
        friend bool operator!(const smart_pointer &p_right);
        
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
    
    void swap(smart_pointer &p1, smart_pointer &p2 );
    
    bool operator==(const smart_pointer &p_left, const smart_pointer &p_right);
    bool operator==(const smart_pointer &p_left, const int *value);
    bool operator==(const int *value, const smart_pointer &p_right);
    bool operator!=(const smart_pointer &p_left, const smart_pointer &p_right);
    bool operator!=(const smart_pointer &p_left, const int *value);
    bool operator!=(const int *value, const smart_pointer &p_right);
    bool operator!(const smart_pointer &p_right);
}

















