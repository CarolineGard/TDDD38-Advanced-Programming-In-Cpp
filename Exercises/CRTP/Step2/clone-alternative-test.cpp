/* STEP 2
 Manager is now to be derived from Employee. In the lecture example this is straight forward:
 class Manager : public Employee { ... };
 
 We now discover that our experiment with CRTP in Step 1 works only for one-level inheritance:
 class Manager : public Person_Cloneable< What? > { ... };
 
 What? should be Employee, but CRTP require Manager. To get around this, let Person_Cloneable have
 two template type parameters, one for the direct base class, one for the class to be derived.
 
 1. Redefine Person_Cloneable to have two template type parameter, named Base and Derived.
 2. Modify Manager given in the lecture example, to derive from Person_Cloneable<Employee, Manager>
    instead of Employee.
 
    If we compile at this stage, we will run into problems with constructors. All subclasses will derive
    from Person_Cloneable, but Person_Cloneable will derive from different base classes, with different
    constructors. In the Employee case Person_Cloneable will derive from Person, in the Manager case from
    Employee and these have different constructors, especially the public ones.
 
 3. Fortunately constructors can be inherited in C++11, so remove the explicitly declared public constructor
    in Person_Cloneable, and instead declare Person_Cloneable to inherit constructors from its direct base class.
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
    vector<Employee*> employees {
        new Employee{ "Art Artsson", CRN{ 1953, 4, 1, 1016 }, Date{ 2003, 1, 1}, 1, 42000.00, 2 },
        new Employee{ "Gustav Gustavsson", CRN{ 1992, 7, 13, 1012 }, Date{ 2001, 1, 1}, 1, 36000.00, 2 },
        new Employee{ "Anna Andersson", CRN{ 1983, 7, 14, 1011 }, Date{ 2005, 1, 1}, 1, 39000.00, 2 },
        new Manager { "Per Persson", CRN{ 1948, 3, 14, 1011 }, Date{ 1996, 1, 1}, 1, 55000.00, 2 },
        new Employee{ "Johanna Johansson", CRN{ 1976, 1, 11, 1011 }, Date{ 2002, 1, 1}, 1, 41000.00, 2 }
    };
    
    Manager *pm2 = new Manager { "Perra", CRN{ 1948, 3, 14, 1011 }, Date{ 1996, 1, 1}, 1, 55000.00, 2 };
    
    for (auto e : employees)
    {
        if ( dynamic_cast<Manager*>(e) != nullptr )
            pm2 = dynamic_cast<Manager*>(e);
        
        else
            pm2->add_department_member(e); //error, only adds one in total....
    }
    
    for (auto e : employees)
    {
        pm2 = dynamic_cast<Manager*>(e);
        
        if (pm2 != nullptr)
        {
            cout << "\nPrint department list: " << endl;
            pm2->print_department_list(cout);
            cout << endl;
        }
    }
    
    for (auto e : employees)
    {
        pm2 = dynamic_cast<Manager*>(e);
        
        if (pm2 != nullptr)
            pm2->raise_salary(10.0);
    }
    
    for (auto e : employees)
    {
        pm2 = dynamic_cast<Manager*>(e);
        
        if (pm2 != nullptr)
            pm2->print_department_list(cout);
    }
    
   return 0;
}







