/*
 * Consultant.h
 */
#ifndef CONSULTANT_H
#define CONSULTANT_H
#include "Employee.h"
#include "Date.h"
#include "CRN.h"
#include <string>

namespace IDA_Person
{
   using IDA_Date::Date;
    
   class Consultant final : public Person_Cloneable<Employee, Consultant>
   {
   public:
        Consultant( const std::string &name,
                    const CRN &crn,
                    const Date &date,
                    int e_number,
                    double salary,
                    int dept)
       : Person_Cloneable{ name, crn, date, e_number, salary, dept } {}
      //using Employee::Employee;  // inheriting constructors
 
       
      ~Consultant() = default;


      // Consultant(const Consultant&) = default; //should be in protected
   

   private:
       std::string str() const override;
      //Consultant& operator=(const Consultant&) = delete;
   };

} // namespace IDA_Person

#endif
