// EXERCISE - POLICY BASED DESIGN FOR SMART POINTERS (SP)
// A very simple smart pointer type implementing deep copy.

// Ex 1 - Conversion policy is added
// A conversion policy is about whether conversion to the raw pointer type is to be allowed or not

/*
 *   Template select_type is added and used for selecting one of two types at
 *   compile-time.
 *
 *   Conversion policy classes allow_conversion and disallow_conversion.
 *
 *   Template parameter conversion_policy, with disallow_conversion as default
 *   argument.
 *
 *   Private helper class disallow, to which the raw pointer ptr_ cannot be
 *   converted and therefore disallowing implicit type conversion when used
 *   as return type for the type conversion operator, se below.
 *
 *   Type conversion operator, converting to either T* or disallow depending
 *   on conversion_policy and selected by using select_type.
 */

#ifndef SMART_POINTER_H
#define SMART_POINTER_H

// Type selection
// selects one of two types based upon a boolean constant
// if true, T1 is selected. false: T2 is selected

template<bool flag, typename T1, typename T2>
struct select_type
{
    typedef T1 result;
};

template<typename T1, typename T2>
struct select_type<false, T1, T2>
{
    typedef T2 result;
};

// Conversion policy
// Allow conversion to the pointer type

struct allow_conversion
{
    static const bool allow = true;
};

struct disallow_conversion
{
    static const bool allow = false;
};

// Smart pointer

template<typename T, class conversion_policy = disallow_conversion>
class smart_pointer
{
public:
     smart_pointer() = default;

     explicit smart_pointer(T* p) : ptr_{ p } {}

     smart_pointer(const smart_pointer& rhs) : ptr_{ copy(rhs) } {}

     ~smart_pointer()
     {
        delete ptr_;
     }
   
     smart_pointer& operator=(const smart_pointer &rhs) &
     {
         if (this != &rhs)
         {
             T* ptr{ copy(rhs) };
             delete ptr_;
             ptr_ = ptr;
         }
         return *this;
     }
   
    T& operator*() const
    {
        return *ptr_;
    }
    
    T& operator*()
    {
         return *ptr_;
    }
      
    T* operator->() const
    {
         return ptr_;
    }
    
    T* operator->()
    {
         return ptr_;
    }

private:
    // Helper class for disallowing implicit type conversions
    class disallowed {};
    
    // If implicit type conversion is allowed, 'implicit_conversion_type' will be defined as 'pointer_type'
    // If implicit type conversion is not allowed, 'disallowed'
    using implicit_conversion_type = typename select_type<conversion_policy::allow, T*, disallowed>::result;
    
public:
    operator implicit_conversion_type() const
    {
        return ptr_;
    }
    
private:
    T* ptr_{ nullptr };

    T* copy(const smart_pointer &sp)
    {
        return sp.ptr_ ? new T{ *sp.ptr_ } : nullptr;
    }
};

#endif
