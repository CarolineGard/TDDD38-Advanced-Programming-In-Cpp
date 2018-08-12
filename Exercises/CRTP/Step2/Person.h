/*
 * Person.h
 */
#ifndef PERSON_H
#define PERSON_H
#include "CRN.h"
#include <iosfwd>
#include <string>

namespace IDA_Person
{
   class Person
   {
   public:
      virtual ~Person() = default;

      virtual Person* clone() const = 0;

      virtual std::string str() const { return name_ + ' ' + crn_.str(); }

      std::string get_name() const { return name_; }
      void        set_name(const std::string& name) { name_ = name; }

      CRN         get_crn() const { return crn_; }
      void        set_crn(const CRN& crn) { crn_ = crn; }

   protected:
       Person(const std::string& name, const IDA_Person::CRN& crn)
       : name_{ name }, crn_{ crn }
      {}
 
      Person(const Person&) = default;

   private:
      Person& operator=(const Person&) = delete;

       std::string name_;
       IDA_Person::CRN crn_;
   };

   std::ostream& operator<<(std::ostream&, const Person&);
    
    // Redefine Person_Cloneable to have two template type parameter, named Base and Derived.
    template<typename Base, typename Derived> //example <Employee, Manager> or <Person, Employee>
    class Person_Cloneable : public Base
    {
    public:
        using Base::Base; // inheriting constructors
        
        // Fortunately constructors can be inherited in C++11,
        // so remove the explicitly declared public constructor in Person_Cloneable, and
        // instead declare Person_Cloneable to inherit constructors from its direct base class.
        Base *clone() const override
        {
            return new Derived( static_cast<const Derived&>(*this) );
        }
        
        Person_Cloneable(const std::string &name, const IDA_Person::CRN &crn) : Person( name, crn ) {}
        
        // (Step 1) Override clone() to dynamically create a Derived object, initialize it with a copy of *this, and return a pointer to the new object as Person*. changed to Base
        /*
        Person *clone() const override
        {
            return new Derived(static_cast<const Derived&>(*this));
        }
        */
    protected:
        Person_Cloneable(const Person_Cloneable&) = default;
        
    private:
        Person_Cloneable &operator=(const Person_Cloneable&) = delete;
        
    };

} // namespace IDA_Person

#endif
