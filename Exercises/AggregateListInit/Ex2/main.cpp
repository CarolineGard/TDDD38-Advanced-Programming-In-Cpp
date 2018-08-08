
#include <iostream>

using namespace std;

struct Person {
    string name;
    unsigned int age;
    float length; //m
};

struct S {
    Person s1{ "Pelle", 19, 1.93 }; //5
    
    S() : s2{ "Hanna", 34, 1.72 } {} //6
    Person s2;
    
    S(const Person &p) : s3(p) {} //8
    Person s3;
};

void print( Person p )
{
    cout << "\n" << p.name << ", " << p.age << " years old, " << p.length << " meters" << endl;
}

void function_1( Person p )
{
    cout << "\n" << p.name << ", " << p.age << " years old, " << p.length << " meters" << endl;
}

Person function_2()
{
    return Person{ "Anna", 46, 1.59 };
}

int main()
{
    //1) as the initializer in a variable definition
    cout << "initializer in a variable definition" << endl;
    Person p1{ "Caroline", 26, 1.67 };
    print(p1);
    
    //2) as the initializer in a new expression
    cout << "initializer in a new expression" << endl;
    Person *p2 = new Person{ "Caroline", 26, 1.67 };
    print(*p2);
    
    //3) as a function argument
    cout << "function argument" << endl;
    function_1( { "Kalle", 12, 1.33 } );
    
    //4) in a return statement
    cout << "return statement" << endl;
    Person p3 = function_2();
    print(p3);
    
    //5) as an initializer for a non-static data member
    cout << "initializer for a non-static data member" << endl;
    S ss1;
    print(ss1.s1);
    
    //6) in a member initializer
    cout << "member initializer" << endl;
    S ss2;
    print(ss2.s2);
    
    //7) on the right-hand side of an assignment
    cout << "the right-hand side of an assignment" << endl;
    p1 = { "Ingvar", 78, 1.71 };
    print(p1);
    
    //8) as an argument to a constructor invocation
    cout << "argument to a constructor invocation" << endl;
    S ss3( { "Kristin", 27, 1.66 } );
    print(ss3.s3);
    
    return 0;
}
