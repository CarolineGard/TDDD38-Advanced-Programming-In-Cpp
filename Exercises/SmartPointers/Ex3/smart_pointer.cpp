
#include "smart_pointer.h"

namespace Smart_Pointer
{
    
    void swap(smart_pointer &p1, smart_pointer &p2)
    {
        p1.swap(p2);
    }
    
    bool operator==(const smart_pointer &p_left, const smart_pointer &p_right)
    {
        return (p_left.ptr_ == p_right.ptr_);
    }
    
    bool operator==(const smart_pointer &p_left, const int *value)
    {
        return (p_left.ptr_ == value);
    }
    
    bool operator==(const int *value, const smart_pointer &p_right)
    {
        return (value == p_right.ptr_);
    }
    
    bool operator!=(const smart_pointer &p_left, const smart_pointer &p_right)
    {
        return (p_left.ptr_ != p_right.ptr_);
    }
    
    bool operator!=(const smart_pointer &p_left, const int *value)
    {
        return (p_left.ptr_ != value);
    }
    
    bool operator!=(const int *value, const smart_pointer &p_right)
    {
        return (value != p_right.ptr_);
    }
    
    bool operator!(const smart_pointer &p_right)
    {
        return (p_right.ptr_ == nullptr);
    }
    
    
}
