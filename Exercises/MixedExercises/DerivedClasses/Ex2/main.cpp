// EXERCISE 2 - DERIVED CLASSES

#include <iostream>

using namespace std;

struct callback
{
    virtual ~callback() noexcept = default;
    virtual void operator()() const = 0;
};

template<void (*ptr_func)()> //*pointer to function
struct callback_function : public callback
{
    virtual void operator()() const
    {
        ptr_func();
    }
};

template<typename T, void (T::*ptr_mem_func)()>
class callback_member_function : public callback
{
public:
    explicit callback_member_function( T &object ) : obj_ref( &object ) {}
    virtual void operator()() const
    {
        ( obj_ref->*ptr_mem_func )();
    }
private:
    T *obj_ref;
};


void hello()
{
    cout << "Hello World!\n" << endl;
}

struct S
{
    void hello()
    {
        cout << "Heya!" << endl;
    }
};

void greet(callback const& call_back)
{
    call_back();
}

int main() {
    
    greet( callback_function<hello>() );
    S s;
    greet( callback_member_function<S, &S::hello>(s) );
    
    return 0;
}
