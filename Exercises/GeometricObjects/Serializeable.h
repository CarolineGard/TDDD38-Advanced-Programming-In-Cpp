
#ifndef Serializeable_h
#define Serializeable_h

#include <string>

using namespace std;

// Returns string in serializeable version

// Interface class
class Serializeable
{
public:
    ~Serializeable() = default;
    std::string str() const
    {
        return to_string();
    }
    
private:
    virtual std::string to_string() const = 0;
    
};


#endif /* Serializeable_h */
