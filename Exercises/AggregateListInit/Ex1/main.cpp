

#include <iostream>
#include <initializer_list>

using namespace std;

//to pass array dimensions to functions
template<typename T, int N>

//a is reference to array with type int[N]
void print_array( T (&a)[N] )
{
    for ( auto x : a )
        cout << x << " ";
    
    cout << "\n\n";
}

void print_pointer_to_array(int *pp, int s)
{
    for (auto it = pp; it != pp + s; it++)
        cout << *it << " ";
    cout << "\n\n";
}

void function_1( initializer_list<int> list ) //3
{
    for (auto x: list)
        cout << x << " ";
    cout << "\n\n";
}

initializer_list<int> function_2() //4
{
    return { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 };
}

struct S {
    int s1[5]{ 1, 2, 3, 4, 5 }; //5
    
    S() : s2{ 7, 8, 9 } {} //6
    int s2[3];
    
    S(const initializer_list<int> &list) //8
    {
        for (auto x : list)
            cout << x << " ";
        cout << "\n";
    }
};

int main()
{

    //1) as the initializer in a variable definition
    cout << "1. initializer in a variable definition" << endl;
    int a[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    print_array(a);
    
    //2) as the initializer in a new expression
    cout << "2. initializer in a new expression" << endl;
    int *p = new int[10]{ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    print_pointer_to_array(p, 10);
    
    //3) as a function argument
    cout << "3. function argument (initializer list)" << endl; //not for array
    function_1( { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 } );
    
    //4) in a return statement
    cout << "4. return statement (initializer list)" << endl; //not for array
    initializer_list<int> a2 = function_2();
    function_1(a2);
    
    //5) as an initializer for a non-static data member
    cout << "5. initializer for a non-static data member" << endl;
    S ss1;
    print_array(ss1.s1);
    
    //6) in a member initializer
    cout << "6. member initializer" << endl;
    S ss2;
    print_array(ss2.s2);
    
    //7) on the right-hand side of an assignment
    cout << "7. the right-hand side of an assignment" << endl;
    cout << "not if left-hand is array\n" << endl;
    
    //8) as an argument to a constructor invocation
    cout << "8. argument to a constructor invocation (initializer list)" << endl;
    S( { 3, 5, 2, 2 } );
    
    return 0;
}
