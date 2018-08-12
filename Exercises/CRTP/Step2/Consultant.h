/*
 * Consultant.h
 */
#ifndef CONSULTANT_H
#define CONSULTANT_H
#include "Employee.h"
#include <string>

namespace IDA_Person
{
   class Consultant final : public Employee
   {
   public:
      using Employee::Employee;  // inheriting constructors
 
      ~Consultant() = default;

      Consultant* clone() const override { return new Consultant{ *this }; }

      std::string str() const override;

       Consultant(const Consultant&) = default; //should be in protected
   protected:
      

   private:
      Consultant& operator=(const Consultant&) = delete;
   };

} // namespace IDA_Person

#endif
