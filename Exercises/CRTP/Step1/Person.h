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
    
    // Derive a class template class named Person_Cloneable from Person, having one template type parameter named Derived.
    template<typename Derived>
    class Person_Cloneable : public Person
    {
    public:
        Person_Cloneable(const std::string &name, const IDA_Person::CRN &crn) : Person( name, crn ) {}
        
        // Override clone() to dynamically create a Derived object, initialize it with a copy of *this, and return a pointer to the new object as Person*.
        Person *clone() const override
        {
            return new Derived(static_cast<const Derived&>(*this));
        }
        
    protected:
        Person_Cloneable(const Person_Cloneable&) = default;
        
    private:
        Person_Cloneable &operator=(const Person_Cloneable&) = delete;
        
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

} // namespace IDA_Person

#endif
