/* STEP 3
 Modify Consultant.
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
        new Consultant{ "Peter petersson", CRN{ 1923, 3, 14, 1013 }, Date{ 2002, 1, 2}, 1, 33000.00, 2 },
        new Employee{ "Anna Andersson", CRN{ 1983, 7, 14, 1011 }, Date{ 2005, 1, 1}, 1, 39000.00, 2 },
        new Manager { "Per Persson", CRN{ 1948, 3, 14, 1011 }, Date{ 1996, 1, 1}, 1, 55000.00, 2 },
        new Employee{ "Johanna Johansson", CRN{ 1976, 1, 11, 1011 }, Date{ 2002, 1, 1}, 1, 41000.00, 2 },
        new Consultant{ "Petter pettersson", CRN{ 1923, 3, 14, 1013 }, Date{ 2002, 1, 2}, 1, 33000.00, 2 }
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
    
    Consultant *pc{ nullptr };
    for ( auto e : employees)
    {
        if (dynamic_cast<Consultant*>(e) != nullptr)
            pc = dynamic_cast<Consultant*>(e);
    }
    
    for (auto e : employees)
    {
        pm2 = dynamic_cast<Manager*>(e);
        
        if (pm2 != nullptr)
            pm2->print_department_list(cout);
    }
    
   return 0;
}



