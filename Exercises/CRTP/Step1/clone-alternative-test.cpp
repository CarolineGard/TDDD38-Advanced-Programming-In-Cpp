/*
 * clone-alternative-test.cc
 */
#include "CRN.h"
#include "Date.h"
#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include "Consultant.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;
using namespace IDA_Person;
using namespace IDA_Date;

int main()
{
    
    Person *p{nullptr};
    
    Employee *pe{ new Employee{ "Beth Saida", CRN{ 1952, 2, 1, 1021}, Date{ 2007, 1, 2}, 2, 12000.00 } };
    Employee *pe2{ new Employee{ "Caroline Gard", CRN{ 1999, 2, 6, 1024}, Date{ 2008, 1, 1}, 4, 13000.00 } };
    p = new Employee{ *pe2 };
    
    cout << "p: " << *p << endl;
    cout << *pe << endl;
    cout << *pe2 << endl;
    
    Person *pm{ new Manager{"Art Iculate", CRN{ 1950, 1, 1, 1011 }, Date{ 2007, 1, 1}, 1, 41000.00, 2 } };
    cout << *pm << endl;
    
    Person *pc { new Consultant{"Magnus Karlsson", CRN{ 1965, 12, 24, 1000 }, Date{ 2018, 6, 5 }, 1, 40000.00, 2} };
    cout << *pc << endl;
    
    Person *p2{ nullptr };
    
    if ( typeid(*pm) == typeid(Employee) )
    {
        p2 = new Employee{ *dynamic_cast<Employee*>(pm) };
    }
    
    else if ( typeid(*pm) == typeid(Manager) )
    {
        p2 = new Manager{ *dynamic_cast<Manager*>(pm) };
    }
    
    else if (typeid(*pm) == typeid(Consultant))
    {
        p2 = new Consultant{ *dynamic_cast<Consultant*>(pm) };
    }
    
    cout << "p2: " << *p2 << endl;
    
    // Clone Employee
    Person *p3{ p->clone() };
    cout << "p3: " << *p3 << endl;
    delete p3;
    p3 = nullptr;

   return 0;
}
